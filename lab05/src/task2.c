int main(){
//чи є задане число простим
	#define num 124
	char result;
	for(int i = 2; i < num; i++){
		if(num % i == 0){  //якщо число ділиться на числа окрім 1 та самого себе
		result ='F';    //число не просте
		break;}
	else 
		result ='T';
	}
	return 0;
}
