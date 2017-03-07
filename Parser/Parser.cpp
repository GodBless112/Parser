#include "Parser.h"

std::vector<std::string> Parse::split(std::string str, std::string pattern)
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

std::vector<std::string> Parse::getConfig()
{
	std::vector<std::string> config;
	std::string TypeInfo;
	std::ifstream fin_config("config.txt");
	if (!fin_config.is_open())
	{
		std::cerr << "File open error!\n";
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
