#include<lib.h>
int main() {
#define N2 50
	float arr[N2];
	int count_of_intervals = 0, start_index_max, end_index_max, max_count = 0;
	
    create_array_2(N2, &arr);
    

    interval_increasing_numbers(N2, arr, &start_index_max, &end_index_max, &count_of_intervals, &max_count);
	
    float* result_arr = (float*)malloc(max_count * sizeof(int));
	
    for (int i = 0, j = start_index_max; i < max_count && j < end_index_max; i++, j++) {
		result_arr[i] = arr[j];
	}

	free(result_arr);
	return 0;
}

