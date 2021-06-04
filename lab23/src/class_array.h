#pragma once
#include "class_data.h"
#include <cstdlib>

class Array_Desserts {
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

	bool operator == (const Array_Desserts& right) {
		if (size != right.size)
			return false; // массивы с разным количеством элементов

		for (size_t ix = 0; ix < size; ix++)
			if ((ptr[ix] != right.ptr[ix]) == false)
				return false; // массивы не равны

		return true; // массивы равны
	}

	void search_by_notGlucose_maxCarb();
	Dessert* search_by_notGlucose_maxCarb_for_test();
};