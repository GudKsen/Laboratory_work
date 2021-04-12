#include "list.h"
#include "data.h"

#define dVIEW_FUNCTION printf("%s\n", __PRETTY_FUNCTION__);


/*long currentTimeMillis() {  
	struct timeval time;   
	gettimeofday(&time, NULL); //note: how c functions returns structures !   
	return time.tv_sec * 1000 + time.tv_usec / 1000;
}*/

//#define DEBUG 1


int main() {
	//long start_time = currentTimeMillis();
    int n;
	printf("Please enter the number of elements in list: ");
	scanf("%d", &n);
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
    free(taste_insert);
	free(name_insert);
	free(name_add);
	free(taste_add);
	free(taste_desserts);
	free(name_desserts);
   
	Clear_List(ls);
    free(ls);

	//long end_time = currentTimeMillis();
	/*#ifdef DEBUG 
	#define PRINT printf("Spent time: %d sec\n", (end_time - start_time)/1000);
	#define PRINTD printf("\nDate: %s\n", __DATE__);
	#define PRINTT printf("Time: %s\n", __TIME__);
	#define dVIEW_FUNCTION
	#endif*/
	//printf("Spent time: %ld sec\n", (end_time - start_time)/1000);
	printf("\nDate: %s\n", __DATE__);
	printf("Time: %s\n", __TIME__);
	dVIEW_FUNCTION
    return 0;
}