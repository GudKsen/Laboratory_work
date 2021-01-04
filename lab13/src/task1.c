#include<lib.h>

int main() {
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
    
    char **array_of_words = malloc(count_of_words * sizeof(char*));
    for(int i = 0; i < count_of_words; i++) {
        array_of_words[i] = malloc(25 * sizeof(char*));
    }
    int i = 0;
    while(tmp1) {
        strcpy(array_of_words[i], tmp1);
        tmp1 = strtok(NULL, " ,.");
        i++;
    }
    sort_words(array_of_words, count_of_words);
    for(int i = 0; i < count_of_words; i++) {
        free(array_of_words[i]);
    }
    free(array_of_words);
    return 0;
}