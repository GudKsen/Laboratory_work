#include "class_array.h"

void test_from_string() {
	std::string array4 = "0 cookie 100 20 30 10 10 solodkiy";
	Array_Desserts res(1);
	res[0]->from_string(array4);  //read information from string

	Array_Desserts exp(1);
	exp[0]->setter(false, "cookie", 100, 20, 30, 10, 10, "solodkiy");

	if (exp == res) {
		std::cout << "expectation == result\n" << std::endl;
	}
	else {
		std::cout << "expectation != result\n" << std::endl;
		std::cout << res << std::endl;
		std::cout << exp << std::endl;
	}
}

int main() {
	test_from_string();

	return 0;
}
