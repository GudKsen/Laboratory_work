int main()
{
	#define SIZE 12
	char arr[SIZE] = {'g',' ','f','t',' ',' ','r',' ','q','x','v','j'};
	int count = 1;
	int i = 0;
	while(arr[i] != '\0') {
		if(arr[i] == ' ' && arr[i + 1] != ' ') {
			count ++;
		}
		i ++;
	}
