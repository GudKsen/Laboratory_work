int main(){
//знайти корінь числа
	#define NUMBER 121
	int num_sqrt;
	num_sqrt = sqrt_of_number(NUMBER, num_sqrt);
	return 0;
}

int sqrt_of_number(int num, int num_sqrt) {
	
	for (int i = 0;i < num / 2; i++){//пошук чисел, множення яких дорівнює числу 
		if (i * i == num)             //якщо таке знайдено
		num_sqrt = i;              //то це і є корінь числа
    }
	return num_sqrt;
}
