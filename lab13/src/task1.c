#include<lib.h>

int main() {
   /* #define TEXT  "gf jhgjsd skdjgfj djgfb kfh"
    #define SYMBOL  ' '
    char copy_of_symbol = SYMBOL;
    char string[20];                                           //copy of TEXT
    int count_of_words = 0;      
    strcpy(&string, TEXT);
    char* tmp_string; 
    
    tmp_string = strtok(&string, &copy_of_symbol);
    while(tmp_string != NULL) {                      //count of words
        tmp_string = strtok(NULL, copy_of_symbol);
        count_of_words++;
    }
    
    char* array_of_words = malloc(count_of_words * sizeof(char)); 
    
    tmp_string = strtok(string, &copy_of_symbol);
    array_of_words[0] = *tmp_string;
    
    for(int i = 1; i < count_of_words; i++) {
        while(tmp_string != NULL) {         //write separate words in an array 
            array_of_words[i] = *tmp_string; //strcpy
            tmp_string = strtok(NULL, &copy_of_symbol);
        }
    }
    */
    
    #define TEXT  "gf jhgjsd skdjgfj djgfb kfh"
    #define SYMBOL  ' '
    int size_one = strlen(TEXT) + 1;
    char string[size_one];
    strcpy(string, TEXT);
    int count_of_words = 0;

    char * tmp = strtok(string, " .,");
    while(tmp != NULL) {
        count_of_words++;
        tmp = strtok(NULL, " .,");
    }
    
    
strcpy(string, TEXT);
    char *tmp1 = strtok(string, " ,.");
    
    char array_of_words[count_of_words][255];
    int i = 0;
    //strcpy(array_of_words[0], tmp1);
    
            while(tmp1) {
            strcpy(array_of_words[i], tmp1);
            tmp1 = strtok(NULL, " ,.");
            i++;
            }
        
    
    
    

    char temp[255];
    for(int i = 0; i < count_of_words; i++) {
        for(int j = 0; j < count_of_words; j++) {
            if(strcmp(array_of_words[j], array_of_words[j + 1]) > 0) {
                strcpy(temp, array_of_words[j]);
                strcpy(array_of_words[j], array_of_words[j + 1]);
                strcpy(array_of_words[j + 1], temp);
            }
        }
    }
    return 0;
}