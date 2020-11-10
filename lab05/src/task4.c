int main(){
	#define num 6
	int sum=0;
	char result;
	for(int i=1;i<num;i++){
	if(num%i==0){
	sum += i;
	}}
	if(sum==num)
	result='T';
	else
	result='F';
	return 0;
}
