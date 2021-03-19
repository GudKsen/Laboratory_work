#include <lib.h>
/*void testing_insert_func_variant(char* result_of_func) {
	char expectation_func_variant[] = "abraTXT21kadabra";
	if (strcmp(expectation_func_variant, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_func_variant);
		puts(result_of_func);
	}
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
}

void testing_add_element_memcpy(char* result_of_func) {
	char expectation_add_element_memcpy[] = "chtohelo popalo";
	if (strcmp(expectation_add_element_memcpy, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_add_element_memcpy);
		puts(result_of_func);
	}
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
}

void testing_delete_element_memset(char* result_of_func) {
	char expectation_delete_element_memset[] = "chtpopalo";
	if (strcmp(expectation_delete_element_memset, result_of_func) == 0) {
		printf("Expectation with the result of the function coincided.\n");
	}
	else {
		printf("Expectation with the result of the function not coincided.\n");
		puts(expectation_delete_element_memset);
		puts(result_of_func);
	}
}*/



char* insert_func_variant(char* string1, char* string2, unsigned long size) {
	char* result2 = (char*)malloc(size * sizeof(char));
	for (unsigned long i = 0; i < size; i++) {
		result2[i] = 0;
	}
	strncpy(result2, string1, 4);
	strncpy(result2 + 4, string2, strlen(string2));
	strncpy(result2 + 4 + strlen(string2), string1 + 4, 7);
	printf("Result of inserting string: ");
	puts(result2);
    return result2;
}

char* insert_iter_variant(char* string1, char* string2, unsigned long size) {
	char* cp_str1 = string1;
	char* cp_str2 = string2;
	int pos = 4;
	char* result_string = (char*)malloc(size * sizeof(char));

    int num_of_pos = pos + (int)strlen(string2);
	int ir = 0, istr = 0, isd = 0;
	while (size != 0) {
		result_string[ir] = cp_str1[istr];
		if (ir >= pos && ir < num_of_pos) {
			result_string[ir] = cp_str2[isd];
			isd++;
			istr = pos - 1;
		}
		istr++;
		ir++;
		size--;
	}
	printf("%s", "Result of inserting via iteration: ");
	puts(result_string);
    return result_string;
}

char* add_element_memcpy(char* sentence, char* tmp, int num_of_add_el) {
	int posit_add_start = 4;
	int posit_add_end = 0;

	posit_add_end = posit_add_start + num_of_add_el;
	int adding_space = num_of_add_el;

	int size1 = (int)strlen(sentence) + adding_space + 1;

	char* res = (char*)malloc((unsigned long)size1 * sizeof(char));
	for (int i = 0; i < size1; i++) {
		res[i] = 0;
	}
	memcpy(res, sentence, (unsigned long) posit_add_start);
	memcpy(res + posit_add_start, tmp, strlen(tmp) + 1);
	memcpy(res + adding_space + posit_add_start, sentence + posit_add_start, strlen(sentence) - (unsigned long) posit_add_start);
	printf("Result memcpy: ");
	printf("%s\n", res);
    return res;
}

char* delete_elements(char* original, int pos_start, int pos_end) {
	char* result_delete = (char*)malloc((strlen(original) - 5 + 1) * sizeof(char));

	strncpy(result_delete, original, (unsigned long) pos_start);
	strncpy(result_delete + pos_start, original + pos_end + 1, 3);
	printf("Result of deleting elements: ");
	puts(result_delete);
    return result_delete;
}

char* add_element(char* slova) {
	char* n_slova = (char*)malloc(12 * sizeof(char));
	for (int i = 0; i < 12; i++) {
		n_slova[i] = 0;
	}
	memcpy(n_slova, slova, strlen(slova) + 1);
	memcpy(n_slova + strlen(slova), "Cv", 2);
	printf("Result of adding element: ");
	printf("%s\n", n_slova);
    return n_slova;
}

char* delete_element_memset(char* sentence, unsigned long size_sentence, int size_del, int pos_del_start, int pos_del_end) {
	char* result_delete_memset = (char*)malloc((unsigned long)size_del * sizeof(char));
	for (int i = 0; i < size_del; i++) {
		result_delete_memset[i] = 0;
	}
	int j = 0;
	for (int i = 0; i <= (int) size_sentence; i++) {
		if (i > pos_del_start && i < pos_del_end) {
			continue;
		}
		else {
			memset(result_delete_memset + j, sentence[i], 1);
			j++;
		}
	}

	printf("Result of deleting via memset: %s\n", result_delete_memset);
    return result_delete_memset;
}

