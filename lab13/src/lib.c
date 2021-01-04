#include<lib.h>
/**
 @file lib.c
*/
void surnames(char **array_of_surnames, char **result_surnames, int count_of_surnames){
    for(int i = 0; i < count_of_surnames; i++) {
        for(int j = i; j < count_of_surnames; j++) {
            for(int k = 0; k < count_of_surnames; k++) {
                if(strcmp(result_surnames[k], array_of_surnames[j]) == 0) {
                    break;
                }
            
                else if(strcmp(result_surnames[k], array_of_surnames[j]) != 0) {
                    strcpy(result_surnames[i], array_of_surnames[j]);
                    
                }
            }
        }
    }
}

void sort_words(char **array_of_words, int count_of_words) {
     char temp[20];
    for(int i = 0; i < count_of_words; i++) {
        for(int j = 0; j < count_of_words - 1; j++) {
            if(strcmp(array_of_words[j], array_of_words[j + 1]) > 0) {
                strcpy(temp, array_of_words[j]);
                strcpy(array_of_words[j], array_of_words[j + 1]);
                strcpy(array_of_words[j + 1], temp);
            }
        }
    }
}

void find_numbers(char *string_numbers, char *array_of_numbers, int size_numbers) {
    int n = 0;
    for(int i = 0; i < size_numbers; i++) {
        if(isdigit(string_numbers[i])) {
            array_of_numbers[n] = string_numbers[i];
            array_of_numbers[n + 1] = ' ';
            n += 2;
        }
    }
}

void all_freq_symb(char *text, int *all_frequency, char *all_symbols, int size) {
    int count = 0;
    char symbol;
    for (int j = 0; j < 255; j++) {
		for (int i = 0; i < size; i++) {
			if (j == (int)text[i]) {
			    count++;
			    symbol = text[i];
			}
		}
		all_frequency[j] = count;
		all_symbols[j] = symbol;
		count = 0;
	}
}