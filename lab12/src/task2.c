#include <lib.h>

int main() {
    float arr[N2];
    char string[255];
    puts("Input: ");
    gets(&string);

    int count_of_intervals = 0, start_index_max, end_index_max, max_count = 0;
    take_numbers_from_string(string, &arr);
    interval_increasing_numbers(N2, arr, &start_index_max, &end_index_max, &count_of_intervals, &max_count);
    float* result_arr = (float*)malloc(max_count * sizeof(int));
	
    for (int i = 0, j = start_index_max; i <= max_count && j <= end_index_max; i++, j++) {
		result_arr[i] = arr[j];
	}
    printf("\n");

    char *temp;
    
    char *str;
    /*for(int i = 0; i < max_count; i++) {
        str[i] = malloc(255 * sizeof(char*));
    }*/
    /*int len;
    len = asprintf(&temp, "%g", arr[0]);
    strcpy(str, temp);
    for(int i = 1; i <= max_count; i++) {
       len = asprintf(&temp, "%g", arr[i]);
        if(len != -1) {
            strcat(str, temp);
            strcat(str, ' ');
        } 
    }*/
    printf("\n");
    puts(str);
    printf("\n");
    for (int i = 0, j = start_index_max; i <= max_count && j <= end_index_max; i++, j++) {
		printf("%f ", result_arr[i]);
	}
	free(result_arr);
    getchar();
    return 0;
}