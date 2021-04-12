#include <lib.h>

int main() {
	//insert
	char string1[12] = "abrakadabra";
	char string2[7] = "TXT21";
	unsigned long size = strlen(string1) + strlen(string2) + 1;
	printf("\n");
	free(insert_func_variant(string1, string2, size));
	printf("\n");
	free(insert_iter_variant(string1, string2, size));
	printf("\n");


	//delete
	char original[12] = "abrakadabra";
	int pos_start = 4;
	int pos_end = 8;
	free(delete_elements(original, pos_start, pos_end));
	printf("\n");


	//add
	char words[] = "trylala";
	free(add_element(words));
	printf("\n");


	int size_str = 20;
	struct Dessert* desserts = (struct Dessert*)malloc(sizeof(struct Dessert) * 3);
	desserts->name_dessert = (char*)malloc((unsigned long)size_str * sizeof(char));
	desserts->taste = (char*)malloc((unsigned long)size_str * sizeof(char));
	bool is_glucose_arr[3] = { 1, 0, 1 };
	char name_dessert_arr[3][20] = { "chocolate cake", "fruit cake", "cookie" };
	float weight_arr[3] = { 200, 100, 400 };
	float nutrit_kkal[3] = { 1000, 500, 2500 };
	float nutrit_proteins[3] = { (float)0.2, (float)0.6, (float)0.4 };
	float nutrit_fats[3] = { (float)1.2, (float)1.0, (float)1.6 };
	float nutrit_carbohydrates[3] = { (float)2.5, (float)2.4, (float)2.2 };
	char taste_arr[3][20] = { "solodkiy", "kyslo-solodkiy", "solodkiy" };
	for (int i = 0; i < 3; i++) {
		desserts[i].is_glucose = is_glucose_arr[i];
		desserts[i].name_dessert = name_dessert_arr[i];
		desserts[i].weight = weight_arr[i];
		desserts[i].nutrit.kKal = nutrit_kkal[i];
		desserts[i].nutrit.bilky = nutrit_proteins[i];
		desserts[i].nutrit.zhyry = nutrit_fats[i];
		desserts[i].nutrit.carbohydrates = nutrit_carbohydrates[i];
		desserts[i].taste = taste_arr[i];
	}
	Print_Dessert(desserts, 3);
	
	int position = 1;
	//create cake for insert 
	struct Dessert* cake_insert = (struct Dessert*)malloc(sizeof(struct Dessert));
	cake_insert->name_dessert = (char*)malloc((unsigned long)size_str * sizeof(char));
	cake_insert->is_glucose = 1;
	char cake[20] = { "vanil cake" };
	cake_insert->name_dessert = cake;
	cake_insert->weight = 120;
	cake_insert->nutrit.kKal = 1000;
	cake_insert->nutrit.bilky = (float)0.2;
	cake_insert->nutrit.zhyry = (float)0.3;
	cake_insert->nutrit.carbohydrates = (float)0.4;
	char taste_cake_insert[20] = "solodkiy";
	cake_insert->taste = taste_cake_insert;
	int n = 0;
	struct Dessert* new_array_desserts = (struct Dessert*)malloc(4 * sizeof(struct Dessert));
	//memcpy insert dessert
	for (int i = 0; i < 4; i++) {
		if (i == position) {
			memcpy(new_array_desserts + i, cake_insert, sizeof(struct Dessert));
		}
		else {
			memcpy(new_array_desserts+i, desserts+n, sizeof(struct Dessert));
			n++;
		}
	}
	printf("\n\nInserting dessert via memcpy\n");
	Print_Dessert(new_array_desserts, 4);
	struct Dessert* new_array_desserts_memcpy_delete = (struct Dessert*)malloc(2 * sizeof(struct Dessert));
	//memcpy delete dessert
	n = 0;
	int pos = 1;
	for (int i = 0; i < 3; i++) {
		if (i == pos) {
			continue;
		}
		else {
			memcpy(new_array_desserts_memcpy_delete + n, desserts + i, sizeof(struct Dessert));
			n++;
		}
	}
	printf("\n\nDeleting dessert via memcpy\n");
	Print_Dessert(new_array_desserts_memcpy_delete, 2);
	
	int posdel = 1;
	for (int i = 0; i < 3; i++) {
		if (i == posdel) {
			memset(desserts + i, 0, sizeof(struct Dessert));
		}
		continue;
	}
	printf("\n\nDeleting dessert via memset\n");
	Print_Dessert(desserts, 3);
	return 0;
}