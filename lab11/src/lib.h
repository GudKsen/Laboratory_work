#include<stdlib.h>
/**
 @file lib.h
*/

void find_repeat(int size, int *num_arr[], int *arr[], int *repeat[]);

void sort_array4(int size, int arr[]);
int create_array(int size, int arr[]);
void create_array_2(int size, float arr[]);
/**
 * Отриманння індексів - меж інтервалу, у якому сума елементів максимальна
 * @param sum поточна сума
 * @param sum_max максимальна сума
 * @param start_index індекс першого додатнього числа інтервалу
 * @param end_index індекс останнього додатного числа інтервалу
 * @param start_index_max індекс першого додатнього числа інтервалу, сума елементів якого максимальна
 * @param end_index_max індекс останнього додатнього числа інтервалу, сума елементів якого максимальна
 * @param count лічильник кількості елементів інтервалу
 * @param size_of_result_mass розмір нового масиву
*/
void index_of_interval_positive_numbers(int size, int arr[], int *start_index_max, int *end_index_max, int *size_of_result_mass);


void interval_increasing_numbers(int size, float arr[], int *start_index_max, int *end_index_max, int *count_of_intervals, int *max_count);

void main_diagonal(int str, int col, int *line_arr, int *res);

