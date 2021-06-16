#pragma once
#include "class_array.h"

class bake :public Dessert {
	
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

	~bake() {

	}
};
