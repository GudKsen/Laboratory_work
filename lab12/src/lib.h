#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N2 5

/**
 * Знаходження меж інтервалу, у якому найбільша кількість зростаючих чисел
 * @param size розмір масиву
 * @param arr масив чисел
 * @param start_index_max початкова межа інтервалу
 * @param end_index_max кінцева межа інтервалу
 * @param max_count кількість елементів у інтервалі
*/
void interval_increasing_numbers(int size, float arr[], int *start_index_max, int *end_index_max, int *count_of_intervals, int *max_count);

void take_numbers_from_string(char *string, float arr[]);
void find_repeat(int size, int *num_arr, int *arr, int *repeat);