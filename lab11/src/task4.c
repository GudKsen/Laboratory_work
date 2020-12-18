#include<stdio.h>
#include<stdlib.h>

int main() {
#define STR 5
#define COL 5
	int arr[STR][COL];
	
	int count = 0;

	for (int i = 0; i < STR; i++) {
		for (int j = 0; j < COL; j++) {
			*(*(arr+i)+j) = rand() % 99;
		}
	}

	


	for (int i = 0; i < STR; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == j) {
				count++;
			}
		}
	}
	int* res = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < STR; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == j) {
				*(res+j) = *(*(arr+i)+j);
			}
		}
	}
	
	for(int i = 0; i < count; i++) {
		
			if(*(res + i) < *(res + i + 1)){
				int tmp = *(res + i);
				*(res + i) = *(res + i + 1);
				*(res + i + 1) = tmp;
			}
		
	}
	
	return 0;
}