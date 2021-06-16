#include "class_array.h"




int main() {
	char name[] = "donut";
	char taste[] = "sugar";
	Dessert* smth_for_inserting = new Dessert;
	smth_for_inserting->setter(false, taste, 1000, 200, 300, 10, 30, name);
	
	Array_Desserts muarray3;
	muarray3.set_information_to_array();
	std::cout << "----------------------Array-----------------------" << std::endl;
	std::cout << muarray3;
	std::cout << std::endl;

	std::cout << "---------------Add element in array---------------" << std::endl;
	muarray3 += smth_for_inserting;
	std::cout << muarray3;
	std::cout << std::endl;
	
	std::cout << "----------------Delete 1st element----------------" << std::endl;
	std::cout << muarray3 - 1;
	std::cout << std::endl;

	std::cout << "----------------------Search----------------------" << std::endl;
	muarray3.searching_by_min_weight_and_taste();
	std::cout << std::endl;

	std::string array4 = "0 cookie 100 20 30 10 10 solodkiy";
	Array_Desserts myarra4;
	std::cout << std::endl;
	std::cout << "---------------Take information from string---------------" << std::endl;
	myarra4[0]->from_string(array4);  //read information from string
	std::cout << myarra4;
	
	std::cout << std::endl;
	std::cout << "---------------Write information to string----------------" << std::endl;
	myarra4[0]->to_string();
	muarray3[0]->to_string();
	

	std::cout << std::endl;
	std::string filename = "/home/ksen/new_reposit/lab25/AllDesserts.txt";
	std::string filename1 = "C:\\Users\\Tb\\All_Desserts.txt";
	//Array_Desserts marray;
	//marray.read_from_file(filename);
	
	std::cout << std::endl;
	Array_Desserts marr;
	std::cout << "---------------Take information from file---------------" << std::endl;
	marr <= filename;
	std::cout << marr;

	Array_Desserts arr3;
	std::cout << "Input information to array of desserts(3 desserts):" << std::endl;
	std::cout << "Array's name: arr3" << std::endl;
	std::cin >> arr3;
	std::cout << std::endl;
	std::cout << "Output information from arr3:" << std::endl;
	std::cout << arr3;

	
	return 0;
}
