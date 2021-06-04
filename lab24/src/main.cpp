#include "class_array.h"


int main() {
	std::string name = "donut";
	std::string taste = "sugar";
	Dessert* smth_for_inserting = new Dessert;
	smth_for_inserting->setter(false, taste, 1000, 200, 300, 10, 30, name);
	

	Array_Desserts muarray3;
	muarray3.set_information_to_array();
	muarray3 += smth_for_inserting;
	std::cout << muarray3;
	//std::cout << muarray3 - 1;
	muarray3.delete_el(1);
	muarray3.searching_by_min_weight_and_taste();

	std::string array4 = "0 cookie 100 20 30 10 10 solodkiy";
	Array_Desserts myarra4;
	myarra4[0]->from_string(array4);  //read information from string
	std::cout << myarra4;
	myarra4[0]->to_string();


	std::cout << std::endl;
	std::string filename = "/home/ksen/new_reposit/lab24/AllDesserts.txt";
	std::string filename1 = "/home/ksen/new_reposit/lab24/AllDesserts_empty.txt";
	Array_Desserts marray;
	marray.read_from_file(filename);
	marray.showarray();
	return 0;
}
