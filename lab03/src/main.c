

int main()
{
    #define initial_number 123   //задане число
    
    int first_number=initial_number%10;      //запис останньої цифри заданого числа у змінну(потім воно буде стояти на першому місці)
    int s = initial_number/10;             //перша дія для другого числа(ділимо число на десять, отримаємо 12)
    int second_number=s%10;                //запис другої цифри у змінну(12%10=2)
    int third_number=initial_number/100;   //запис третьої цифри у змінну(вона стане на третє місце)
    
    int inverse_number=(first_number*100)+(second_number*10)+third_number; //3*100+2*10+1(отримаємо зворотнє число)
    
    return 0;
} 
