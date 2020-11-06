int main(){
	int a;
        int a_vtoraya_stepen = a * a;                                //
	
	int a_fourth_stepen = a_vtoraya_stepen*a*a;     //а в четвёртой степени за две операции 

	int a_sixth = a_vtoraya_stepen*a_vtoraya_stepen*a*a; //а в шестой степени за три операции(

	int a_eighth = a_fourth_stepen*a_vtoraya_stepen*a*a; //а в восьмой степени за три операции

	int a_tenth = a_fourth_stepen*a_vtoraya_stepen*a_vtoraya_stepen*a*a; //а в десятой степени за четыре операции
	return 0;
}
