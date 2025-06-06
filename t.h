#pragma once
#include <iostream>

const int32_t tNum = 100;
class tStr
{
public:
	tStr(int32_t ibase,int32_t imov,int32_t iexp);
	~tStr();

	void print();
public:
	void doMultiStrAndInt2Str();
	
private:
	char sDest[tNum];
	char sTmp[tNum];
	
	char sBase[tNum];
	int32_t t_ibase;
	int32_t t_iexp;
	//
	int32_t t_imov;

	int32_t ibase_weishu;

};



