#include"User.h"
namespace Parse
{
	//common implement for User type
	IMPLEMENT_CLASS(User)
	//自定义方法，将一个字符串识别为User数据，存入到vector<User>中
	bool Parser_User::addData(const std::string &str)
	{
		return false;
	}
	
}