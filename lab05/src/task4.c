int main(){
//чи є число сумою своїх дільників
	#define num 6
	int sum = 0;
	char result;
	for(int i = 1; i < num; i++){  //пошук дільників
		if(num % i == 0){            //якщо знайдено
		sum += i;                //їх сумма
		}
	}
	if(sum == num)             //чи дорівнють сумма та число одне одному
		result ='T';              //так
	else
		result ='F';              //ні
	return 0;
}
