#pragma once
#include "menu.h"

class Task 
{
	string fileName;
	int TaskNumber;
	int Number_of_arrays;
	int* array_of_sizes;
	int** arrays;
	int ResultSize;
	int* result;
public:
	Task();
	~Task();
	void Start();
	void ReadNameFile();
	void Read_From_File();
	void Write_To_File();
	void SetSize(int arrIndex, int val);
	void SetEl(int arrIndex, int index, int val);
	void Selected_Function(int number);
	int GetSize(int arrIndex);
	int GetEl(int arrIndex, int index);
	int* Sum_Arrays(int index1, int index2);
	int* Mult_Arrays(int index1, int index2);
	int* Average_Of_Array();
	int* Find_Max_El();
	int* Find_Min_El();
	int* Find_Positive_Number();
	int* Find_Negative_Number();
	int* Search_In_Range(int range1, int range2);
	int* Find_Max_El_Pos();
	int* Find_Max_Number_Of_El();
};

