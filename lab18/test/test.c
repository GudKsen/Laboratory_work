#include <lib.h>
void testing_insert_func_variant(char* result_of_func) {
	char expectation_func_variant[] = "abraTXT21kadabra";
	if (strcmp(expectation_func_variant, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_func_variant);
		puts(result_of_func);
	}
	free(result_of_func);
}

void testing_insert_iter_variant(char* result_of_func) {
	char expectation_iter_variant[] = "abraTXT21kadabra";
	if (strcmp(expectation_iter_variant, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_iter_variant);
		puts(result_of_func);
	}
	free(result_of_func);
}


void testing_delete_elements(char* result_of_func) {
	char expectation_delete_element[] = "abrara";
	if (strcmp(expectation_delete_element, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_delete_element);
		puts(result_of_func);
	}
	free(result_of_func);
}

void testing_add_element(char* result_of_func) {
	char expectation_add_element[] = "trylalaCv";
	if (strcmp(expectation_add_element, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_add_element);
		puts(result_of_func);
	}
	free(result_of_func);
}



int main(){
    //insert
	char string1[12] = "abrakadabra";
	char string2[7] = "TXT21";
	unsigned long size = strlen(string1) + strlen(string2) + 1;
	
    testing_insert_iter_variant(insert_iter_variant(string1, string2, size));
	printf("\n\n");
	
    testing_insert_func_variant(insert_func_variant(string1, string2, size));
    printf("\n\n");

	//delete
	char original[12] = "abrakadabra";
	int pos_start = 4;
	int pos_end = 8;
	testing_delete_elements(delete_elements(original, pos_start, pos_end));
    printf("\n\n");

	//add
	char slova[] = "trylala";
	testing_add_element(add_element(slova));
    printf("\n\n");

	

	
    printf("\n\n");
    return 0;
}
