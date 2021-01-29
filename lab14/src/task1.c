#include <lib.h>

int main() {

    FILE *file_start;
    FILE *file_result;
    char name_of_start_file[255];
    char name_of_result_file[255];
    char str[50];
    char str1[50];
    puts("Input file's name: ");
    gets(name_of_start_file);
    puts("Enter the name of the resulting file: ");
    gets(name_of_result_file);
    file_start = fopen(name_of_start_file, "r");
    
    if(file_start == NULL) {
        puts("Error");
    }
    else {
        puts("File opened successfully!");
    }

    fgets(str, sizeof(str), file_start);  //from file to string
    
    fclose(file_start);
    puts(str);
    strcpy(str1, str);
    int count_of_words = 0;

    char * tmp = strtok(str, " .,");
    while(tmp != NULL) {
        count_of_words++;
        tmp = strtok(NULL, " .,");
    }

    printf("Number of words: %d\n", count_of_words);

    strcpy(str, str1);
    char *tmp1 = strtok(str, " ,.");
    
    char **array_of_words = malloc(count_of_words * sizeof(char*));
    for(int i = 0; i < count_of_words; i++) {
        array_of_words[i] = malloc(25 * sizeof(char*));
    }
    
    int g = 0;
    while(tmp1) {
        strcpy(array_of_words[g], tmp1);
        tmp1 = strtok(NULL, " ,.");
        g++;
    }
    
    sort_words(array_of_words, count_of_words);
    
    for (int i = 0; i < count_of_words; i++) {
        printf("%s ", array_of_words[i]);
    }
    
    printf("\n");

    file_result = fopen(name_of_result_file, "w");
    for (int i = 0; i < count_of_words; i++) {
        fprintf(file_result, "%s ", array_of_words[i]);
    }
    fclose(file_result);

    for(int i = 0; i < count_of_words; i++) {
        free(array_of_words[i]);
    }
    free(array_of_words);

    printf("\n");
    char name_dir[20];
    
    
    gets(name_dir);
    char copy_of_first_name_dir[255];
    strcpy(copy_of_first_name_dir, name_dir);
    //show_dir(name_dir, copy_of_first_name_dir);
    show_dir(name_dir, 0);
    return 0;
}