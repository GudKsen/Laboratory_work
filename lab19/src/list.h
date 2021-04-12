#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct List* list_new();
void Show_List(struct List* ls);
int List_Delete_El(struct List* ls, int index);
void Search_isGlucose(struct List* ls, int glucose);
void Search_NameDessert(struct List* ls, char* name);
//void sort(struct List* ls);
void Search_Weight(struct List* ls, float weight);
void Write_To_File(char* name_file, struct List* ls);
void Read_From_File(char* name_file, struct List* ls);
struct Dessert* list_new_node(int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste);
int compare(struct Dessert* a, struct Dessert* b);
struct List* sort_ptr(struct List* ls, int(*compare)(struct Dessert*, struct Dessert*));
struct Dessert* list_add_begin(struct List* ls, int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste);
struct Dessert* list_insert(struct List* ls, int index, int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste);
struct Dessert* list_add_end(struct List* ls, int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste);
void Clear_List(struct List* ls);
#endif