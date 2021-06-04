#include "class_array.h"

void test_add_el() {
	char name[] = "donut";
	char taste[] = "sugar";
	Array_Desserts exp(4);
	exp.set_information_to_array();
	exp[3]->setter(false, taste, 1000, 200, 300, 10, 30, name);

	Array_Desserts res;
	res.set_information_to_array();
	Dessert* smth_for_inserting = new Dessert;
	smth_for_inserting->setter(false, taste, 1000, 200, 300, 10, 30, name);
	res += smth_for_inserting;

	if (exp == res) {
		std::cout << "expectation == result" << std::endl;
	}
	else {
		std::cout << "expectation != result" << std::endl;
	}
}

void test_del_el() {
	char name[] = "donut";
	char taste[] = "sugar";
	Array_Desserts exp;
	exp[0]->setter(true, "cupcake", 500, 1200, 230, 20, 123, "vanil");
	exp[1]->setter(true, "eclair", 236, 500, 320, 50, 231, "creme");
	exp[2]->setter(false, taste, 1000, 200, 300, 10, 30, name);

	Array_Desserts res(4);
	res.set_information_to_array();
	res[3]->setter(false, taste, 1000, 200, 300, 10, 30, name);
	res - 1;

	if (exp == res) {
		std::cout << "expectation == result" << std::endl;
	}
	else {
		std::cout << "expectation != result" << std::endl;
	}
}


int main () {
	test_add_el();
	test_del_el();


	return 0;
}
