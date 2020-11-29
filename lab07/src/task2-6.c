int main()
{
	#define SIZE 10
	int arr[SIZE] = {};
	not_repeate(SIZE, arr);
	return 0;
}

void not_repeate(int size, int arr[]) {
	for(int i = 0; i < SIZE; i++) {
		arr[i] = rand() % (100 - 1 + 1) + 1;
	}
	for(int j = 0; j < SIZE; j++) {                    //перевірка на повторення
		for(int i = 0; i < SIZE; i++) {
			if( j == i) continue;
			if( arr[j] == arr[i] ) {
				arr[i] = rand() % (100 - 1 + 1) + 1;
			}
		}
	}
}
