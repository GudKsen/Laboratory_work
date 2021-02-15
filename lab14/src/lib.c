#include <lib.h>

void sort_words(char **array_of_words, int count_of_words) {
     char temp[20];
    for(int i = 0; i < count_of_words; i++) {
        for(int j = 0; j < count_of_words - 1; j++) {
            if(strcmp(array_of_words[j], array_of_words[j + 1]) > 0) {
                strcpy(temp, array_of_words[j]);
                strcpy(array_of_words[j], array_of_words[j + 1]);
                strcpy(array_of_words[j + 1], temp);
            }
        }
    }
}

void show_dir(char *name_dir, int count_into) {
    int count_for_direct = 0;
    int count_for_files = 0;
   
    struct dirent *de;
    DIR *dr = opendir(name_dir);
    struct stat st;
    float size;
    if(dr == NULL) {
        printf("Could not open current directory");
    }
    char *string_for_name[1000];
   
    while((de = readdir(dr)) != NULL) {
      if (strcmp(de -> d_name, ".") != 0 && strcmp(de -> d_name, "..") != 0) {
         if(de -> d_type == DT_DIR) {
             for(int i = 0; i < 2*count_into; i++) {
                 printf(" ");
             }
            stat(de -> d_name, &st);
            size = st.st_size;
             printf("\e[1;34m%s\e[0m - %6.2f\n", de -> d_name, size/1024);
            

             
             strcpy(string_for_name, name_dir);
             strcat(string_for_name, "/");
             strcat(string_for_name, de -> d_name);
             
             show_dir(string_for_name, count_into + 1);
             
         }  else {
           for(int i = 0; i < 2*count_into; i++) {
               printf(" ");
           }
           stat(de -> d_name, &st);
            size = st.st_size;
           printf("%s - %6.2f\n", de -> d_name, size/1024);
           count_for_files++;
         }
         
      }
    }
    
    closedir(dr);
}

void read_from_file(char* name_of_start_file, char* str) {
    FILE *file_start;
    file_start = fopen(name_of_start_file, "r");
    if(file_start == NULL) {
        puts("Error");
    }
    else {
        puts("File opened successfully!");
    
    }
    
    fgets(str, 50, file_start);  //from file to string  
    
    printf("string after fgets: %s", str);
    
    fclose(file_start);
}

void write_to_file(char* name_of_result_file, int count_of_words, char** array_of_words) {
    FILE *file_result;
    file_result = fopen(name_of_result_file, "w");
    for (int i = 0; i < count_of_words; i++) {
        fprintf(file_result, "%s ", array_of_words[i]);
    }
    fclose(file_result);
}