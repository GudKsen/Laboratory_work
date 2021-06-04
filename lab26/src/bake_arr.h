#pragma once
#include "bake.h"

class Array_Bake
{
private:
	size_t sizemass;
	bake** mass;
public:
	Array_Bake()
	{
		sizemass = 3;
		mass = new bake * [sizemass];
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i] = new bake;
		}
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setterbake(0, false);
		}
	}

	Array_Bake(size_t sizet)
	{
		sizemass = sizet;
		mass = new bake * [sizemass];
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i] = new bake;
		}
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setterbake(0, false);
		}
	}

	Array_Bake(double time_, bool flavour_)
	{
		sizemass = 1;
		mass = new bake * [sizemass];
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i] = new bake;
		}
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setterbake(time_, flavour_);
		}
	}

	~Array_Bake()
	{

		for (size_t i = 0; i < sizemass; i++)
		{
			delete mass[i];
		}
		delete[] mass;
	}

	void setbake()
	{
		double arr_time[3] = { 100, 124, 329 };
		bool arr_flavour[3] = { true, false, true };
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setterbake(arr_time[i], arr_flavour[i]);
		}
	}

	void print_bake()
	{
		for (size_t i = 0; i < sizemass; i++)
		{
			std::cout << "Time of baking: " << mass[i]->TimeOfBaking() << " Has flavour:" << mass[i]->IsFlavour() << std::endl;
		}
	}

	void delete_bake(size_t index) {
		if (this->sizemass == 0) return;
		bake * *new_array = new bake * [sizemass - 1];
		if (index >= sizemass) index = this->sizemass - 1;
		memcpy(new_array, this->mass, index * sizeof(Dessert*));
		memcpy(new_array + index, this->mass + index + 1, (this->sizemass - index - 1) * sizeof(Dessert*));
		delete mass[index];
		delete[] this->mass;
		this->mass = new_array;
		this->sizemass--;
	}


	void add_bake(size_t index, bake * smth) {
		bake** new_Dessert = new bake * [sizemass + 1];
		int n = 0;
		for (size_t i = 0; i < sizemass + 1; i++) {
			new_Dessert[i] = this->mass[n];
			if (i == index) {
				new_Dessert[i] = smth;
				n--;
			}
			n++;
		}
		delete[] this->mass;
		this->mass = new_Dessert;
		this->sizemass++;
	}

};
