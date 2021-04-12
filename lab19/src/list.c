#include "list.h"
#include "data.h"

struct List* list_new()
{
	struct List* ls = (struct List*)malloc(sizeof(struct List));
	ls->head = NULL;
	ls->tail = NULL;
	return ls;
}

void Show_List(struct List* ls) {
	for (struct Dessert* node = ls->head; node != NULL; node = node->next)
		printf("\t%d %10s %f %f %f %f %f %s\n", node->is_glucose, node->name_dessert, node->weight, node->nutrit.kKal, node->nutrit.bilky, node->nutrit.zhyry, node->nutrit.carbohydrates, node->taste);
	printf("\n");
}

int List_Delete_El(struct List* ls, int index)
{
	if (index < 0)
		return 0;
	struct Dessert* p = ls->head;
	if (index == 0) {
		if (!ls->head)
			return 0;
		ls->head = ls->head->next;
		if (p->next)
			p->next->prev = NULL;
		else
			ls->tail = NULL;
		free(p);
		return 1;
	}
	while (index > 0) {
		if (!p)
			return 0;
		p = p->next;
		index--;
	}
	p->prev->next = p->next;
	if (p->next)
		p->next->prev = p->prev;
	else
		ls->tail = p->prev;
	free(p);
	return 1;
}

void Write_To_File(char* name_file, struct List* ls) {
	FILE* myfile = fopen(name_file, "w");
	if (myfile != NULL) {
		printf("File is opened success for writing!!!\n");
		for (struct Dessert* i = ls->head; i != NULL; i = i->next) {
			fprintf(myfile, "%d %s %f %f %f %f %f %s\n", i->is_glucose, i->name_dessert, i->weight, i->nutrit.kKal, i->nutrit.bilky, i->nutrit.zhyry, i->nutrit.carbohydrates, i->taste);
		}
	}
	else {
		printf("File cannot be opened");
	}
	fclose(myfile);
}

void Read_From_File(char* name_file, struct List* ls) {
	FILE* myfile = fopen(name_file, "r");
	if (myfile != NULL) {
		printf("\nFile opened for reading!!!\n");
        printf("Reading from file:\n");
		for (struct Dessert* i = ls->head; i != NULL; i = i->next) {
			fscanf(myfile, "%d", &i->is_glucose);
			fscanf(myfile, "%s", i->name_dessert);
			fscanf(myfile, "%f", &i->weight);
			fscanf(myfile, "%f", &i->nutrit.kKal);
			fscanf(myfile, "%f", &i->nutrit.bilky);
			fscanf(myfile, "%f", &i->nutrit.zhyry);
			fscanf(myfile, "%f", &i->nutrit.carbohydrates);
			fscanf(myfile, "%s", i->taste);
			printf("\t%d %s %.2f %.2f %.2f %.2f %.2f %s\n", i->is_glucose, i->name_dessert, i->weight, i->nutrit.kKal, i->nutrit.bilky, i->nutrit.zhyry, i->nutrit.carbohydrates, i->taste);

		}
	}
	else {
		printf("File cannot be reading");
	}
	fclose(myfile);
}

void Search_isGlucose(struct List* ls, int glucose) {
	struct List* tmp = list_new();
	for (struct Dessert* node = ls->head; node != NULL; node = node->next) {
		if (node->is_glucose == glucose) {
			free(list_add_end(tmp, node->is_glucose, node->name_dessert, node->weight, node->nutrit.kKal, node->nutrit.bilky, node->nutrit.zhyry, node->nutrit.carbohydrates, node->taste));
			printf("\nResult of searching is glucose:\n");
			Show_List(tmp);
		}
	}
	free(tmp);
}


void Search_NameDessert(struct List* ls, char* name) {
	for (struct Dessert* node = ls->head; node != NULL; node = node->next) {
		if (strcmp(node->name_dessert, name) == 0) {
			struct List* tmp = list_new();
			free(list_add_end(tmp, node->is_glucose, node->name_dessert, node->weight, node->nutrit.kKal, node->nutrit.bilky, node->nutrit.zhyry, node->nutrit.carbohydrates, node->taste));
			printf("\nResult of searching name dessert:\n\t");
			Show_List(tmp);
            free(tmp);
		}
	}
}

void Search_Weight(struct List* ls, float weight) {
	struct List* tmp = list_new();
	for (struct Dessert* node = ls->head; node != NULL; node = node->next) {
		if (node->weight <= weight && weight <= node->weight) {
			free(list_add_end(tmp, node->is_glucose, node->name_dessert, node->weight, node->nutrit.kKal, node->nutrit.bilky, node->nutrit.zhyry, node->nutrit.carbohydrates, node->taste));
			printf("\nResult of searching weight:\n");
			Show_List(tmp);
		}
	}
    free(tmp);
}

