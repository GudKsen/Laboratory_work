#include<stdlib.h>
#include<string.h>
/**
 @file lib.h
*/

/**
 * перепис прізвищ у інший масив без повторень
 * @param array_of_surnames масив прізвищ
 * @param result_surnames результуючий масив прізвищ, у якому немає дублікатів
 * @param count_of_surnames кількість прізвищ
*/
void surnames(char **array_of_surnames, char **result_surnames, int count_of_surnames);

void sort_words(char **array_of_words, int count_of_words);

void find_numbers(char *string_numbers, char *array_of_numbers, int size_numbers);

void all_freq_symb(char *text, int *all_frequency, char *all_symbols, int size);