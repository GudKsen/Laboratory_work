#include<stdlib.h>
int main() {
#define N 50
	float arr[N];
	int count = 1, max_count = 0, start_index = -1, end_index = -1, count_of_intervals = 0, start_index_max, end_index_max;
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % (20 + 20 - 1) - 20;
	}


	
    for(int i = 0; i < N; i++){
        if(*(arr + i) < *(arr + i + 1) && end_index == -1 && start_index == -1){
            start_index = i;
        }
        else if(*(arr + i) > *(arr + i + 1) && start_index != -1){
            end_index = i;
        }

        if(start_index != -1 && end_index != -1){
            count = end_index - start_index;
            if(count > max_count){
                max_count = count;
                start_index_max = start_index;
                end_index_max = end_index;
            }
        start_index = -1;
        end_index = -1;
        count = 1; }
        
    }
    
    
    
    
  

	float* result_arr = (float*)malloc(max_count * sizeof(int));
	for (int i = 0, j = start_index_max; i < max_count && j < end_index_max; i++, j++) {
		result_arr[i] = arr[j];
	}

	
	return 0;
}

