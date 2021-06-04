#include <task.h>
#include "menu.h"



void test1()
{
	int res[4];
	int exp[4] = {2, 3 , 4, 4};
	ifstream fin;
	fin.open("src/result.txt", std::ios_base::in);
	int tmp;
	for (size_t i = 0; i < 3; i++)
	{
		fin>>tmp;
		res[i] = tmp;
	}
	
	for (size_t i = 0; i < 3; i++)
	{
		if(res[i] != exp[i])
		{
			return;
		}
		
	}
	cout << " result==expectation\n" << endl;
	
}

int main() 
{
	test1();
	return 0;
}
