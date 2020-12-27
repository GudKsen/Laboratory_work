#include<lib.h>

int main() {
    #define TEXT_WITH_NUMBERS "jgb r8 r 4764 83 82 fhrhf 9 r09"
    int array_of_numbers[100];
    char* string_numbers = NULL;
    strcpy(string_numbers, *TEXT_WITH_NUMBERS);
    while(string_numbers != NULL) {
        for(int i = 0; i < 100; i++) {
            if(isdigit(*string_numbers)) {
                array_of_numbers[i] = atoi(isdigit(*string_numbers));
            }
        }
        
    }
    return 0;
}