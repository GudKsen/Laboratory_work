#include <lib.h>

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
