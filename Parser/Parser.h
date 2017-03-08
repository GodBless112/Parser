#pragma once
#ifndef PARSER_H
#define PARSER_H
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<set>

namespace Parse
{
//some basic fuction
	std::vector<std::string> split(std::string str, std::string pattern);	//string split function
	std::vector<std::string> getConfig();	//code to get type information from a file
//some vaule
	extern std::vector<std::string> TypeStr;// = { "int","double","float","long" };
	extern std::set<std::string> Type_Set;// (TypeStr.begin(), TypeStr.end());
}
#endif // !PARSER_H
