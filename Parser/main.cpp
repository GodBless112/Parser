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
	int lineNum = 0;	//��¼��ȡ�˶�����
	std::string line;
	std::vector<std::string> v_str;
	getline(fin_data, line);
	while (fin_data)
	{
		v_str = Parse::split(line, "\t");
		Parse::read_line(v_str, lineNum);
		getline(fin_data, line);
	}
	//�������Ԫ��
	for (int i = 0; i < Parse::v_pParseObject.size(); i++)
		Parse::v_pParseObject[i]->output();
	//�������Ԫ�ط�ʽ
	for (int i = 0; i < lineNum; i++)
	{
		for (int j = 0; j < Parse::v_pParseObject.size(); j++)
		{
			Parse::v_pParseObject[j]->output(i);
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
	//��ȡ������ݵ�vector
	std::vector<int> result_int = dynamic_cast<Parse::Parser_int&>(*Parse::v_pParseObject[0]).ParseData;
	//��ȡ��ŵ�����
	std::cout<<Parse::v_pParseObject[0]->GetClassInfo()->GetClassName();
	
	//�������ɵĸ�ָ��
	Parse::Uninit();
	
	//Code to keep window open
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}