#include "desserts_arr.h"

Array_Desserts::Array_Desserts() {}

Array_Desserts::Array_Desserts(const Array_Desserts& copy) :index(copy.index) {
	for (int i = 0; i <= copy.index; i++) {
		desserts[i] = copy.desserts[i]->clone();
	}
}

Array_Desserts::~Array_Desserts() {
	while (index >= 0) {
		delete desserts[index];
		index--;
	}
}
Array_Desserts& Array_Desserts::operator=(const Array_Desserts& copy) {
	if (this == &copy)
		return *this;
	while (index >= 0) {
		delete desserts[index];
		index--;
	}
	for (int i = 0; i <= copy.index; i++) {
		desserts[i] = copy.desserts[i]->clone();
	}
	index = copy.index;
	return *this;
}



void Array_Desserts::Add_Dessert(Dessert* dessert) {
	index += 1;
	if (index >= 255) {
		return;
	}
	desserts[index] = dessert->clone();
}


Dessert* Array_Desserts::Get_Dessert(int index) const {
	if (index < 0) {
		index = 0;
	}
	if (index >= this->index) {
		index = this->index - 1;
	}

	return desserts[index]->clone();
}

void Array_Desserts::Show_Array_Desserts() const {
	for (int i = 0; i <= this->index; ++i) {
		if (i == 0) { cout << "\33[1:34mBake\33[0m\n"; }
		if (i == ((this->index + 1) / 2)) { cout << "\33[1:34mJelly dessert\33[0m\n"; }
		cout << "\33[1:33mDessert "<< i + 1 << ":\33[0m\n";
		desserts[i]->Print();
		cout << endl;
	}
}

void Array_Desserts::Not_Glucose_Max_Proteins()
{
	double max = 0;
	size_t index_of_max_element;
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if (desserts[i]->IsItGlucose() != 0)
		{
			double tmp = desserts[i]->IsItGlucose();
			size_t index_tmp = i;
			if (max < tmp)
			{
				max = tmp;
				index_of_max_element = index_tmp;
			}
		}
	}
	cout << "Non-glucose dessert with max proteins:" << endl;
	desserts[index_of_max_element]->Print();
}

void Array_Desserts::Sweet_Sour_Taste_And_Max_Kkal()
{
	double max = 0;
	size_t index_of_max_element;
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if (desserts[i]->IsItSweetSour())
		{
			double tmp = desserts[i]->IsItSweetSour();
			size_t index_tmp = i;
			if (max < tmp)
			{
				max = tmp;
				index_of_max_element = index_tmp;
			}
		}
	}
	cout << "Dessert with sweet and sour taste and max kkal:" << endl;
	desserts[index_of_max_element]->Print();
}

void Array_Desserts::No_Flavour_And_Min_Time_Of_Baking()
{
	double min_time = 1000;
	size_t index_of_dessert_with_min_time_of_baking;
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if (desserts[i]->Bake_IsItFlour())
		{
			double tmp = desserts[i]->Bake_IsItFlour();
			size_t index_tmp = i;
			if (min_time > tmp)
			{
				min_time = tmp;
				index_of_dessert_with_min_time_of_baking = index_tmp;
			}
		}
	}
	cout << "Non-flavour dessert with min time of baking:" << endl;
	desserts[index_of_dessert_with_min_time_of_baking]->Print();
}


