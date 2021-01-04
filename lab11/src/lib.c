#include<lib.h>
/**
 @file lib.c
*/

/**
 task1
*/
void find_repeat(int size, int *num_arr, int *arr, int *repeat) {
    int count = 0;
    for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			if (*(num_arr + j) == *(arr + i)) {
				count++;
			}
		}
		*(repeat + j) = count;
		count = 0;
	}
}

int create_array(int size, int arr[]){
    for (int i = 0; i < size; i++) {
		    *(arr + i) = rand() % (20 + 20 - 1) - 20;
	}
    return *arr;
}

void create_array_2(int size, float *arr){                                                                                                 
    for (int i = 0; i < size; i++) {
		    *(arr + i) =  (float) rand() / (20 + 20 - 1) - 20; 
           
	}
}
                       

void sort_array4(int size, int arr[]){
    for(int j = 0; j < size; j++) {
       for(int i = 0; i < size; i++) {
		    if(*(arr + i) < *(arr + i + 1)){                                                                                                               
				int tmp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = tmp;
			}
		} 
    }
    
}

/**
 * task2
*/
void index_of_interval_positive_numbers(int size, int arr[], int *start_index_max, int *end_index_max, int *size_of_result_mass){
    int sum = 0, sum_max = 0, start_index = -1, end_index = -1, count = 0;
    for (int i = 0; i < size; i++) {
        if(*(arr + i) >= 0 && start_index == -1){
            start_index = i;
        } 
        else if(*(arr + i) < 0 && start_index != -1){
            end_index = i - 1;
        }

        if(start_index != -1 && end_index != -1){
            for(int j = start_index; j <= end_index; j++) {
                sum += *(arr + j);
                count++;
                if(sum > sum_max){
                sum_max = sum;
                *start_index_max = start_index;
                *end_index_max = end_index;
                *size_of_result_mass = count;
                }
            }
            sum = 0;
            start_index = -1;
            end_index = -1;
            count = 0;
        }
    }
}
    
/**
 * task3
*/
    void interval_increasing_numbers(int size, float arr[], int *start_index_max, int *end_index_max, int *count_of_intervals, int *max_count) {
        int count = 1, start_index = -1, end_index = -1;
        for(int i = 0; i < size; i++){
        if(*(arr + i) < *(arr + i + 1) && end_index == -1 && start_index == -1){
            start_index = i;
        }
        else if(*(arr + i) > *(arr + i + 1) && start_index != -1){
            end_index = i;
        }

        if(start_index != -1 && end_index != -1){
            count = end_index - start_index;
            *count_of_intervals++;
            if(count > *max_count){
                *max_count = count;
                *start_index_max = start_index;
                *end_index_max = end_index;
            }
        start_index = -1;
        end_index = -1;
        count = 1; }
        
        }
        max_count += 1;
    }

/**
 task4
*/
void main_diagonal(int str, int col, int *line_arr, int *res) {
    int matrix[str][col];
  
   int k = 0;
   for (int i = 0; i < str; i++) {
       for(int j = 0; j < col; j++) {
           *(*(matrix + i) + j) = *(line_arr + k);
           k++;
       }
   }
   
    for (int i = 0; i < str; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j) {
				*(res+j) = *(*(matrix + i) + j);
			}
		}
	}
}
