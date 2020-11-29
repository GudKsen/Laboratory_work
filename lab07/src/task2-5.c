#include <stdbool.h>
int main(){
//чи є задане число простим
	#define NUMBER 124
	int result;
	result = prime(NUMBER, result);
	return 0;
}

int prime(int num, int result){
	for(int i = 2; i < num; i++){
		if(num % i == 0){  //якщо число ділиться на числа окрім 1 та самого себе
		result = 1;    //число не просте
		break;}
	else 
		result = 0;
	}
	return result;
}
