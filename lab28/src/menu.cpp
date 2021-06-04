#include "menu.h"
#include "task.h"

int Menu() 
{
	int choice;
	cout << endl << "Choose:" << endl;
	cout << "\t1. Determine the sum of two arrays;\n" << endl;
	cout << "\t2. Multiply two arrays;\n" << endl;
	cout << "\t3. Calculate the average of the elements of an array;\n" << endl;
	cout << "\t4. Find the element with the maximum value in the array;\n" << endl;
	cout << "\t5. Find the element with the minimum value in the array;\n" << endl;
	cout << "\t6. Determine the number of positive elements in an array;\n" << endl;
	cout << "\t7. Determine the number of items that belong to the range [a, b];\n" << endl;
	cout << "\t8. Determine the number of negative elements in an array;\n" << endl;
	cout << "\t9. Find the number of the first element with the maximum value in the array;\n" << endl;
	cout <<	"\t10. Find the number of elements with the maximum value in the array." << endl;
	cout << endl << "Choose the option: ";
	cin >> choice;
	if (choice > 10 || choice < 1) 
	{
		throw out_of_range("Out of range exception");
	}
	else 
	{
		return choice;
	}
}

void Task::Selected_Function(int choice) 
{
	int index1, index2;
	switch (choice) 
	{
	case 1:
		cout << "Enter input indices of arrays: ";
		cin >> index1 >> index2;
		if (result != nullptr)
		{
			delete[] result;
		}
		cout << "Calling sum function: " << endl;
		result = Sum_Arrays(index1, index2);
		break;
	case 2:
		cout << "Enter input indices of arrays: ";
		cin >> index1 >> index2;
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling multiply function: " << endl;
		result = Mult_Arrays(index1, index2);
		break;
	case 3:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Function call func calculate average" << endl;
		result = Average_Of_Array();
		break;
	case 4:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function for finding the maximum element" << endl;
		result = Find_Max_El();
		break;
	case 5:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function for finding the minimum element " << endl;
		result = Find_Min_El();
		break;
	case 6:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function for finding positive elements" << endl;
		result = Find_Positive_Number();
		break;
	case 7:
		cout << "Enter the range: ";
		cin >> index1 >> index2;
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function to find an N element in a range" << endl;
		result = Search_In_Range(index1, index2);
		break;
	case 8:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function for finding negative elements" << endl;
		result = Find_Negative_Number();
		break;
	case 9:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function for finding the position of the maximum element" << endl;
		result = Find_Max_El_Pos();
		break;
	case 10:
		if (result != nullptr) 
		{
			delete[] result;
		}
		cout << "Calling the function for finding the number of maximum elements" << endl;
		result = Find_Max_El();
		break;
	default:
		break;
	}
}