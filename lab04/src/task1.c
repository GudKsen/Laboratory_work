int main() {
#define pi 3.14
#define r 2
	char choice;
	double res;
	switch (choice) {                  //оператор для выбора
	case 'l':                          //если выбор l(длина окружности)
		res = 2 * pi*r;            //то результат считается за этой формулой
		break;
	case 's':                          //площадь круга
		res = pi*r*r;            
		break;
	case 'v':                          //объем шара
		res = (4 * pi*r*r*r) / 3;
	}
	return 0;
}
