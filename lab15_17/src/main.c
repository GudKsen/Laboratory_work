#include <lib.h>


int main() {
	struct Dessert cake[] = { {1, "jbirthday_cake", 120, {1000, 20, 20, 20}, "solodkyi"}, {0, "chocolate_cake", 300, {(float)1500, 10, (float)2.30, 4.5}, "solodkiy"}, {1, 
    "friut_cake", 200, {2000, 10,10,10}, "kyslo-solodkiy"} };
	struct Dessert cookie[2];
	//struct Dessert cake_bin[3];
	
	int number_of_desserts = sizeof(cake) / sizeof(cake[0]);
	char name_file_read[] = "/home/ksen/new_reposit/lab15, 17/AllDesserts.txt";
	char name_file_write[] = "/home/ksen/new_reposit/lab15, 17/Desserts.txt";
	Print_Dessert(cake, number_of_desserts);
	Write_To_File(name_file_write, cake, number_of_desserts);
	Read_From_File(name_file_read, cookie, 2);
	
	printf("\n-------------------------------------------\n");
	Write_To_Binary_File(cake, number_of_desserts);

	Read_From_Binary_File();
	printf("\n=============================================================\n");

	int index_search = 1;
	printf("Please enter the index for searching: ");

	Search_by_Index_in_Binary_File(index_search);

	printf("\n\n");
	Sort_Weight2_Dessert(cake, number_of_desserts);
	Print_Dessert(cake, number_of_desserts);
	
	
	return 0;
}



/*int choice = 1;
	printf("1 - Name, 2 - Weight, 3 - Kkal, 4 - bilky, 5 - zhyry, 6 - carbohydrates, 7 - Taste\n"); 
	switch (choice) {
	case 1: 
		Sort_Name_Dessert(cake, number_of_desserts);
		break;
	case 2:
		Sort_Weight_Dessert(cake, number_of_desserts);
		break;
	case 3:
		Sort_Kkal_Dessert(cake, number_of_desserts);
		break;
	case 4:
		Sort_Bilky_Dessert(cake, number_of_desserts);
		break;
	case 5:
		Sort_Zhyry_Dessert(cake, number_of_desserts);
		break;
	case 6:
		Sort_Carbohydrates_Dessert(cake, number_of_desserts);
		break;
	case 7:
		Sort_Taste_Dessert(cake, number_of_desserts);
		break;
	}
	Print_Dessert(cake, number_of_desserts);

*/