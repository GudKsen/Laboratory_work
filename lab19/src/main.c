#include "list.h"
#include "data.h"




#define dVIEW_FUNCTION printf("%s\n", __PRETTY_FUNCTION__);



int main() {
	long start_time = currentTimeMillis();
	printf("Please enter the number of elements in list: ");

	struct List* ls = (struct List*)malloc(sizeof(struct List));
    ls->head = NULL;
    ls->tail = NULL;
	char* name_desserts = (char*)malloc(20 * sizeof(char));
	char* taste_desserts = (char*)malloc(20 * sizeof(char));
	strcpy(name_desserts, "cake");
	strcpy(taste_desserts, "solodkiy");

	list_add_end(ls, 1, name_desserts, 500.0, 100.0, 20.0, 30.0, 10.0, taste_desserts);
    printf("\nThe first element is:\n");
	Show_List(ls);

	char* name_add = (char*)malloc(20 * sizeof(char));
	char* taste_add = (char*)malloc(20 * sizeof(char));
	strcpy(name_add, "cheescake");
	strcpy(taste_add, "solodkiy");

	list_add_end(ls, 0, name_add, 200, 100, 10, 10, 10, taste_add);
	printf("\nList after adding:\n");
	Show_List(ls);

	List_Delete_El(ls, 0);
    list_add_end(ls, 1, name_desserts, 400, 200, 35, 27, 10, taste_add);
    char name_file[] = "/home/ksen/new_reposit/lab19/Desserts_list.txt";
	Write_To_File(name_file, ls);
	struct List* l = (struct List*)malloc(sizeof(struct List));
    l->head = NULL;
    l->tail = NULL;
	Read_From_File(name_file, ls);

	Search_Weight(ls, 400);
	Search_NameDessert(ls, name_add);
    char* name_insert = (char*)malloc(20 * sizeof(char));
	strcpy(name_insert, "fruit cake");
	char* taste_insert = (char*)malloc(20 * sizeof(char));
	strcpy(taste_insert, "kysliy");
	list_insert(ls, 1, 1, name_insert, 500, 152, 1, 14, 15, taste_insert);
    printf("Result of adding fruit cake on 0 position:\n");
	Show_List(ls);
    sort_ptr(ls, compare);
    printf("List after sorting by weight:\n");
    Show_List(ls);

	int number_of_elements = 0;
	printf("Enter the number of elements: ");
	scanf("%d", &number_of_elements);
	struct List* list_ = (struct List*)malloc(number_of_elements * sizeof(struct List));
    list_->head = NULL;
    list_->tail = NULL;
	int choice = 1;
	int pos;

	while (choice !=  0) {
		printf("0 - exit\n1 - print list\n2 - add an element to begin\n3 - add an element to end\n4 - insert element\n5 - delete element\n6 - sorting by weight\n\n");
	scanf("%d", &choice);
	
	switch (choice)
	{
	case 1:
		Show_List(list_);
		break;
	case 2:
		list_add_begin(list_, 1, name_desserts, 500.0, 100.0, 20.0, 30.0, 10.0, taste_desserts);
		break;
	case 3:
		list_add_end(list_, 0, name_add, 200, 100, 10, 10, 10, taste_add);
		break;
	case 4:
		printf("Enter the position for inserting: ");
		scanf("%d", &pos);
		list_insert(list_, 1, pos, name_insert, 500, 152, 1, 14, 15, taste_insert);
		break;
	case 5:
		printf("Enter the element's position for deleting: ");
		scanf("%d", &pos);
		List_Delete_El(list_, 0);
		break;
	case 6:
		sort_ptr(list_, compare);
		break;
	default:
		break;
	}
	}
    free(taste_insert);
	free(name_insert);
	free(name_add);
	free(taste_add);
	free(taste_desserts);
	free(name_desserts);
    Clear_List(list_);
	free(list_);
	Clear_List(ls);
    free(ls);

	long end_time = currentTimeMillis();

	#ifdef DEBUG 
	 printf("Spent time: %ld sec\n", (end_time - start_time)/1000);
	 printf("\nDate: %s\n", __DATE__);
	 printf("Time: %s\n", __TIME__);
	 dVIEW_FUNCTION
	#endif

    return 0;
}