int main()
{
    int number=123;   //задане число
    float a = number%10;  //остання цифра
    int b = number/100;  //перша цифра
    float diff= b/a;  //визначення у скільки разів перша більша за останню
    double result = (int)(diff*100)/100.0;   //округлення до двох знаків
    return 0;
}

