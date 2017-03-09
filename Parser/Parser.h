#pragma once
#ifndef PARSER_H
#define PARSER_H
#include<string>
#include<sstream>
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<set>

namespace Parse
{
	//...... .reflection definition...............
#define DECLARE_CLASS(name) \
	protected:\
		static Parse::ClassInfo ms_classinfo;\
	public:\
		virtual Parse::ClassInfo *GetClassInfo() const;\
		static Parse::ParserObject *CreateObject();

#define IMPLEMENT_CLASS_COMMON(name, func) \
	Parse::ClassInfo name::ms_classinfo((#name), \
		(Parse::ObjectConstructorFn) func);\
	Parse::ClassInfo *name::GetClassInfo() const \
	{return &name::ms_classinfo;}

#define IMPLEMENT_CLASS(name) \
	IMPLEMENT_CLASS_COMMON(Parser_##name, Parser_##name::CreateObject) \
	Parse::ParserObject *Parser_##name::CreateObject() { return new Parser_##name; }\
	Parse::TypeString Parser_##name::namestr(#name);

#define IMPLEMENT_CLASS_OTHER(name) \
	bool Parser_##name::addData(const std::string & str){\
		if (str.empty()){\
			ParseData.push_back(name());\
			return false;}\
		std::stringstream ss;\
		name result;\
		ss << str;\
		ss >> result;\
		ParseData.push_back(result);\
		return true;}
	
//macro definition for reflection
#define REFLECT(name) \
	class Parser_##name: public Parse::ParserObject \
	{\
		DECLARE_CLASS(Parser_##name)\
		public:\
			Parser_##name(){};\
			~Parser_##name(){};\
			bool addData(const std::string &str);\
			void output() const{\
				for (int i = 0; i<ParseData.size(); i++)\
					std::cout << ParseData[i] << std::endl;}\
		public:\
			std::vector<name> ParseData;\
		private:\
			static Parse::TypeString namestr;\
	};
	

//some basic fuction
	std::vector<std::string> split(std::string str, std::string pattern);	//string split function
	std::vector<std::string> getConfig();	//code to get type information from a file
	void read_line(const std::vector<std::string> &v_str, int& lineNum);
	bool Init();		//��ʼ������ָ���������͵�ָ��
	bool Uninit();		//ɾ��ָ��

//...............basic class.....................
	class ClassInfo;		//��������������
	class ParserObject;		//�ָ����û����࣬��Ϊ�������
	static std::map<std::string, ClassInfo*> *classInfoMap = NULL;	//map,�������������Ϣָ��
	typedef ParserObject* (*ObjectConstructorFn)(void);		//����ָ��
//some vaule
	//extern std::set<std::string> s_TypeStr;			//����Ѿ����ɵ����ʹ�����
	extern std::vector<std::string> v_TypeConfig;		//��������Ҫ�ָ������
	extern std::vector<ParserObject*> v_pParseObject;	//�����Ҫ�ָ�����Ͷ�Ӧ��ָ��
	
	bool Register(ClassInfo *ci);			//ע�������Ϣ

	class TypeString
	{
	public:
		TypeString(const std::string &str) { s_TypeStr.insert(str); }
		static std::set<std::string> s_TypeStr;
	};

	class ClassInfo
	{
	public:
		ClassInfo(const std::string &className, ObjectConstructorFn ctor)
			:m_className(className), m_objectConstruction(ctor)
		{
			Register(this);
		}
		virtual ~ClassInfo() {};
		ParserObject *CreateObject() const { return m_objectConstruction ? (*m_objectConstruction)() : nullptr; }
		bool IsDynamic() const { return nullptr != m_objectConstruction; }
		const std::string GetClassName() const { return m_className; }
		ObjectConstructorFn GetConstructor() const { return m_objectConstruction; }
	public:
		std::string m_className;		//����
		ObjectConstructorFn m_objectConstruction;	//����ָ��
	};
	class ParserObject
	{
		DECLARE_CLASS(ParserObject)
	public:
		ParserObject() {};
		virtual ~ParserObject() {};
		virtual bool addData(const std::string &str) { return true; };
		virtual void output() const {};
		static bool Register(ClassInfo *ci);
		static ParserObject* CreateObject(const std::string &className);
	};

//����ָ���
	REFLECT(int)
	REFLECT(float)
	REFLECT(double)
}
#endif // !PARSER_H
