#include <lib.h>

int main() {
    char arr[N2];
    int start_index_max, end_index_max, count_of_intervals = 0, max_count = 0;
    int arr_num[N2];
    int copy_arr_num[N2];
    int repeat[N2];
    printf("Input numbers: ");
    for(int i = 0; i < N2; i++) {
        arr[i] = getc(stdin);
    }
     printf("\n");
    
    for(int i = 0; i < N2; i++) {            //char => int
        arr_num[i] = arr[i] - '0';
    }
    for (int i = 0; i < N2; i++) {            //coping
		*(copy_arr_num + i) = *(arr_num + i);
	}
    find_repeat(N2, &copy_arr_num, arr_num, &repeat);
    int* result_arr = (int*)malloc((N2 + N2) * sizeof(int));
	
	int i = 0;
	for (int j = 0; j < N2; j++) {
		*(result_arr + i) = *(arr_num + j);
		*(result_arr + i + 1) = *(repeat + j);
		i += 2;
	}
    printf("\n");
    char *char_result_arr = malloc(N2*2 * sizeof(char));
    for(int i = 0; i < N2*2; i++) {
        char_result_arr[i] = result_arr[i] + '0';
        printf(" ");
        putc(char_result_arr[i], stdout);
    }
	free(result_arr);
    printf("\n");
    return 0;
}