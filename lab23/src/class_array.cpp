#include "class_array.h"

Array_Desserts::Array_Desserts() {
	size = 3;
	ptr = new Dessert * [size];
	for (size_t i = 0; i < size; i++) {
		ptr[i] = new Dessert;
	}

	char nullname[] = "0";
	char nulltaste[] = "0";
	for (size_t i = 0; i < size; i++) {
		ptr[i]->setter(false, nullname, 0, 0, 0, 0, 0, nulltaste);
	}
}

bool Array_Desserts::operator == (const Array_Desserts& right) {
		if (size != right.size)
			return false; // массивы с разным количеством элементов

		for (size_t ix = 0; ix < size; ix++)
			if ((ptr[ix] != right.ptr[ix]) == false)
				return false; // массивы не равны

		return true; // массивы равны
	}

Array_Desserts::Array_Desserts(size_t size_arr) {
	size = size_arr;
	ptr = new Dessert * [size];
	for (size_t i = 0; i < size; i++) {
		ptr[i] = new Dessert;
	}

	char nullname[] = "0";
	char nulltaste[] = "0";
	for (size_t i = 0; i < size; i++) {
		ptr[i]->setter(false, nullname, 0, 0, 0, 0, 0, nulltaste);
	}
}

void Array_Desserts::setarray(int index, bool glucose, char name[], double weight, double nkkal, double nproteins, double nfats, double ncarb, char taste[]) {
	ptr[index]->setter(glucose, name, weight, nkkal, nproteins, nfats, ncarb, taste);
}

Array_Desserts::~Array_Desserts() {
	for (size_t i = 0; i < size; i++) {
		delete ptr[i];
	}
	delete[] ptr;
}

void Array_Desserts::delete_el(size_t index) {
	if (this->size == 0) return;
	Dessert** new_array = new Dessert * [size - 1];
	if (index >= size) index = this->size - 1;
	memcpy(new_array, this->ptr, index * sizeof(Dessert*));
	memcpy(new_array + index, this->ptr + index + 1, (this->size - index - 1) * sizeof(Dessert*));
	delete[] this->ptr;
	this->ptr = new_array;
	this->size--;
}

//void Array_Desserts::add_el(size_t index, Dessert* smth) {
//	if (this->size == 0) return;
//	Dessert * *new_array = new Dessert * [size + 1];
//	//if (index >= size) index = this->size - 1;
//	memcpy(new_array, this->ptr, index * sizeof(Dessert*));
//	memcpy(new_array + index, smth, sizeof(Dessert*));
//	memcpy(new_array + index + 1, this->ptr + index, (size - index) * sizeof(Dessert*));
//	delete[] this->ptr;
//	this->ptr = new_array;
//	this->size++;
//	std::cout << "adding:"<<std::endl;
//	ptr[2]->show();
//}

void Array_Desserts::add_el(size_t index, Dessert* smth) {
	Dessert** new_Dessert = new Dessert*[size + 1];
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

void Array_Desserts::searching_by_min_weight_and_taste() {
	double min_weight = ptr[0]->getter_weight();
	size_t i_min = 0;
	char taste_for_finding[] = "sugar";
	for (size_t i = 0; i < size; i++) {
		if(strcmp(ptr[i]->getter_taste(), taste_for_finding) == 0 && min_weight > ptr[i]->getter_weight()){
			i_min = i;
			min_weight = ptr[i]->getter_weight();
		}
	}
	std::cout << "Finding dessert:\n";
	ptr[i_min]->show();
}

void Array_Desserts::search_by_notGlucose_maxCarb() {
	double max_carb = 0;
	size_t max_i = size;
	for (size_t i = 0; i < size; i++) {
		if (ptr[i]->getter_isglucose() == false && ptr[i]->getter_carbohydrates() > max_carb) {
			max_carb = ptr[i]->getter_carbohydrates();
			max_i = i;
		}
	}

	if (max_i < size) {
		std::cout << "Finding dessert:\n";
		ptr[max_i]->show();
	}
}

Dessert* Array_Desserts::search_by_notGlucose_maxCarb_for_test() {
	double max_carb = 0;
	size_t max_i = size;
	for (size_t i = 0; i < size; i++) {
		if (ptr[i]->getter_isglucose() == false && ptr[i]->getter_carbohydrates() > max_carb) {
			max_carb = ptr[i]->getter_carbohydrates();
			max_i = i;
		}
	}

	if (max_i < size) {
		std::cout << "Finding dessert:\n";
		ptr[max_i]->show();
		return ptr[max_i];
	}
}

void Array_Desserts::search_by_index(size_t index) {
	for (size_t i = 0; i < size; i++) {
		if (i == index) {
			ptr[i]->show();
		}
	}
	
}

void Array_Desserts::showarray() {
	for (size_t i = 0; i < size; i++) {
		search_by_index(i);
	}
}

void Array_Desserts::set_information_to_array() {
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

Array_Desserts::Array_Desserts(const Array_Desserts& arrayToCopy) // конструктор копии
	:size(arrayToCopy.size)              // инициализатор размера массива
{
	ptr = new Dessert*[size]; // выделить место в памяти для массива

	for (size_t ix = 0; ix < size; ix++)
		ptr[ix] = arrayToCopy.ptr[ix]; // заполняем массив значениями массива arrayToCopy
}