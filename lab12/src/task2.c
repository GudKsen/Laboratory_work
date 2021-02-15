#include <lib.h>
 /**
 * @file task2.c  виконати завдання 2
 * # Індивідуальне завдання
 * 
 * Переробити одну програму на вибір з попередньої роботи. Продемонструвати взаємодію з користувачем шляхом використання функцій gets(), puts().
 * 
*/


/**
 * головна функція = {виклик функції take_numbers_from_string,
                      виклик функції interval_increasing_numbers,
                      створення результуючого масиву,
                      перепис елементу масиву та його частоти до результуючого масиву таким чином - перший елемнт - число, наступний - його частота}
*/
int main() {
    float arr[N2];
    char string[255];
    puts("Input numbers: ");
    gets(&string);

    int count_of_intervals = 0, start_index_max, end_index_max, max_count = 0;
    take_numbers_from_string(string, &arr);
    interval_increasing_numbers(N2, arr, &start_index_max, &end_index_max, &count_of_intervals, &max_count);
    float* result_arr = malloc(max_count * sizeof(float));
	
    for (int i = 0, j = start_index_max; i <= max_count && j <= end_index_max; i++, j++) {
		result_arr[i] = arr[j];
	}
    printf("\n");

    char temp[20];
    char str[20];
    int len;
    printf("Result: ");
    for(int i = 0; i <= max_count; i++) {
        sprintf(temp, "%f", result_arr[i]);
        strcat(str, temp);
        strcat(str, " ");
    }
    printf("\n");
    puts(str);
    printf("\n");
	free(result_arr);
    getchar();
    return 0;
}