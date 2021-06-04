#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct NutritVal {
	float kKal;
	float bilky;
	float zhyry;
	float carbohydrates;
};

struct Dessert {
	int is_glucose;
	char *name_dessert;
	float weight;
	struct NutritVal nutrit;
	char *taste;
	struct Dessert* prev;
	struct Dessert* next;
};

struct List {
	struct Dessert* head;
	struct Dessert* tail;
};

