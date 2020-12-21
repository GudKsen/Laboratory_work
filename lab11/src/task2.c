#include<lib.h>
/**
 * @file task2.c  виконати завдання 2
 * 
 * Знайти безперервну послідовність додатніх чисел у вхідному масиві, сума елементів якої максимальна, та переписати їх у вихідний масив.
*/


/**
 * головна функція = {виклик функції create_array,
                      виклик функції index_of_interval_positive_numbers,
                      створення результуючого масиву,
                      перепис додатніх чисел визначеного інтервалу до результуючого масиву }
*/
int main() {
#define N 50
	int mass[N], start_index_max, end_index_max, size_of_result_mass = 0;
	
    create_array(N, mass);
    index_of_interval_positive_numbers(N, &mass, &start_index_max, &end_index_max, &size_of_result_mass);
    
    int* result_mass = ((int*)malloc(size_of_result_mass * sizeof(int)));
	
    int j = start_index_max;
    for(int i = 0; i < size_of_result_mass + 1; i++){
        *(result_mass + i) = *(mass + j);
        j++;
    }

    free(result_mass);
    return 0;
}
