int main()
{
	#define STRING 4
	#define COLUMN 4
	int arr[STRING][COLUMN]={{1, 2, 3, 4}, {5, 6, 7, 8}};
	int kol_vo = 1;
	for(int k = 0; k < kol_vo; k++) {
		for(int i = 0; i < STRING; i++) {
			int tmp = arr[i][0];
			for(int j = 0; j < COLUMN - 1; j++) {
				arr[i][j] = arr[i][j + 1];
			}
			arr[i][COLUMN - 1] = tmp;
		}
	}
	return 0;
}
