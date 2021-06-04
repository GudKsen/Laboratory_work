#include "desserts.h"

class Array_Desserts {
	Dessert* desserts[ARRAY_SIZE];
	int index = -1;
public:
	Array_Desserts();
	Array_Desserts(const Array_Desserts& copy);

	virtual ~Array_Desserts();

	void Add_Dessert(Dessert* baka);

	Dessert* Get_Dessert(int index) const;

	void Show_Array_Desserts() const;

	void Not_Glucose_Max_Proteins();

	void Sweet_Sour_Taste_And_Max_Kkal();

	void No_Flavour_And_Min_Time_Of_Baking();

	Array_Desserts& operator=(const Array_Desserts& copy);

	bool operator==(const Array_Desserts & right) const
{
	/*if (ARRAY_SIZE != right.ARRAY_SIZE)
		return false; // массивы с разным количеством элементов
*/
	for (size_t ix = 0; ix < ARRAY_SIZE; ix++)
		if ((desserts[ix] != right.desserts[ix]))
			return false; // массивы не равны

	return true; // массивы равны
}

	Dessert* No_Flavour_And_Min_Time_Of_Baking_copy()
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
	return desserts[index_of_dessert_with_min_time_of_baking];
}

Dessert*& operator[](size_t index_arr)
{
	return desserts[index_arr];
}

};

