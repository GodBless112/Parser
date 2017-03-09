#include"User.h"
namespace Parse
{
	//common implement for User type
	IMPLEMENT_CLASS(User)
	//自定义方法，将一个字符串识别为User数据，存入到vector<User>中
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