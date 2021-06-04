#pragma once
#include "class_data.h"
#include <cstdlib>
#include <fstream>
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

	Array_Desserts(size_t size_arr);

	void setarray(int index, bool glucose, char name[], double weight, double nkkal, double nproteins, double nfats, double ncarb, char taste[]);

	void showarray();

	~Array_Desserts();

	void delete_el(size_t index);

	void add_el(size_t index, Dessert* smth);

	void searching_by_min_weight_and_taste();

	void search_by_index(size_t index);

	void set_information_to_array();

	Array_Desserts(const Array_Desserts& arrayToCopy);

	Dessert*& operator[](size_t index);

	Array_Desserts& operator+= (Dessert* smth);

	Array_Desserts& operator- (size_t index);

	const Array_Desserts& operator= (const Array_Desserts&); // оператор присваивания
	bool operator== (const Array_Desserts&) const; // оператор сравнения

	void read_from_file(std::string filename);

	void write_to_file(std::string filename, Array_Desserts smth);


};

