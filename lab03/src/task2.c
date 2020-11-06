int main()
{
    #define R1 2        //перший резистор
    #define R2 7        //другий 
    #define R3 3        //третій
    double sum = ((R1*R2*R3)/(R2*R3+R1*R3+R1*R2)); //сумма опорів
    return 0;
}
