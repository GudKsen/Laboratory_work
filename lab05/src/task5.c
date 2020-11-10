int main(){
//знайти корінь числа
	#define num 121
	float num_sqrt;
	for(int i=0;i<num/2;i++){//пошук чисел, множення яких дорівнює числу 
	if(i*i==num)             //якщо таке знайдено
	num_sqrt=i;              //то це і є корінь числа
        }
	return 0;
}
