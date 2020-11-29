int main(){
	#define num1 1324                //константа 1       
	#define num2 567                 //константа 2
	int res;                //змінні для запису результату та виконання операцій 
	res = nsd(num1, num2, res);
	return 0;
}

int nsd(int num_1, int num_2, int res) {
	int a, b, c;
	a = num_1;                        //запис першого числа у змінну а
	b = num_2;
	if(a>b&&b!=0){                   //якщо а більше за б і остання не =0
       	while(b!=0){                     //виконувати дію поки б не=0
		c = a%b;                         //остача 
		a = b;                           //друге число запис. у перше
		b = c;                           //остачу запис у друге
		res=a;                           //результат = а, бо це остача перед0
	}
        }
	else if(b>a&&a!=0){
		while(a!=0){
		c = b%a;
		b = a;
		a = c;
		res=b;
		}
	}
	return res;
}
