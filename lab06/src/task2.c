int main()
{
	#define SIZE 10
	int arr[SIZE] = {};
	for(int i = 0; i < SIZE; i++) {
		arr[i] = rand() % (100 - 1 + 1) + 1;
	}
	for(int j = 0; j < SIZE; j++) {
		for(int i = 0; i < SIZE; i++) {
			if( j == i) continue;
			if( arr[j] == arr[i] ) {
				arr[i] = rand() % (100 - 1 + 1) + 1;
			}
		}
	}
	return 0;
}
