int main(){
// чи є число щасливим
	#define num 102003
	int sum1=0, sum2=0, n, kol_vo=6;
	char result;
	for(int i=0;i<kol_vo;i++){ //к-ть разів відпов к-ті цифр у числі
	n=num%10;                  //кожна цифра
	if(i<3)                    //перші три
	sum1 += n;                 //їх сума
	else
	sum2 += n;}                //сума других трьох
	if(sum1==sum2)             //чи є рівними
	result='T';                //якщо так, число щасливе
	else
	result='F';
	return 0;
}
