#include<lib.h>

int main() {
    #define TEXT_WITH_NUMBERS "jgb r8 r 4764 83 82 fhrhf 9 r09"
    int size_numbers = strlen(TEXT_WITH_NUMBERS) + 1;
    char *array_of_numbers = malloc(20 * sizeof(char));
    char *string_numbers = malloc(size_numbers * sizeof(char));
    strcpy(string_numbers, TEXT_WITH_NUMBERS);
    find_numbers(string_numbers, array_of_numbers, size_numbers);
    free(array_of_numbers);
    return 0;
}