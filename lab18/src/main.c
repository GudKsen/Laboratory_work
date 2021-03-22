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


	//memcpy
	char sentence[] = "have a nice day";
	char tmp[] = "hello";
	int num_of_add_el = (int) strlen(tmp);
	free(add_element_memcpy(sentence, tmp, num_of_add_el));
	printf("\n");

	//memset
	unsigned long size_sentence = strlen(sentence);
	int pos_del_start = 2, pos_del_end = 5;
	int size_del = (int)strlen(sentence) - (pos_del_end - pos_del_start) ; //+1
	free(delete_element_memset(sentence, size_sentence, size_del, pos_del_start, pos_del_end));
	printf("\n");
	return 0;
}