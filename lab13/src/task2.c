#include<lib.h>

/**
 * @file task2.c
 *
 * видалення прізвищ, які повторюються
*/


/**
 * @param string_of_surnames копія оригінального рядка
 * @param part зміння для запису відокремлених слів
 * @param array_of_surnames масив прізвищ
 * @param result_surnames результуючий масив
 * @param part2 зміння для запису відокремлених слів(використовується для запису слів у масив)
 * @param count_of_surnames кількість прізвищ
 * @param size_text розмір тексту
*/
int main() {

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
   char ** array_of_surnames = malloc(count_of_surnames * sizeof(char*));
   for(int i = 0; i < count_of_surnames; i++) {
       array_of_surnames[i] = malloc(25 * sizeof(char));
   }
   int i = 0;
  
   while(part1) {
       strcpy(array_of_surnames[i], part1);
       part1 = strtok(NULL, " ,.");
       i++;
   }
    char ** result_surnames = malloc(count_of_surnames * sizeof(char*));
    for(int i = 0; i < count_of_surnames; i++) {
       result_surnames[i] = malloc(25 * sizeof(char));
    }

    surnames(array_of_surnames, result_surnames,count_of_surnames);

    for(int i = 0; i < count_of_surnames; i++) {
        free(result_surnames[i]);
    }
    free(result_surnames);
    for(int i = 0; i < count_of_surnames; i++) {
        free(array_of_surnames[i]);
    }
    free(array_of_surnames);
    return 0;

}