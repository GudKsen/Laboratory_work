#pragma once
#include "jelly_based_dessert.h"

class Array_Jelly_Dessert
{
private:
	size_t sizemass;
	jelly_dessert** mass;
public:
	Array_Jelly_Dessert()
	{
		sizemass = 3;
		mass = new jelly_dessert * [sizemass];
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i] = new jelly_dessert;
		}
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setter_jelly("??????", 0);
		}
	}

	Array_Jelly_Dessert(size_t sizet)
	{
		sizemass = sizet;
		mass = new jelly_dessert * [sizemass];
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i] = new jelly_dessert;
		}
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setter_jelly("?????", 0);
		}
	}

	Array_Jelly_Dessert(std::string  str, double weight)
	{
		sizemass = 1;
		mass = new jelly_dessert * [sizemass];
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i] = new jelly_dessert;
		}
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setter_jelly(str, weight);
		}
	}

	~Array_Jelly_Dessert()
	{

		for (size_t i = 0; i < sizemass; i++)
		{
			delete mass[i];
		}
		delete[] mass;
	}

	void setjelly()
	{
		std::string arr_str[3] = { "agar", "zhelatin", "agar-agar" };
		double arr_weight[3] = { 100, 124, 329 };
		for (size_t i = 0; i < sizemass; i++)
		{
			mass[i]->setter_jelly(arr_str[i], arr_weight[i]);
		}
	}

	void print_bake()
	{
		for (size_t i = 0; i < sizemass; i++)
		{
			std::cout << "Time of baking: " << mass[i]->getter_jelly() << " Has flavour:" << mass[i]->getter_weight_jelly() << std::endl;
		}
	}

	void delete_jelly(size_t index) {
		if (this->sizemass == 0) return;
		jelly_dessert * *new_array = new jelly_dessert * [sizemass - 1];
		if (index >= sizemass) index = this->sizemass - 1;
		memcpy(new_array, this->mass, index * sizeof(Dessert*));
		memcpy(new_array + index, this->mass + index + 1, (this->sizemass - index - 1) * sizeof(Dessert*));
		delete mass[index];
		delete[] this->mass;
		this->mass = new_array;
		this->sizemass--;
	}


	void add_jelly(size_t index, jelly_dessert * smth) {
		jelly_dessert** new_Dessert = new jelly_dessert * [sizemass + 1];
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
