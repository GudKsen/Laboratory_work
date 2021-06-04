#pragma once
#include "class_array.h"

class bake :public Dessert {
	//friend ostream& operator<< (ostream& output, const bake & obh) // перегруженный оператор вывода
	//{
	//	output << obh.time_of_baking << ' ' << obh.is_flavour;
	//	return output;
	//}
private:
	double time_of_baking;
	bool is_flavour;
public:
	bake() {
		time_of_baking = 0;
		is_flavour = false;
	}

	void setterbake(double time, bool isflav)
	{
		time_of_baking = time;
		is_flavour = isflav;
	}

	double TimeOfBaking() {
		return time_of_baking;
	}

	bool IsFlavour() {
		return is_flavour;
	}

	void add() {
		Dessert* smth_for_inserting = new Dessert;
		smth_for_inserting->setter(false, "jvj", 1000, 200, 300, 10, 30, "gchgfxx");
		//Array_Desserts::add_el(0, smth_for_inserting);
		//Array_Desserts::search_by_index(1);
	}


	~bake() {

	}
};
