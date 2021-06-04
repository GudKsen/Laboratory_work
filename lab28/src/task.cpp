#include "task.h"

Task::Task() : fileName(), TaskNumber(0), Number_of_arrays(0), array_of_sizes(nullptr), arrays(nullptr), ResultSize(0), result(nullptr) {}

Task::~Task() 
{
	if (arrays)
		for (int i = 0; i < Number_of_arrays; i++)
			delete[] arrays[i];
	delete[] arrays;
	delete[] array_of_sizes;
	delete[] result;
}

void Task::Start() 
{
	for (;;) 
	{
		try 
		{
			cout << "Enter input fileName: ";
			ReadNameFile();
			if (fileName == "\\exit")
			{
				return;
			}
			cout << "Reading from file " << endl;
			Read_From_File();
			TaskNumber = Menu();
			Selected_Function(TaskNumber);
			cout << endl << "Enter output fileName: ";
			ReadNameFile();
			if (fileName == "\\exit")
			{
				return;
			}
			cout << "Writing to file " << endl;
			Write_To_File();
		}
		catch (out_of_range & error) 
		{
			cout << error.what() << endl;
		}
		catch (std::ios_base::failure & error) 
		{
			cout << error.what() << endl;
		}
		catch (std::invalid_argument & error) 
		{
			cout << error.what() << endl;
		}
		cout << endl << "-----------------------------------------" << endl << endl;
		
	}
}


void Task::ReadNameFile() 
{
	cin >> fileName;
}

void Task::Read_From_File() 
{
	ifstream fin;
	fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
	fin.open(fileName, std::ios_base::in);
	fin >> Number_of_arrays;
	if (Number_of_arrays < 0) 
	{
		throw std::invalid_argument("Bad argument");
	}
	array_of_sizes = new int[Number_of_arrays];
	arrays = new int* [Number_of_arrays];
	for (int i = 0; i < Number_of_arrays; i++) 
	{
		int val_size;
		fin >> val_size;
		SetSize(i, val_size);
		arrays[i] = new int[GetSize(i)];
		for (int j = 0; j < GetSize(i); j++)
		{
			int val;
			fin >> val;
			SetEl(i, j, val);
		}
	}
	fin.close();
}

void Task::Write_To_File() 
{
	ofstream fout;
	fout.exceptions(std::ios_base::failbit | std::ios_base::badbit);
	fout.open(fileName, std::ios_base::out);
	for (int i = 0; i < ResultSize; i++) 
	{
		fout << result[i] << " ";
	}
	fout.close();
}

void Task::SetSize(int arrIndex, int val) {
	if (arrIndex >= Number_of_arrays || arrIndex < 0 || val < 0)
	{
		throw out_of_range("Out of range exception");
	}
	else {
		array_of_sizes[arrIndex] = val;
	}
}
void Task::SetEl(int arrIndex, int index, int val)
{
	if (arrIndex >= Number_of_arrays || arrIndex < 0) {
		throw out_of_range("Out of range exception:");
	}
	else if (index >= array_of_sizes[arrIndex] || index < 0)
	{
		throw out_of_range("Out of range exception");
	}
	else {
		arrays[arrIndex][index] = val;
	}
}

int Task::GetSize(int arrIndex) 
{
	if (arrIndex >= Number_of_arrays || arrIndex < 0) 
	{
		throw out_of_range("Out of range exception");
	}
	else 
	{
		return array_of_sizes[arrIndex];
	}
}
int Task::GetEl(int arrIndex, int index) 
{
	if (arrIndex >= Number_of_arrays || arrIndex < 0) 
	{
		throw out_of_range("Out of range exception");
	}
	else if (index >= array_of_sizes[arrIndex] || index < 0) 
	{
		throw out_of_range("Out of range exception");
	}
	else {
		return arrays[arrIndex][index];
	}
}


