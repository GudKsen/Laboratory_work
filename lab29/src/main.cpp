#include "class_array.h"
#include "bake_arr.h"
#define _CRTDBG_MAP_ALLOC 


int main() {
	std::string name = "donut";
	std::string taste = "sugar";
	Dessert* smth_for_inserting = new Dessert;
	smth_for_inserting->setter(false, taste, 1000, 200, 300, 10, 30, name);


	Array_Desserts<Dessert> muarray3;
	muarray3.set_information_to_array();
	muarray3 += smth_for_inserting;
	std::cout << muarray3;
	muarray3.searching_by_min_weight_and_taste();

	std::string array4 = "0 cookie 100 20 30 10 10 solodkiy";
	Array_Desserts<Dessert> myarra4;
	myarra4[0]->from_string(array4);  //read information from string

	myarra4[0]->to_string();


	std::cout << std::endl;
	std::string filename = "C:\\Users\\Tb\\AllDesserts.txt";
	std::string filename1 = "C:\\Users\\Tb\\All_Desserts.txt";
	/*Array_Desserts<Dessert> marray;
	marray.read_from_file(filename);
	marray.showarray();

	Array_Desserts<Dessert> marr;
	marr <= filename;
	std::cout << marr;
	std::cout << std::endl;
	std::cout << marr;
	std::cout << std::endl;*/


	jelly_dessert hhh("jelly", 100);
	std::cout << hhh.getter_jelly() << std::endl;
	std::cout << hhh.getter_weight_jelly() << std::endl;


	bool is_glucose_array[3] = { true, false, true };
	char name_dessert_array[3][20] = { "cupcake", "donut", "eclair" };
	double weight_array[3] = { 500, 200, 236 };
	double kkal_array[3] = { 1200, 1000, 500 };
	double proteins_array[3] = { 230, 120, 320 };
	double fats_array[3] = { 20, 23, 50 };
	double carbohydrates[3] = { 123, 321, 231 };
	char taste_array[3][20] = { "vanil", "sugar", "creme" };

	Array_Bake<bake> barr(3);
	barr.setbake();
	barr.print_bake();
	bake* bake_for_adding = new bake;
	bake_for_adding->setterbake(300, true);
	barr.add_bake(1, bake_for_adding);
	std::cout << std::endl << std::endl;
	barr.print_bake();
	barr.delete_bake(2);
	std::cout << std::endl << std::endl;
	barr.print_bake();
	return 0;
}
