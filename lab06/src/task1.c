
int main()
{
	#define SIZE 15
	char arr[SIZE]={'I','v','a','n','o','v','\0'};
	int count = 0, k = 0, n = 0;

	for(int i = 0; i < SIZE; i++) {                            //кількість символів
		if(arr[i] != 0) {
			count++; }
	}

	k = (SIZE - count) / 2;                            //кількість знаків до та після слова
	n = k + count;


	for(int i = n; i > SIZE - n - k; i--){             //розміщення слова у центрі
		arr[i] = arr[i - k];
	}

	for(int i = 0; i < k; i++){                        //запис знаків по обидва боки від слова
		arr[i] = '_';
		arr[i + n] = '_';
	}
	
	
	return 0;
}
