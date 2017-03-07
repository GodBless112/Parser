#include<cstdio>
#include<sstream>
#include"Parser.h"
#include"User.h"

typedef struct ss
{
	int a;
	double b;
}s;
#define getByName(name)\
name get(const std::string & str){\
return name(new name);}
getByName(int)
int main()
{
	auto x = int;
	int a = get("int");
	Parse::a;
	std::vector<std::string> TypeConfig = Parse::getConfig();
	std::cout << typeid(int).name() << std::endl;

	//Code to keep window open
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}