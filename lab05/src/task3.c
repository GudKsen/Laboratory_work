int main(){
	#define num 102003
	int sum1=0, sum2=0, n, kol_vo=6;
	char result;
	for(int i=0;i<kol_vo;i++){
	n=num%10;
	if(i<3)
	sum1 += n;
	else
	sum2 += n;}
	if(sum1==sum2)
	result='T';
	else
	result='F';
	return 0;
}
