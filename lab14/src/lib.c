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

int file_size(FILE* myfile) {
    
    //myfile = fopen(name_file, "r");
    long int prev = ftell(myfile);
    fseek(myfile, 0L, SEEK_END);
    
    long int sz = ftell(myfile);
    fseek(myfile, prev, SEEK_SET);
   // fclose(myfile);
    return sz;
}

int show_dir(char *name_dir, int count_into) {
   int full_size = 0;
   int size = 0;
    struct dirent *de;
    DIR *dr = opendir(name_dir);
    struct stat st;
    //float size;
    char *tmp;
    //off_t size;
    int size_fseek = 0;
    
    if(dr == NULL) {
        printf("Could not open current directory");
    }
    char string_for_name[1000];
   FILE* fl;
    while((de = readdir(dr)) != NULL) {
      if (strcmp(de -> d_name, ".") != 0 && strcmp(de -> d_name, "..") != 0) {
         if(de -> d_type == DT_DIR) {
             for(int i = 0; i < 2*count_into; i++) {
                 printf(" ");
             }
            /*stat(de -> d_name, &st);
            size = st.st_size;
            
            fl = fopen(de -> d_name, "rb");*/
            //size_fseek = file_size(fl);
            /*fseek(fl, 0L, SEEK_END);
    
            long sz = ftell(fl);
            fclose(fl);*/
            // printf("\e[1;34m%s\e[0m - %6.2ld   %d\n", de -> d_name, size, size_fseek);
            
             //printf("\e[1;34m%s\e[0m\n", de -> d_name);
             
             strcpy(string_for_name, name_dir);
             strcat(string_for_name, "/");
             strcat(string_for_name, de -> d_name);
             printf("\e[1;34m%s\e[0m\n", de -> d_name);
             full_size += show_dir(string_for_name, count_into + 1);
             
         }  else {
           for(int i = 0; i < 2*count_into; i++) {
               printf(" ");
           }
           strcpy(string_for_name, name_dir);
             strcat(string_for_name, "/");
             strcat(string_for_name, de -> d_name);
             fl = fopen(string_for_name, "rb");
             size = file_size(fl);
             full_size += size;
           //stat(de -> d_name, &st);
           //size = st.st_size;
           /*char str_tmp[100];
           strcpy(str_tmp, de -> d_name);
           str_tmp[strcspn(str_tmp, '\0')] = 0;*/

           /*fl = fopen(de -> d_name, "rb");
           size_fseek = file_size(fl);

           fclose(fl);*/
           printf("%s\n", de -> d_name);
           
         }
         
      }
    }
    printf("Total size: %d\n", full_size);
    closedir(dr);
    return full_size;
}
/*void show_size(char *name_dir, int count_into, off_t *full_size) {
   
    struct dirent *de;
    DIR *dr = opendir(name_dir);
    struct stat st;
    //float size;
    off_t size;
    FILE* fl;
    if(dr == NULL) {
        printf("Could not open current directory");
    }
   char string_for_name[1000];
   //char* string_for_name;
    while((de = readdir(dr)) != NULL) {
     if (strcmp(de -> d_name, ".") != 0 && strcmp(de -> d_name, "..") != 0) {
         if(de -> d_type == DT_DIR) {
            stat(de -> d_name, &st);
            size = st.st_size;
            *full_size += size;
             
             strcpy(string_for_name, name_dir);
             strcat(string_for_name, "/");
             strcat(string_for_name, de -> d_name);
             
             show_size(string_for_name, count_into + 1, full_size);
             
         }  else {
           
           /*stat(de -> d_name, &st);
            size = st.st_size;*
            fl = fopen(string_for_name, "rb");
            size = file_size(fl);

           *full_size += size;
           fclose(fl);
           
         }
         
      }
    }
    
    closedir(dr);
}*/
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