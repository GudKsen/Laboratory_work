#include<lib.h>

int main() {
    #define TEXT  "gf jhgjsd skdjgfj djgfb kfh"
    #define SYMBOL  ' '
    char copy_of_symbol = SYMBOL;
    char* string = NULL;                                           //copy of TEXT
    int count_of_words = 0;      
    strcpy(&string, TEXT);
    char* tmp_string = NULL; 
    
    tmp_string = strtok(&string, &copy_of_symbol);
    while(tmp_string != NULL) {                      //count of words
        tmp_string = strtok(tmp_string, copy_of_symbol);
        count_of_words++;
    }
    
    char* array_of_words = malloc(count_of_words * sizeof(char)); 
    
    tmp_string = strtok(string, &copy_of_symbol);
    array_of_words[0] = *tmp_string;
    
    for(int i = 1; i < count_of_words; i++) {
        while(tmp_string != NULL) {         //write separate words in an array 
            array_of_words[i] = *tmp_string;
            tmp_string = strtok(string, &copy_of_symbol);
        }
    }
    
    
    int size = strlen(string) + 1;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(array_of_words[j] > array_of_words[j + 1]) {
                char temp = array_of_words[j];
                array_of_words[j] = array_of_words[j + 1];
                array_of_words[j + 1] = temp;
            }
        }
    }
    return 0;
}