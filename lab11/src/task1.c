#include <stdlib.h>
int main()
{
    #define N  5

	int arr[N] = { 1, 5, 1, 6, 7 };
	int num_arr[N];
	int repeat[N];


	for (int i = 0; i < N; i++) {
		*(num_arr + i) = *(arr + i);
	}

	int count = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (*(num_arr + j) == *(arr + i)) {
				count++;
			}
		}
		*(repeat + j) = count;
		count = 0;
	}

	

	
	int* result_arr = (int*)malloc((N + N) * sizeof(int));
	int i = 0;
		for (int j = 0; j < N; j++) {
			    *(result_arr + i) = *(arr + j);
				*(result_arr + i + 1) = *(repeat + j);
				i += 2;
		}
    
    return 0;
}