#include <lib.h>

void test_sort_name(struct Dessert dessert[]) {
	//Dessert* temp = (Dessert*)malloc(3 * sizeof(Dessert));
	struct Dessert temp[] = { {0, "chocolate_cake", 300, {1500, 10, (float)2.3, 4.5}, "solodkiy"}, {1, "friut_cake", 200, {2000, 10,10,10}, "kyslo-solodkiy"}, {1, "jbirthday_cake", 120, {1000, 20, 20, 20}, "solodkyi"} };
	if (memcmp(dessert, temp, 1) == 0) {
		printf("\nPoluchilos sort\n");
	}
	else {
		printf("\n******************\n");
	}
}

void test_read_from_write_file(struct Dessert desserts_expectation[], struct Dessert desserts_result[]) {
	if (memcmp(desserts_expectation, desserts_result, 1) == 0) {
		printf("\nexpectation = write file result\n");
	}
	else {
		printf("\nexpectation != write file result\n");
	}
}

void _test_read_from_file_cookie(struct Dessert desserts[]) {
	struct Dessert expectation[] = { {1, "cookie1", 100, {10, 10, 1, 2}, "kysliy"}, {0, "cookie2", 200, {10, 10, 3, 5}, "solodkiy"} };
	if (memcmp(expectation, desserts, 1) == 0) {
		printf("\nexpectation = result\n");
	}
	else {
		printf("\nexpectation != result\n");
		Print_Dessert(desserts, 2);
		Print_Dessert(expectation, 2);
	}
}

void test_search_by_index_binary_file(struct Dessert dessert_search[]) {
	struct Dessert expectation[1] = { {0, "chocolate cake", 300, {1500, 10, (float)2.3, 4.5}, "solodkiy"} };
	if (memcmp(expectation, dessert_search, 1) == 0) {
		printf("\nozhidanie poiska sovpalo c resultatom\n");
	}
	else {
		printf("\nuhhh\n");
	}
} 

int main(){
    struct Dessert cake[3] = { {1, "jbirthday_cake", 120, {1000, 20, 20, 20}, "solodkyi"}, {0, "chocolate_cake", 300, {1500.0, 10, (float)2.3, 4.5}, "solodkiy"}, {1, "friut_cake", 200, {2000, 10,10,10}, "kyslo-solodkiy"} };
	struct Dessert cookie[2];
	struct Dessert cake_bin[3];
	int index_search = 1;
	char name_file_read[] = "/home/ksen/new_reposit/lab15_17/AllDesserts.txt";
	char name_file_write[] = "/home/ksen/new_reposit/lab15_17/Desserts.txt";
    struct Dessert cake_res[3];
    test_read_from_write_file(cake, Read_From_File(name_file_write, cake_res, 3)); //ok
    
    _test_read_from_file_cookie(Read_From_File(name_file_read, cookie, 2)); //ok
    test_search_by_index_binary_file(Copy_Search_by_Index_in_Binary_File(cake_bin, index_search)); //ok
    Sort_Name_Dessert(cake, 3);
    test_sort_name(cake);

    return 0;
}