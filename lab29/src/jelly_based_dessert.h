#pragma once
#include "class_data.h"

class jelly_dessert : private Dessert {
private:
	std::string jelly;
	double weight_jelly;
public:
	jelly_dessert() {

	}

	jelly_dessert(std::string jelly_tmp, double weight_dessert_tmp) {
		jelly = jelly_tmp;
		weight_jelly = weight_dessert_tmp;
	}

	std::string getter_jelly() {
		return jelly;
	}

	double getter_weight_jelly() {
		return weight_jelly;
	}

	~jelly_dessert() {
		std::cout << "Destructor are called" << std::endl;
	}
};

