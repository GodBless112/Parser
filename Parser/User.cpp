#include"User.h"
namespace Parse
{
	//common implement for User type
	IMPLEMENT_CLASS(User)
	//�Զ��巽������һ���ַ���ʶ��ΪUser���ݣ����뵽vector<User>��
	bool Parser_User::addData(const std::string &str)
	{
		if (str.empty())
		{
			ParseData.push_back(User());
			return false;
		}
		std::vector<std::string> v_str = split(str, "|");
		std::stringstream ss;
		User myData;
		ss << v_str[0];
		ss >> myData.a;
		ss.clear();
		ss << v_str[1];
		ss >> myData.b;
		ParseData.push_back(myData);
		return true;
	}
	
}