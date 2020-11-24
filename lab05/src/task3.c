int main(){
// чи є число щасливим
	int num = 102003;
	int sum1=0, sum2=0, n1, n2, kol_vo=6;
	char result;
	
	
	int tmp = 100000;    
	for(int i = 0; i < 3; i++) {
		sum1 += num % 10;
		sum2 += num / tmp;
		num %= tmp;
		tmp /= 100;
		num /= 10;
	}
	
	
	
	if(sum1 == sum2)             //чи є рівними
		result='T';                //якщо так, число щасливе
	else
		result='F';
	
	return 0;
}
