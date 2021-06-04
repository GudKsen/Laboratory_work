#include <iostream>
#include "class_array.h"

void test_add_el() {
	Array_Desserts<Dessert> exp;
	std::string name = "donut";
	std::string taste = "sugar";
	exp.setarray(0, false, taste, 1000, 200, 300, 10, 30, name);
	exp.setarray(1, true, name, 100, 50, 20, 10, 10, taste);
	exp.setarray(2, true, name, 300, 200, 30, 50, 60, taste);

	Array_Desserts<Dessert> res;
	Dessert* smth_for_inserting = new Dessert;
	smth_for_inserting->setter(false, taste, 1000, 200, 300, 10, 30, name);
	res.setarray(1, true, name, 100, 50, 20, 10, 10, taste);
	res.setarray(2, true, name, 300, 200, 30, 50, 60, taste);
	res.add_el(0, smth_for_inserting);
	res.delete_el(1);
	if (exp == res) {
		std::cout << "expectation == result of adding\n\n";
	}
	else {
		std::cout << "expectation != result of adding\n\n";
		std::cout << std::endl << std::endl;
		std::cout << "expectation\n";
		exp.showarray();
		std::cout << std::endl << std::endl;
		std::cout << "result\n";
		res.showarray();
		std::cout << std::endl << std::endl;
	}
}

void test_del_el() {
	Array_Desserts<Dessert> exp(2);
	std::string name = "donut";
	std::string taste = "sugar";
	exp.setarray(0, true, name, 100, 50, 20, 10, 10, taste);
	exp.setarray(1, true, name, 300, 200, 30, 50, 60, taste);

	Array_Desserts<Dessert> res;
	res.setarray(0, true, name, 100, 50, 20, 10, 10, taste);
	res.setarray(1, false, name, 200, 100, 20, 30, 35, taste);
	res.setarray(2, true, name, 300, 200, 30, 50, 60, taste);
	res.delete_el(1);

	if (exp == res) {
		std::cout << "expectation == result of deleting" << std::endl;
	}
	else {
		std::cout << "expectation != result of deleting" << std::endl;
		std::cout << std::endl << std::endl;
		std::cout << "expectation\n";
		exp.showarray();
		std::cout << std::endl << std::endl;
		std::cout << "result\n";
		res.showarray();
		std::cout << std::endl << std::endl;
	}
}



int main () {

	test_add_el();
	test_del_el();
	return 0;
}
