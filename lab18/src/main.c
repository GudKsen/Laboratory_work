#include <lib.h>

int main() {
	//insert
	char string1[12] = "abrakadabra";
	char string2[7] = "TXT21";
	unsigned long size = strlen(string1) + strlen(string2) + 1;
	
	insert_func_variant(string1, string2, size);
	insert_iter_variant(string1, string2, size);


	//delete
	char original[12] = "abrakadabra";
	int pos_start = 4;
	int pos_end = 8;
	delete_elements(original, pos_start, pos_end);


	//add
	char slova[] = "trylala";
	add_element(slova);


	//memcpy
	char sentence[] = "chto popalo";
	
	
	char tmp[] = "helo";
	int num_of_add_el = (int) strlen(tmp);
	add_element_memcpy(sentence, tmp, num_of_add_el);
	
	//memset
	unsigned long size_sentence = strlen(sentence);
	int pos_del_start = 2, pos_del_end = 5;
	int size_del = (int)strlen(sentence) - (pos_del_end - pos_del_start) ; //+1
	delete_element_memset(sentence, size_sentence, size_del, pos_del_start, pos_del_end);
	return 0;
}