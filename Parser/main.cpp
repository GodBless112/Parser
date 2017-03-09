#include<cstdio>
#include<sstream>
#include"User.h"
#include"Parser.h"

int main()
{
	Parse::Init();
	std::ifstream fin_data;
	fin_data.open("data.txt");
	if (fin_data.is_open() == false)
	{
		std::cerr << "Can't open file. Bye." << std::endl;
		std::cout << "error 0" << std::endl;
		exit(EXIT_FAILURE);
	}
	int lineNum = 0;
	std::string line;
	std::vector<std::string> v_str;
	getline(fin_data, line);
	while (fin_data)
	{
		v_str = Parse::split(line, "\t");
		Parse::read_line(v_str, lineNum);
		getline(fin_data, line);
	}
	Parse::v_pParseObject[0]->output();
	Parse::v_pParseObject[1]->output();
	Parse::Parser_int a;
	Parse::Uninit();
	
	//Code to keep window open
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}