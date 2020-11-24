int main(){
// чи є число щасливим
	int num = 102003;
	int sum1=0, sum2=0, n1, n2, kol_vo=6;
	char result;
	n1 = num/1000;
	n2 = num%1000;
	
	/*for(int i = 0; i < 3; i++) {
		sum1 += n1%10;
		sum2 += n2%10;
		n1 = n1 / 10;
		n2 = n2 / 10;
		
	}*/
	
	int tmp = 100000;    //ne poluchaetsa schitat s nachala chisla
	for(int i = 0; i < 3; i++) {
		sum1 += num % 10;
		sum2 += num / tmp;
		num %= tmp;
		tmp /= 100;
		num /= 10;
	}
	
	/*for(int i = 0; i < kol_vo; i++) {
		int n = num % 10;
		if(i < 3){
			sum1 += n;
		} else
			sum2 += n;
		num /= 10;
	}*/
	
	if(sum1==sum2)             //чи є рівними
	result='T';                //якщо так, число щасливе
	else
	result='F';
	
	return 0;
}
