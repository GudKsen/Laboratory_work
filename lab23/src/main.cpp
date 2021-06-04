#include "class_array.h"



int main() {
	Array_Desserts myarray;
	char name[] = "donut";
	char taste[] = "sugar";
	std::cout << "--------------set element on 1st position--------------" << std::endl;
	myarray.setarray(0, true, name, 100, 50, 20, 10, 10, taste);
	myarray.showarray();

	std::cout << std::endl;
	myarray.setarray(1, false, name, 200, 100, 20, 30, 35, taste); //88 bytes
	myarray.showarray();

	myarray.setarray(2, true, name, 300, 200, 30, 50, 60, taste);
	std::cout << std::endl << std::endl;
	myarray.showarray();
	std::cout << std::endl << std::endl;

	std::cout << "--------------delete 2nd element---------------" << std::endl;
	myarray.delete_el(1);
	myarray.showarray();
	std::cout << std::endl << std::endl;

	Dessert* smth_for_inserting = new Dessert;
	smth_for_inserting->setter(false, taste, 1000, 200, 300, 10, 30, name);
	std::cout << "--------------insert element on 1st position---------------" << std::endl;
	myarray.add_el(0, smth_for_inserting);
	myarray.showarray();
	std::cout << std::endl << std::endl;

	//myarray.searching_by_min_weight_and_taste();
	std::cout << std::endl << std::endl;
	Array_Desserts myarray2;
	myarray2.set_information_to_array();
	std::cout << std::endl << std::endl;
	myarray2.showarray();
	std::cout << std::endl << std::endl;                                                                                               
	
	
	std::cout << std::endl << std::endl;
	myarray.search_by_notGlucose_maxCarb();
	
	return 0;
}