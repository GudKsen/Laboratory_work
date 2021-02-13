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

void take_numbers_from_string(char *string, float arr[]) {
    int n = 0;
    char* tmp = strtok(string, " "); 
    char ** array_str = malloc(N2 * sizeof(char*));
    for(int i = 0; i < N2; i++) {
       array_str[i] = malloc(25 * sizeof(char));
    }
    while (tmp) {
        strcpy(array_str[n], tmp);
        tmp = strtok(NULL, " ");
        n++;
    }

    for(int i = 0; i < N2; i++) {
        arr[i] = atof(array_str[i]);
    }
    for (int i = 0; i < N2; i++) {
        printf("%f ", arr[i]);
    }
    for(int i = 0; i < N2; i++) {
        free(array_str[i]);
    }
    free(array_str);
}

