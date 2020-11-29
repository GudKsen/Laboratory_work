int main(){
//чи є число сумою своїх дільників
	#define NUMBER 6
	int result;
	result = sum_of_divisors(NUMBER, result);
	return 0;
}

int sum_of_divisors(int num, int result) {
	int sum = 0;
	for(int i = 1; i < num; i++){  //пошук дільників
		if(num % i == 0){            //якщо знайдено
		sum += i;                //їх сумма
		}
	}
	if(sum == num)             //чи дорівнють сумма та число одне одному
		result = 0;              //так
	else
		result = 1;              //ні
	return result;
}
