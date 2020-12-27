#include<lib.h>

int main() {
#define TEXT_OF_SYMBOLS "kljbkggd 856 4g55034 hgh,,.rjhg,s"
int size_symbols = strlen(TEXT_OF_SYMBOLS);
char unique_array[size_symbols];
char copy_of_text[size_symbols];
strcpy(copy_of_text, TEXT_OF_SYMBOLS);
strcpy(unique_array, TEXT_OF_SYMBOLS);


int frequency[15];
int count = 0, n = 0, i = 0;

/*for(int i = 0; i < size_symbols; i++) {
    for(int j = i; j < size_symbols; j++) {
        if(unique_array[i] == copy_of_text[j] && count == 0) {
            unique_array[i] = copy_of_text[j];
            count++;
        }
        if(unique_array[i] == copy_of_text[j] && count != 0) {
            continue;
        }
       // if(unique_array[i] != copy_of_text[j]) {
         //   unique_array[i] = copy_of_text[j];
        //}
    }
    count = 0;
}*/


for(int i = 0; i < size_symbols; i++) {
    for(int j = i; j < size_symbols; j++) {
        if(copy_of_text[i] == copy_of_text[j]) {
            count++;
        }
    }
}





/*for(int i = 0; i < size_symbols; i++) {
    for( int j = i; j < size_symbols; j++) {
        if(strshr(copy_of_text, unique_array[i])){
            count++;
        }
    }
    frequency[n] = count / size_symbols;
    n++;
    count = 0;
}*/






    for(int i = 0; i < size_symbols; i++) {
        for(int j = i; j < size_symbols; j++) {
            for(int k = 0; k < i; k++) {
                if(unique_array[k] = copy_of_text[j]) {
                    break;
                }
                if(k == i){
                    unique_array[i] = copy_of_text[j];
                    break;
                }
            }
        }
    }
    /*int n = 0;
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
    }*/
    return 0;
}