#include<lib.h>

int main() {
    #define TEXT_OF_SURNAMES "ivanov,petrov,ivanov"
    #define SYMBOL_SURNAMES ","
    char* string_of_surnames = NULL;
    strcpy(string_of_surnames, TEXT_OF_SURNAMES);
    char* symbol_between_surnames = NULL;
    string_of_surnames = SYMBOL_SURNAMES;
    char* array_of_surnames = NULL;
    char* temp_string = NULL;
    temp_string = strtok(string_of_surnames, symbol_between_surnames);
    int size_text = strlen(TEXT_OF_SURNAMES);
    array_of_surnames[0] = *temp_string;
    int count_of_surnames = 0;
   
    for(int i = 1; i < size_text; i++) {
        while(temp_string != NULL) {
            array_of_surnames[i] = *temp_string;
            temp_string = strtok(string_of_surnames, symbol_between_surnames);
            count_of_surnames++;
        }
    }
    char* result_surnames = NULL;
    int g = 0;
    for(int i = 0; i < count_of_surnames; i++) {
        result_surnames[g] = array_of_surnames[i];
        g++;
    }
  
    int flag = 0;
    for(int i = 0; i < size_text; i++) {
        for(int j = i; j < size_text; j++) {
            if(strcmp(&result_surnames[i], &array_of_surnames[j]) && flag == 0) {
                result_surnames[i] = array_of_surnames[j];
                flag++;
            }
        }
        flag = 0;
    }
    return 0;
}