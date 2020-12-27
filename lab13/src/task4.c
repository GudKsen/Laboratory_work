#include<lib.h>

int main() {
    #define TEXT_WITH_NUMBERS "jgb r8 r 4764 83 82 fhrhf 9 r09"
    char array_of_numbers[20];
    char string_numbers[50];
    strcpy(string_numbers, TEXT_WITH_NUMBERS);
    int n = 0;
    while(string_numbers != NULL) {
        for(int i = 0; i < 100; i++) {
            if(isdigit(string_numbers[i])) {
                array_of_numbers[n] = string_numbers[i];
                n++;
            }
        }
        
    }
    return 0;
}