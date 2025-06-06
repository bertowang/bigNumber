#include <iostream>
#include <string>
#include "t.h"

using namespace std;

int32_t changeFloat2Int(string sFloat, int32_t &base, int32_t &exp)
{
	
	return 0;
}


int main(int argc, char** argv)
{
	std::cout << "usage: base(int) exp(int)" << std::endl;	
	
	//change to int
	int32_t g_ibase = 95123;
	int32_t g_imov=1000;
	int32_t g_iexp = 12;
	if (argc == 1)
	{
		std::cout << "default : base =" << g_ibase << std::endl;
		std::cout << "default : exp =" << g_iexp << std::endl;
	}
	else if (argc == 3)
	{
		std::cout << "default : base =" << argv[1] << std::endl;
		std::cout << "default : exp =" << argv[2] << std::endl;

		//changeFloat2Int(argv[1], g_ibase, g_imov);
		g_ibase = atoi(argv[1]);
		g_iexp = atoi(argv[2]);
	}
	else
	{
		std::cout << "error input" << std::endl;
		exit(1);
	}

	
	tStr tBigNum(g_ibase, g_imov, g_iexp);
	//tBigNum.print();
	tBigNum.doMultiStrAndInt2Str();
	tBigNum.print();
	return 0;

}