int* Task::Sum_Arrays(int index1, int index2) 
{
	if (GetSize(index1) != GetSize(index2)) 
	{
		ResultSize = 0;
		result = nullptr;
		throw std::invalid_argument("Bad argument");
	}
	ResultSize = GetSize(index1);
	int* temp_res = new int[ResultSize];
	for (int i = 0; i < ResultSize; i++)
		temp_res[i] = GetEl(index1, i) + GetEl(index2, i);
	return temp_res;
}

int* Task::Mult_Arrays(int index1, int index2) 
{
	if (GetSize(index1) != GetSize(index2)) 
	{
		ResultSize = 0;
		result = nullptr;
		throw std::invalid_argument("Bad argument");
	}
	ResultSize = GetSize(index1);
	int* temp_res = new int[ResultSize];
	for (int i = 0; i < ResultSize; i++)
		temp_res[i] = GetEl(index1, i) * GetEl(index2, i);
	return temp_res;
}

int* Task::Average_Of_Array() 
{
	int* temp_res = new int[Number_of_arrays];
	int sum = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			sum += GetEl(i, j);
		}
		temp_res[i] = sum / GetSize(i);
		sum = 0;
	}
	return temp_res;
}

int* Task::Find_Max_El() 
{
	int* temp_res = new int[Number_of_arrays];
	int elem = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (j == 0) 
			{
				elem = GetEl(i, j);
			}
			if (elem < GetEl(i, j)) 
			{
				elem = GetEl(i, j);
			}
		}
		temp_res[i] = elem;
	}
	return temp_res;
}

int* Task::Find_Min_El() 
{
	int* temp_res = new int[Number_of_arrays];
	int elem = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (j == 0) {
				elem = GetEl(i, j);
			}
			if (elem > GetEl(i, j)) 
			{
				elem = GetEl(i, j);
			}
		}
		temp_res[i] = elem;
	}
	return temp_res;
}

int* Task::Find_Positive_Number() 
{
	int* temp_res = new int[Number_of_arrays];
	int count = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (GetEl(i, j) >= 0) 
			{
				count++;
			}
		}
		temp_res[i] = count;
		count = 0;
	}
	return temp_res;
}

int* Task::Search_In_Range(int range1, int range2) 
{
	if (range1 >= range2) 
	{
		ResultSize = 0;
		result = nullptr;
		throw std::invalid_argument("Bad argument");
	}
	int* temp_res = new int[Number_of_arrays];
	int count = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (GetEl(i, j) >= range1 && GetEl(i, j) <= range2) 
			{
				count++;
			}
		}
		temp_res[i] = count;
		count = 0;
	}
	return temp_res;
}

int* Task::Find_Negative_Number() 
{
	int* temp_res = new int[Number_of_arrays];
	int count = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (GetEl(i, j) < 0) 
			{
				count++;
			}
		}
		temp_res[i] = count;
		count = 0;
	}
	return temp_res;
}

int* Task::Find_Max_El_Pos() 
{
	int* temp_res = new int[Number_of_arrays];
	int pos = 0;
	int elem = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (j == 0) 
			{
				elem = GetEl(i, j);
			}
			if (elem < GetEl(i, j)) 
			{
				elem = GetEl(i, j);
				pos = j;
			}
		}
		temp_res[i] = pos;
	}
	return temp_res;
}


int* Task::Find_Max_Number_Of_El() 
{
	int* temp_res = new int[Number_of_arrays];
	int elem = 0;
	int count = 0;
	ResultSize = Number_of_arrays;
	for (int i = 0; i < Number_of_arrays; ++i) 
	{
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (j == 0) 
			{
				elem = GetEl(i, j);
			}
			if (elem < GetEl(i, j)) 
			{
				elem = GetEl(i, j);
			}
		}
		for (int j = 0; j < GetSize(i); ++j) 
		{
			if (elem == GetEl(i, j)) 
			{
				count++;
			}
		}
		temp_res[i] = count;
		count = 0;
	}
	return temp_res;
}
