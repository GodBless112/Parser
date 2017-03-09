#pragma once
#ifndef USER_H
#define USER_H
#include"Parser.h"
namespace Parse
{
	struct User
	{
		int a;
		double b;
	public:
		friend std::ostream & operator<<(std::ostream &os, const User &us)
		{
			os << us.a << "\t" << us.b;
			return os;
		}
	};

	//�����û����ͣ�����
	REFLECT(User)
}
#endif // !USER_H
