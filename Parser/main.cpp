#include<cstdio>
#include<sstream>
#include"User.h"
#include"Parser.h"


typedef struct ss
{
	int a;
	double b;
}s;
using Userdata1 = ss;
#define User#x ss;
int main()
{
	//Parse::a;
	std::vector<std::string> TypeConfig = Parse::getConfig();
	std::cout << typeid(int).name() << std::endl;

	//Code to keep window open
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}