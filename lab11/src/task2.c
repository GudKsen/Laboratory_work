#include<stdlib.h>
/**
 * @file task2.c  виконати завдання 2
 * 
 * Знайти безперервну послідовність додатніх чисел у вхідному масиві, сума елементів якої максимальна, та переписати їх у вихідний масив.
*/

/** 
 * @param sum поточна сума
 * @param sum_max максимальна сума
 * @param start_index індекс першого додатнього числа інтервалу
 * @param end_index індекс останнього додатного числа інтервалу
 * @param start_index_max індекс першого додатнього числа інтервалу, сума елементів якого максимальна
 * @param end_index_max індекс останнього додатнього числа інтервалу, сума елементів якого максимальна
 * @param count лічильник кількості елементів інтервалу
 * @param size_of_result_mass розмір нового масиву
*/ 

/**
 * головна функція = {створення масиву та його заповнення випадковими числами,
                      знаходження інтервалу, у якому знаходяться додатні числа та їх сума є максимальна,
                      створення результуючого масиву,
                      перепис додатніх чисел визначеного інтервалу до результуючого масиву }
*/
int main() {
#define N 50
	int mass[N], sum = 0, sum_max = 0, start_index = -1, end_index = -1, start_index_max, end_index_max, count = 0, size_of_result_mass = 0;
	for (int i = 0; i < N; i++) {
		*(mass + i) = rand() % (20 + 20 - 1) - 20;
	}

    for (int i = 0; i < N; i++) {
        if(*(mass + i) >= 0 && start_index == -1){
            start_index = i;
        } 
        else if(*(mass + i) < 0 && start_index != -1){
            end_index = i - 1;
        }

        if(start_index != -1 && end_index != -1){
            for(int j = start_index; j <= end_index; j++) {
                sum += *(mass + j);
                count++;
                if(sum > sum_max){
                sum_max = sum;
                start_index_max = start_index;
                end_index_max = end_index;
                size_of_result_mass = count;
                }
            }
            sum = 0;
            start_index = -1;
            end_index = -1;
            count = 0;
        }
    
        

        
    }

    int* result_mass = ((int*)malloc(size_of_result_mass * sizeof(int)));
	
    int j = start_index_max;
    for(int i = 0; i < size_of_result_mass + 1; i++){
        
        *(result_mass + i) = *(mass + j);
        j++;
    }

    
    return 0;
}
