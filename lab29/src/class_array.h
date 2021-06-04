#pragma once
#include "class_data.h"
#include <cstdlib>
#include <fstream>
#include "jelly_based_dessert.h"
#include "bake.h"
#include <typeinfo>
using std::istream;
using std::ostream;

template <class T>
class Array_Desserts {
	//friend istream& operator>> (istream&, Array_Desserts&); // перегруженный оператор ввода
	//template <class T> 
	friend ostream& operator<< (ostream& output, const Array_Desserts<T>& obj) // перегруженный оператор вывода
	{
		for (size_t ix = 0; ix < obj.size; ix++)
		{
			output << *obj.ptr[ix];
			output << std::endl;
		}

		output << std::endl; // перенос маркера на новую строку

		return output; // позволяет множественный вывод, типа cout << x << y << z << ...
	}

private:
	T** ptr;
	size_t size;
public:
	Array_Desserts()
	{
		size = 3;
		ptr = new Dessert * [size];
		for (size_t i = 0; i < size; i++) {
			ptr[i] = new Dessert;
		}

		std::string nullname = "0";
		std::string nulltaste = "0";
		for (size_t i = 0; i < size; i++) {
			ptr[i]->setter(false, nullname, 0, 0, 0, 0, 0, nulltaste);
		}
	}

	Array_Desserts(size_t sizearr)
	{
		size = sizearr;
		ptr = new Dessert * [size];
		for (size_t i = 0; i < size; i++) {
			ptr[i] = new Dessert;
		}

		std::string nullname = "0";
		std::string nulltaste = "0";
		for (size_t i = 0; i < size; i++) {
			ptr[i]->setter(false, nullname, 0, 0, 0, 0, 0, nulltaste);
		}
	}

	void setarray(int index, bool glucose, std::string name, double weight, double nkkal, double nproteins, double nfats, double ncarb, std::string taste);

	void showarray()
	{
		for (size_t i = 0; i < size; i++) {
			search_by_index(i);
		}
	}

	~Array_Desserts()
	{
		for (size_t i = 0; i < size; i++) {
			delete ptr[i];
		}
		delete[] ptr;
	}

	void delete_el(size_t index);

	void add_el(size_t index, T* smth);

	void searching_by_min_weight_and_taste()
	{
		double min_weight = -1;
		size_t i_min = 0;
		std::string taste_for_finding = "sugar";
		for (size_t i = 0; i < size; i++) {
			if ((ptr[i]->getter_taste() == taste_for_finding) && (min_weight > ptr[i]->getter_weight())) {
				i_min = i;
				min_weight = ptr[i]->getter_weight();
			}
		}
		if (min_weight != -1) {
			std::cout << "Finding dessert:\n";
			std::cout << ptr[i_min];
		}
		else {
			std::cout << "Dessert not found\n";
		}
	}

	void search_by_index(int index)
	{
		for (size_t i = 0; i < size; i++) {
			if (i == index) {
				std::cout << *ptr[i];
				std::cout << std::endl;
			}
		}

	}

	void set_information_to_array()
	{
		bool is_glucose_array[3] = { true, false, true };
		char name_dessert_array[3][20] = { "cupcake", "donut", "eclair" };
		double weight_array[3] = { 500, 200, 236 };
		double kkal_array[3] = { 1200, 1000, 500 };
		double proteins_array[3] = { 230, 120, 320 };
		double fats_array[3] = { 20, 23, 50 };
		double carbohydrates[3] = { 123, 321, 231 };
		char taste_array[3][20] = { "vanil", "sugar", "creme" };

		for (size_t i = 0; i < size; i++) {
			ptr[i]->setter(is_glucose_array[i], name_dessert_array[i], weight_array[i], kkal_array[i], proteins_array[i], fats_array[i], carbohydrates[i], taste_array[i]);
		}
	}

	Array_Desserts(const Array_Desserts& arrayToCopy);

	T*& operator[](size_t index)
	{
		return ptr[index];
	}

	Array_Desserts& operator+= (T* smth)
	{
		T** newdessert = new T * [size + 1];
		memcpy(newdessert, ptr, size * sizeof(T*));
		newdessert[size] = smth;
		delete[] this->ptr;
		this->ptr = newdessert;
		this->size++;
		return *this; // каскадный вызов перегруженного оператора
	}

	Array_Desserts& operator- (size_t index);

	const Array_Desserts& operator= (const Array_Desserts&); // оператор присваивания
	bool operator== (const Array_Desserts&) const; // оператор сравнения

	void read_from_file(std::string filename)
	{
		std::ifstream myfile;
		myfile.open(filename);
		if (myfile.is_open()) {
			for (size_t i = 0; i < this->size; i++) {
				if (!myfile.eof()) {
					std::string buff;
					std::getline(myfile, buff);
					ptr[i]->from_string(buff);
				}
			}
		}
		else {
			myfile.close();
			return;
		}
		myfile.close();
	}

	void write_to_file(std::string filename, Array_Desserts smth);

	Array_Desserts& operator<= (std::string filename) { //чтение
		std::ifstream myfile;
		myfile.open(filename);
		if (myfile.is_open()) {
			for (size_t i = 0; i < this->size; i++) {
				if (!myfile.eof()) {
					std::string buff;
					std::getline(myfile, buff);
					ptr[i]->from_string(buff);
				}
			}
		}
		else {
			myfile.close();
			return *this;
		}
		myfile.close();
		return *this;
	}

	Array_Desserts& operator>= (Array_Desserts smth) { //запись
		std::ofstream myfile;
		std::string filename = "C:\\Users\\Tb\\AllDesserts.txt";
		myfile.open(filename);
		if (myfile.is_open()) {
			for (size_t i = 0; i < size; i++) {
				std::string tmp = ptr[i]->to_string();
				myfile << tmp;
			}
		}
		myfile.close();
	}
};