int compare(struct Dessert* a, struct Dessert* b) {
	if (a->weight <= b->weight && b->weight <= a->weight)
		return 0;
	else if (a->weight > b->weight)
		return 1;
	else
		return -1;
}
//struct List* sort_ptr(struct List* ls, int(*compare)(struct Dessert*, struct Dessert*));
struct List* sort_ptr(struct List* ls, int(*compare)(struct Dessert*, struct Dessert*))
{
	struct Dessert* set = ls->tail;
	while (set != ls->head)
	{
		struct Dessert* p = ls->head->next;
		struct Dessert* max = ls->head;
		while (p != set->next) {
			if (compare(p, max) >= 0)
				max = p;
			p = p->next;
		}
		if (set == max) {}
		else if (max == ls->head && set == ls->tail) {
			ls->head = set;
			ls->tail = max;
			ls->head->next = ls->tail->next;
			ls->tail->prev = ls->head->prev;
			ls->head->next->prev = ls->head;
			ls->tail->prev->next = ls->tail;
			ls->head->prev = NULL;
			ls->tail->next = NULL;
		}
		else if (max == ls->head) {
			ls->head = set;
			max->prev = ls->head->prev;
			ls->head->prev = NULL;
			max->prev->next = max;
			struct Dessert* t = max->next;
			max->next = ls->head->next;
			ls->head->next = t;
			max->next->prev = max;
			ls->head->next->prev = ls->head;
		}
		else if (set == ls->tail) {
			ls->tail = max;
			set->next = ls->tail->next;
			ls->tail->next = NULL;
			set->next->prev = set;
			struct Dessert* t = set->prev;
			set->prev = ls->tail->prev;
			ls->tail->prev = t;
			set->prev->next = set;
			ls->tail->prev->next = ls->tail;
		}
		else {
			struct Dessert* t = max->next;
			max->next = set->next;
			set->next = t;
			max->next->prev = max;
			set->next->prev = set;
			t = max->prev;
			max->prev = set->prev;
			set->prev = t;
			max->prev->next = max;
			set->prev->next = set;
		}
		set = max->prev;
	}
	return ls;
}

struct Dessert* list_new_node(int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste)
{
	struct Dessert* node = (struct Dessert*)malloc(sizeof(struct Dessert));
	node->is_glucose = a;
	node->name_dessert = name;
	node->weight = weight;
	node->nutrit.kKal = kkal;
	node->nutrit.bilky = proteins;
	node->nutrit.zhyry = fats;
	node->nutrit.carbohydrates = carbohydrates;
	node->taste = taste;
	node->next = NULL;
	node->prev = NULL;
	return node;
}



struct Dessert* list_add_begin(struct List* ls, int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste)
{
	struct Dessert* node = list_new_node(a,  name, weight,  kkal, proteins, fats, carbohydrates, taste);
	node->next = ls->head;
	if (ls->head)
		ls->head->prev = node;
	else
		ls->tail = node;
	ls->head = node;
	return node;
}

struct Dessert* list_insert(struct List* ls, int index, int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste){
	if (index <= 0) {
		//list_add_begin(ls, a,  name,  weight,  kkal,  proteins,  fats,  carbohydrates,  taste);
		return list_add_begin(ls, a, name, weight, kkal, proteins, fats, carbohydrates, taste);
	}

	struct Dessert* p = ls->head;
	while (index > 0) {
		if (!p) {
			//list_add_end(ls, a,  name,  weight,  kkal,  proteins,  fats,  carbohydrates,  taste);
			return list_add_end(ls, a, name, weight, kkal, proteins, fats, carbohydrates, taste);
		}
		p = p->next;
		index--;
	}
	struct Dessert* node = list_new_node(a,  name,  weight,  kkal,  proteins,  fats,  carbohydrates,  taste);
	node->prev = p->prev;
	node->next = p;
	node->prev->next = node;
	node->next->prev = node;
	return node;
}

struct Dessert* list_add_end(struct List* ls, int a, char* name, float weight, float kkal, float proteins, float fats, float carbohydrates, char* taste)
{
	struct Dessert* node = list_new_node(a, name, weight, kkal, proteins, fats, carbohydrates, taste);

	node->prev = ls->tail;
	if (ls->tail)
		ls->tail->next = node;
	else
		ls->head = node;
	ls->tail = node;
	return node;
}

void Clear_List(struct List* ls){
	while (ls->head) {
        struct Dessert *ptr = ls->head;
        ls->head = ptr->next;
        free(ptr);
	}
}