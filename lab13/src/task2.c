#include<lib.h>

int main() {
   /* #define TEXT_OF_SURNAMES "ivanov,petrov,ivanov"
    #define SYMBOL_SURNAMES ","
    int size_text_of_surnames = strlen(TEXT_OF_SURNAMES);
    char* string_of_surnames[size_text_of_surnames];
    strcpy(string_of_surnames, &TEXT_OF_SURNAMES);
    char* symbol_between_surnames = NULL;
    symbol_between_surnames = SYMBOL_SURNAMES;
    char* array_of_surnames[20];
    char* temp_string;
    temp_string = strtok(string_of_surnames, symbol_between_surnames);
    int size_text = strlen(TEXT_OF_SURNAMES);
    
    int count_of_surnames = 0;

    temp_string = strtok(string_of_surnames, symbol_between_surnames);
    array_of_surnames[0] = *temp_string;
    for(int i = 1; i < size_text; i++) {
        while(temp_string != NULL) {
            array_of_surnames[i] = *temp_string; //strcpy
            temp_string = strtok(string_of_surnames, symbol_between_surnames);
            count_of_surnames++;
        }
    }
    char* result_surnames[5];
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
    }*/

    #define TEXT_OF_SURNAMES "ivanov,petrov,ivanov"
    #define SYMBOL_SURNAMES ","
    char * string_of_surnames[5];
    strcpy(string_of_surnames, TEXT_OF_SURNAMES);
    int count_of_surnames = 0;
    
    
    char * part = strtok(string_of_surnames, " .,");
    while(part != NULL) {
        count_of_surnames++;
        part = strtok(NULL, " .,");
        
    }
    int size_text = strlen(TEXT_OF_SURNAMES);
   
   strcpy(string_of_surnames, TEXT_OF_SURNAMES);
   char * part1 = strtok(string_of_surnames, " ,.");
   char array_of_surnames[count_of_surnames][20];
   int i = 1;
   strcpy(array_of_surnames[0], part1);
   while(part1) {
       part1 = strtok(NULL, " ,.");
       strcpy(array_of_surnames[i], part1);
       i++;
   }



    char* result_surnames[5];
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