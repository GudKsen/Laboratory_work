#pragma once
#include "class_data.h"
#include <cstdlib>
#include <fstream>
#include "jelly_based_dessert.h"
#include "bake.h"
using std::istream;
using std::ostream;

class Array_Desserts {
	//friend istream& operator>> (istream&, Array_Desserts&); // перегруженный оператор ввода
	friend ostream& operator<< (ostream&, const Array_Desserts&); // перегруженный оператор вывода
private:
	Dessert** ptr;
	size_t size;
public:
	Array_Desserts();

	Array_Desserts(size_t sizearr);

	void setarray(int index, bool glucose, std::string name, double weight, double nkkal, double nproteins, double nfats, double ncarb, char taste[]);

	void showarray();

	~Array_Desserts();

	void delete_el(size_t index);

	void add_el(size_t index, Dessert* smth);

	void searching_by_min_weight_and_taste();

	void search_by_index(int index);

	void set_information_to_array();

	Array_Desserts(const Array_Desserts& arrayToCopy);

	Dessert*& operator[](size_t index);

	Array_Desserts& operator+= (Dessert* smth);

	Array_Desserts& operator- (size_t index);

	const Array_Desserts& operator= (const Array_Desserts&); // оператор присваивания
	bool operator== (const Array_Desserts&) const; // оператор сравнения

	void read_from_file(std::string filename);

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

