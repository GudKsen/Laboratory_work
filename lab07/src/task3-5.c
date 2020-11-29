int main(){
// чи є число щасливим
	#define NUMBER 102004
	int result;
	result = success_number(NUMBER, result);
	return 0;
}

int success_number(int num, int result) {
	int sum1=0, sum2=0, n1, n2;
	
	n1 = num/1000;
	n2 = num%1000;
	
	for(int i = 0; i < 3; i++) {
		sum1 += n1%10;
		sum2 += n2%10;
		n1 = n1 / 10;
		n2 = n2 / 10;
		
	}
	
	if(sum1==sum2)             //чи є рівними
		result = 0;                //якщо так, число щасливе
	else
		result = 1;
	return result;
}
