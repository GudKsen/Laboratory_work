int main()
{
    int  initial_number = 1111;          //задане число
    int first_number=initial_number%10;  //запис у змінну першої цифри і тд
    
    int second_number=(initial_number%100)/10;
    
    int third_number=(initial_number%1000)/100;
    
    int fourth_number=initial_number/1000;
    
    int decimal_number = (first_number*1)+(second_number*2)+(third_number*4)+(fourth_number*8); //перепис числа з двійковой системи у десяткову за допомогою множення на степінь двійки
    return 0;  //binary number into decimal number
}
