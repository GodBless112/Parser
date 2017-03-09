#include "Parser.h"
namespace Parse
{
	std::vector<std::string> v_TypeConfig = getConfig();
	std::vector<ParserObject*> v_pParseObject;
	std::set<std::string> TypeString::s_TypeStr;
	//分割字符串
	std::vector<std::string> split(std::string str, std::string pattern)
	{
		std::vector<std::string> ret;
		if (pattern.empty())
			return ret;
		size_t start = 0, index = str.find_first_of(pattern, 0);
		while (index != str.npos)
		{
			if (start != index)
				ret.push_back(str.substr(start, index - start));
			start = index + 1;
			index = str.find_first_of(pattern, start);
		}
		if (!str.substr(start).empty())
			ret.push_back(str.substr(start));
		return ret;
	}
	//获取配置信息
	std::vector<std::string> getConfig()
	{
		std::vector<std::string> config;
		std::string TypeInfo;
		std::ifstream fin_config("config.txt");
		if (!fin_config.is_open())
		{
			std::cerr << "Error 0: File open error!\n";
			exit(EXIT_FAILURE);
		}
		std::getline(fin_config, TypeInfo);
		while (fin_config)
		{
			config.push_back(TypeInfo);
			std::getline(fin_config, TypeInfo);
		}
		return config;
	}
	//识别一行数据
	void read_line(const std::vector<std::string> &v_str, int& lineNum)
	{
		lineNum++;
		if (v_str.size() == v_TypeConfig.size())
		{
			for (int i = 0; i < v_TypeConfig.size(); i++)
			{
				if (!v_pParseObject[i]->addData(v_str[i]))
					std::cout << "error 2: empty string\n";
			}
		}
		else
			std::cout << "error 3: row " << lineNum << " lack data" << std::endl;
	}
	//初始化
	bool Init()
	{
		for (int i = 0; i < v_TypeConfig.size(); i++)
		{
			if (TypeString::s_TypeStr.find(v_TypeConfig[i]) != TypeString::s_TypeStr.end())
				v_pParseObject.push_back(ParserObject::CreateObject(v_TypeConfig[i]));
			else
			{
				std::cout << "Error :The class for " << v_TypeConfig[i] << " are not defined!\n";
				return false;
			}
		}
		return true;
	}
	//退出
	bool Uninit()
	{
		for (int i = 0; i < v_pParseObject.size(); i++)
			delete v_pParseObject[i];
		return true;
	}
	//注册函数信息类
	bool Parse::Register(ClassInfo * ci)
	{
		return ParserObject::Register(ci);
	}

	//基础类ParseObject的类方法
	Parse::ClassInfo ParserObject::ms_classinfo(("ParseObject"), (Parse::ObjectConstructorFn) ParserObject::CreateObject);
	Parse::ClassInfo *ParserObject::GetClassInfo() const
	{
		return &ms_classinfo; 
	}
	Parse::ParserObject *ParserObject::CreateObject() 
	{
		return new ParserObject; 
	}
	bool ParserObject::Register(ClassInfo * ci)
	{
		if (!classInfoMap)
			classInfoMap = new std::map<std::string, ClassInfo*>();
		
		if (ci)
			if (classInfoMap->find(ci->m_className) == classInfoMap->end())
				(*classInfoMap)[ci->m_className] = ci;
		return true;
	}
	ParserObject * ParserObject::CreateObject(const std::string & className)
	{
		std::map<std::string, ClassInfo*>::iterator itr = classInfoMap->find("Parser_" + className);
		if (classInfoMap->end() != itr)
			return itr->second->CreateObject();
		return nullptr;
	}


//......定义各种类型的分割类的类方法..........
	//int型
	IMPLEMENT_CLASS(int)
	IMPLEMENT_CLASS_OTHER(int)
	
	//float型
	IMPLEMENT_CLASS(float)
	IMPLEMENT_CLASS_OTHER(float)

	//float型
	IMPLEMENT_CLASS(double)
	IMPLEMENT_CLASS_OTHER(double)
	
}