#pragma once
#ifndef PARSER_H
#define PARSER_H
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<map>

namespace Parse
{
//some basic fuction
	std::vector<std::string> split(std::string str, std::string pattern);	//string split function
	std::vector<std::string> getConfig();	//code to get type information from a file
}
#endif // !PARSER_H
