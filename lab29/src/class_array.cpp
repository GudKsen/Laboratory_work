#include "class_array.h"



template <class T>
void Array_Desserts<T>::setarray(int index, bool glucose, std::string name, double weight, double nkkal, double nproteins, double nfats, double ncarb, std::string taste) {
	ptr[index]->setter(glucose, name, weight, nkkal, nproteins, nfats, ncarb, taste);
}





template <class T>
void Array_Desserts<T>::delete_el(size_t index) {
	if (this->size == 0) return;
	Dessert * *new_array = new Dessert * [size - 1];
	if (index >= size) index = this->size - 1;
	memcpy(new_array, this->ptr, index * sizeof(Dessert*));
	memcpy(new_array + index, this->ptr + index + 1, (this->size - index - 1) * sizeof(Dessert*));
	delete ptr[index];
	delete[] this->ptr;
	this->ptr = new_array;
	this->size--;
}


template <class T>
void Array_Desserts<T>::add_el(size_t index, T * smth) {
	Dessert** new_Dessert = new Dessert * [size + 1];
	int n = 0;
	for (size_t i = 0; i < size + 1; i++) {
		new_Dessert[i] = this->ptr[n];
		if (i == index) {
			new_Dessert[i] = smth;
			n--;
		}
		n++;
	}
	delete[] this->ptr;
	this->ptr = new_Dessert;
	this->size++;
}






template <class T>
Array_Desserts<T>::Array_Desserts(const Array_Desserts & arrayToCopy) // ����������� �����
	:size(arrayToCopy.size)              // ������������� ������� �������
{
	ptr = new Dessert * [size]; // �������� ����� � ������ ��� �������

	for (size_t ix = 0; ix < size; ix++)
		ptr[ix] = arrayToCopy.ptr[ix]; // ��������� ������ ���������� ������� arrayToCopy
}

//template <class T>
//T*& Array_Desserts<T>::operator[](size_t index)
//{
//	return ptr[index];
//}

//template <class T>
//Array_Desserts<T> &Array_Desserts<T>::operator+=(T * smth)
//{
//	T** newdessert = new T * [size + 1];
//	memcpy(newdessert, ptr, size * sizeof(T*));
//	newdessert[size] = smth;
//	delete[] this->ptr;
//	this->ptr = newdessert;
//	this->size++;
//	return *this; // ��������� ����� �������������� ���������
//}


template <class T>
Array_Desserts<T> &Array_Desserts<T>::operator-(size_t index)
{
	if (this->size == 0) return *this;
	T * *new_array = new T * [size - 1];
	if (index >= size) index = this->size - 1;
	memcpy(new_array, this->ptr, index * sizeof(T*));
	memcpy(new_array + index, this->ptr + index + 1, (this->size - index - 1) * sizeof(T*));
	delete[] this->ptr;
	this->ptr = new_array;
	this->size--;
	return *this;
}


template <class T>
const Array_Desserts<T> & Array_Desserts<T>::operator=(const Array_Desserts & right)
{
	if (&right != this) // ����� �� ����������� ����������������
	{
		if (size != right.size)
		{
			delete[] ptr; // ���������� ������������
			size = right.size; // ���������� ������ ������ �������
			ptr = new T * [size]; // �������� ������ ��� ���������� ������
		}

		for (size_t ix = 0; ix < size; ix++)
			ptr[ix] = right.ptr[ix]; // ����������� ������
	}

	return *this; // ��������� ������������� ������������, �������� x = t = e
}


template <class T>
bool Array_Desserts<T> ::operator==(const Array_Desserts<T> & right) const
{
	if (size != right.size)
		return false; // ������� � ������ ����������� ���������
	for (size_t ix = 0; ix < size; ix++)
		if (ptr[ix] != right.ptr[ix])
			return false; // ������� �� �����

	return true; // ������� �����
}


//template <class T>
//void Array_Desserts<T>::read_from_file(std::string filename)
//{
//	std::ifstream myfile;
//	myfile.open(filename);
//	if (myfile.is_open()) {
//		for (size_t i = 0; i < this->size; i++) {
//			if (!myfile.eof()) {
//				std::string buff;
//				std::getline(myfile, buff);
//				ptr[i]->from_string(buff);
//			}
//		}
//	}
//	else {
//		myfile.close();
//		return;
//	}
//	myfile.close();
//}

// ������������� �������� �����, ��� ����� �������� ������� � ����������
//istream& operator>> (istream& input, Array_Desserts& obj)
//{
//	for (int ix = 0; ix < obj.size; ix++)
//		input >> obj.ptr[ix]->setter; // ��������� ������ ������� obj
//	return input; // ��������� ������������� ����, ���� cin >> x >> y >> z >> ...
//}

// ������������� �������� ������ ��� ������ Array (����� ��������� ������� �� �����)
//template <class T>
//ostream& operator<< (ostream & output, const Array_Desserts<T> & obj)
//{
//	for (size_t ix = 0; ix < obj.size; ix++)
//	{
//		output << *obj.ptr[ix];
//		output << std::endl;
//	}
//
//	output << std::endl; // ������� ������� �� ����� ������
//
//	return output; // ��������� ������������� �����, ���� cout << x << y << z << ...
//}


template <class T>
void Array_Desserts<T>::write_to_file(std::string filename, Array_Desserts smth) {
	std::ofstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		for (size_t i = 0; i < size; i++) {
			std::string tmp = smth[i]->to_string();
			myfile << tmp;
		}
	}
	myfile.close();
}

