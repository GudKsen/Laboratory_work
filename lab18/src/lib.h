#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct NutritVal {
	float kKal;
	float bilky;
	float zhyry;
	float carbohydrates;
};

struct Dessert {
	bool is_glucose;
	char* name_dessert;
	float weight;
	struct NutritVal nutrit;
	char *taste;
};

void testing_insert_func_variant(char* result_of_func);
void testing_insert_iter_variant(char* result_of_func);
//void testing_add_element_memcpy(char* result_of_func);
void testing_delete_elements(char* result_of_func);
void testing_add_element(char* result_of_func);
//void testing_delete_element_memset(char* result_of_func);

char* insert_func_variant(char* string1, char* string2, unsigned long size);
char* insert_iter_variant(char* string1, char* string2, unsigned long size);
//char* add_element_memcpy(char* sentence, char* tmp, int num_of_add_el);
char* delete_elements(char* original, int pos_start, int pos_end);
char* add_element(char* slova);
//char* delete_element_memset(char* sentence, unsigned long size_sentence, int size_del, int pos_del_start, int pos_del_end);

void Print_Dessert(struct Dessert desserts[], int number_of_desserts);
void Print_NutritVal(struct NutritVal desserts);
