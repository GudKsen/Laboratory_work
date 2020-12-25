#include<lib.h>

int main() {
#define TEXT_OF_SYMBOLS "kljbggd 856 4g55034 hgh,,.rjhg,s"
char* unique_array = NULL;
char* copy_of_text = NULL;
strcpy(&copy_of_text, TEXT_OF_SYMBOLS);
int size_symbols = strlen(TEXT_OF_SYMBOLS);
    for(int i = 0; i < size_symbols; i++) {
        for(int j = i; j < size_symbols; j++) {
            for(int k = 0; k < i; k++) {
                if(strcmp(&unique_array[k], &copy_of_text[j])) {
                    break;
                }
                if(k == i){
                    unique_array[i] = copy_of_text[j];
                    break;
                }
            }
        }
    }
    int n = 0;
    int count = 0;
    int frequency[15];
    for(int i = 0; unique_array[i] == NULL; i++) {
        for(int j = 0; j < copy_of_text[j] == NULL; j++) {
            if(strcmp(&unique_array[i], &copy_of_text[j])){
                count++;
            }
        }
        frequency[n] = count++;
        count = 0;
        n++;
    }
    return 0;
}