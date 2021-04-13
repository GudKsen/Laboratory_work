#include "list.h"
#include "data.h"
#define dVIEW_FUNCTION printf("\n%s\n", __PRETTY_FUNCTION__);
struct Dessert* Search_Weight1(struct List* ls, float weight) {
	struct List* tmp = list_new();
	struct Dessert* t = (struct Dessert*)malloc(sizeof(struct Dessert));
	for (struct Dessert* node = ls->head; node != NULL; node = node->next) {
		if (node->weight <= weight && weight <= node->weight) {
			list_add_end(tmp, node->is_glucose, node->name_dessert, node->weight, node->nutrit.kKal, node->nutrit.bilky, node->nutrit.zhyry, node->nutrit.carbohydrates, node->taste);
			t = list_new_node(node->is_glucose, node->name_dessert, node->weight, node->nutrit.kKal, node->nutrit.bilky, node->nutrit.zhyry, node->nutrit.carbohydrates, node->taste);
		}
	}
    free(tmp);
    return t;
}

void Test_Insert(struct Dessert* result) {
	char* name_insert = (char*)malloc(20 * sizeof(char));
	strcpy(name_insert, "fruit cake");
	char* taste_insert = (char*)malloc(20 * sizeof(char));
	strcpy(taste_insert, "kysliy");
	struct Dessert* expectation = list_new_node(1, name_insert, 500, 152, (float)1.30, 14, 15, taste_insert);
	if (memcmp(expectation, result, 1) == 0) {
		printf("expectation insert == result\n");
	}
	dVIEW_FUNCTION
}

void Test_Del(struct Dessert* result) {
	dVIEW_FUNCTION
	struct Dessert* exp = (struct Dessert*)malloc(sizeof(struct Dessert));
	char* name = (char*)malloc(20 * sizeof(char));
	strcpy(name, "cheescake");
	char* taste = (char*)malloc(20 * sizeof(char));
	strcpy(taste, "solodkiy");
	exp = list_new_node(0,  name, 200.000000, 100.000000, 10.000000, 10.000000, 10.000000, taste);
	if (memcmp(exp, result, 1) == 0) {
		printf("expectation delete == result\n");
	}
	else {
		printf("no\n");
	}
}

void Test_Search_Weight(struct Dessert* result) {
	dVIEW_FUNCTION
	struct Dessert* exp = (struct Dessert*)malloc(sizeof(struct Dessert));
	char* name_desserts = (char*)malloc(20 * sizeof(char));
	char* taste_dessert = (char*)malloc(20 * sizeof(char));
	strcpy(name_desserts, "cake");
	strcpy(taste_dessert, "solodkiy");
	exp = list_new_node(1, name_desserts, 400, 200, 35, 27, 10, taste_dessert);
	if (memcmp(exp, result, 1) == 0) {
		printf("expectation searching weight == result\n");
	}
	else {
		printf("jjjjjjjjjjjjjjjjjjjjjjjjh\n");
	}
}

void Test_Sort(struct List* ls, struct Dessert* result) {
	dVIEW_FUNCTION
	struct List* expectation = list_new();
	struct Dessert* exp = (struct Dessert*)malloc(3 * sizeof(struct Dessert));
	char* exp_name = (char*)malloc(20 * sizeof(char));
	strcpy(exp_name, "cheescake");
	char* exp_taste = (char*)malloc(20 * sizeof(char));
	strcpy(exp_taste, "solodkiy");
	list_add_end(expectation, 0, exp_name, 200, 100, 10, 10, 10, exp_taste);
	exp = list_new_node(0, exp_name, 200, 100, 10, 10, 10, exp_taste);

	char* name_desserts = (char*)malloc(20 * sizeof(char));
	char* taste_desserts = (char*)malloc(20 * sizeof(char));
	strcpy(name_desserts, "cake");
	strcpy(taste_desserts, "solodkiy");
	list_add_end(expectation, 1, name_desserts, 400, 200, 35, 27, 10, taste_desserts);
	exp->next = list_new_node(1, name_desserts, 400, 200, 35, 27, 10, taste_desserts);

	char* name_insert = (char*)malloc(20 * sizeof(char));
	strcpy(name_insert, "fruit cake");
	char* taste_insert = (char*)malloc(20 * sizeof(char));
	strcpy(taste_insert, "kysliy");
	list_add_end(expectation, 1, name_insert, 500, 152, 1, 14, 15, taste_insert);
	exp->next->next = list_new_node(1, name_insert, 500, 152, 1, 14, 15, taste_insert);
	if (memcmp(exp, result, 1) == 0) {
		printf("expectation sort == result\n");
	}
	else {
		printf("no\n");
		Show_List(ls);
		Show_List(expectation);
	}
	free(taste_insert);
	free(name_insert);
	free(taste_desserts);
	free(name_desserts);
	free(exp_taste);
	free(exp_name);
	
} 

int main() {
	int n;
	printf("Please enter the number of elements in list: ");
	scanf("%d", &n);
	struct List* ls = list_new();
	char* name_desserts = (char*)malloc(20 * sizeof(char));
	char* taste_desserts = (char*)malloc(20 * sizeof(char));
	strcpy(name_desserts, "cake");
	strcpy(taste_desserts, "solodkiy");

	list_add_end(ls, 1, name_desserts, 500, 100, 20, 30, 10, taste_desserts);

	char* name_add = (char*)malloc(20 * sizeof(char));
	char* taste_add = (char*)malloc(20 * sizeof(char));
	strcpy(name_add, "cheescake");
	strcpy(taste_add, "solodkiy");

	list_add_end(ls, 0, name_add, 200, 100, 10, 10, 10, taste_add);

	List_Delete_El(ls, 0);
	struct Dessert* del_test = (struct Dessert*)malloc(sizeof(struct Dessert));
	del_test = ls->head;
	del_test->next = ls->head->next;
	long start_time = currentTimeMillis();
	Test_Del(del_test);
	long end_time = currentTimeMillis();
	printf("\nSpent time: %ld sec\n", (end_time - start_time)/1000);

    list_add_end(ls, 1, name_desserts, 400, 200, 35, 27, 10, taste_add);
    char name_file[] = "/home/ksen/new_reposit/lab19/Desserts_list.txt";

	Write_To_File(name_file, ls);
	Read_From_File(name_file, ls);

	Search_Weight1(ls, 400);
	start_time = currentTimeMillis();
	Test_Search_Weight(Search_Weight1(ls, 400));
	end_time = currentTimeMillis();
	printf("\nSpent time: %ld sec\n", (end_time - start_time)/1000);
    char* name_insert = (char*)malloc(20 * sizeof(char));
	strcpy(name_insert, "fruit cake");
	char* taste_insert = (char*)malloc(20 * sizeof(char));
	strcpy(taste_insert, "kysliy");
	list_insert(ls, 1, 1, name_insert, 500, 152, 1, 14, 15, taste_insert);
   
    sort_ptr(ls, compare);
    struct Dessert* temp = (struct Dessert*)malloc(sizeof(struct Dessert));
	temp = ls->head;
	temp->next = ls->head->next;
	temp->next->next = ls->tail;


	start_time = currentTimeMillis();
	Test_Sort(ls, temp);
	end_time = currentTimeMillis();
	printf("\nSpent time: %ld sec\n", (end_time - start_time)/1000);
	printf("\nDate: %s\n", __DATE__);
	printf("Time: %s\n", __TIME__);
	 
    free(taste_insert);
	free(name_insert);
	free(name_add);
	free(taste_add);
	free(taste_desserts);
	free(name_desserts);
    free(ls);
    return 0;
}

