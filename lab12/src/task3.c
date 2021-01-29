#include <lib.h>

int main() {
    char str[20];
    FILE *file;
    file = fopen("text.txt", "w");
    if (file != NULL) {
        printf("File created\n");
        
    }
    else {
        printf("Error\n");
    }
    
    fclose(file);

     

    return 0;
}