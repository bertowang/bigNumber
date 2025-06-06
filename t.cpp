#include "tStr.h"


#include <string>
using namespace std;

tStr::tStr(int32_t ibase, int32_t imov, int32_t iexp)
{
	t_ibase = ibase;
	t_imov = imov;
	t_iexp = iexp;

	for (int32_t i = 0; i < tNum; i++)
	{
		sDest[i] = '0';
		sTmp[i] = '0';
		sBase[i] = '0';
	}	
	
	int32_t itmp = t_ibase;
	int32_t ibIndex = 0;
	while (itmp)
	{		
		sBase[ibIndex] = itmp % 10 + '0';		
		sDest[ibIndex] = itmp % 10 + '0';
		itmp = itmp/10;		
		ibIndex++;
	}
	ibase_weishu = ibIndex++;
	cout <<"ibase_weishu="<<ibase_weishu << endl;
}


tStr::~tStr()
{
}


void tStr::print()
{	
	int32_t i_re = tNum - 1;
	while (sDest[i_re] == '0')
	{
		i_re--;
	}

	printf("sDest:");
	for (int32_t j3 = i_re; j3 >= 0; j3--)
	{
		printf("%c", sDest[j3]);
	}
	printf("\r\n");

#if 0
	//	
	printf("sTmp\r\n");
	for (int32_t i = tNum - 1; i >= 0; i--)	
		printf("%c", sTmp[i]);
	
	printf("\r\n");
	//	
	printf("sBase\r\n");
	for (int32_t i = tNum - 1; i >= 0; i--)	
		printf("%c", sBase[i]);

	printf("\r\n");
#endif
}



void tStr::doMultiStrAndInt2Str()
{	
	cout << "-----------"<< endl;
	for (int32_t i =0; i < t_iexp;i++)
	{	
		
		{
			int32_t mi = tNum-1;
			while (mi >=0 )
			{
				sDest[mi] = sBase[mi];									
				sBase[mi] = '0';
				mi--;				
			}

			
		}
#if 1

		int32_t i_re = tNum - 1;
		while (sDest[i_re] == '0')
		{			
			i_re--;			
		}		

		i_re = i_re + 1;
		
		cout << "exp->" << i  + 1 << ":i_len -> "<<i_re  << endl;
		print();

		for (int32_t index = 0; index < i_re; index++)
		{
			int32_t itmpMult = t_ibase * (sDest[index] - '0') ;
			//cout << "index:" << index << "->" << itmpMult << endl;
			//one_multipul result -> char[i] + sBase				

			/*
					56789
			1234567897899

			*/

			{
				int32_t itmp = itmpMult;
				int32_t ibIndex = 0;
				while (itmp)
				{
					sTmp[ibIndex + index] = itmp % 10 + '0';
					itmp = itmp / 10;
					ibIndex++;
				}
				//---
				//cout <<"ibIndex=" << ibIndex << endl;

				// add 2 str :base + tmp ->base

				for (int32_t j = 0; j <= ibIndex + index; j++)
				{
					int32_t t1 = (sTmp[j] - '0') + (sBase[j] - '0');
					sBase[j] = t1 % 10 + '0';

					int32_t t2 = t1 / 10;
					int32_t j1 = 0;
					do
					{
						t1 = sBase[j + j1 + 1] -'0' + t2;
						sBase[j + j1 + 1] = t1 % 10 + '0';
						t2 = t1 / 10;
						j1++;
					} while (t2);

					//cout << "j1=" << j1 << endl;
				}												
				
				
				//-----
#if 0
				{
					printf("sTmp: ");
					for (int32_t i = i_re + index ; i >= 0; i--)
						printf("%c", sTmp[i]);
					printf("\r");				
					printf("sBase: ");
					for (int32_t i = i_re + index ; i >= 0; i--)
						printf("%c", sBase[i]);
					printf("\r\n");
				}
#endif
				//reset sTmp
				{
					int32_t i = 0;
					while (i < tNum)
					{
						sTmp[i] = '0';
						i++;
					}				
				}				
			}										
		}
#endif
	
	}
}


