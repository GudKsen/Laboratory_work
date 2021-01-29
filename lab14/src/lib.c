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

void show_dir(char *name_dir, int lvl) {
    int count_for_direct = 0;
    int count_for_files = 0;
   
    struct dirent *de;
    DIR *dr = opendir(name_dir);
    struct stat st;
    if(dr == NULL) {
        printf("Could not open current directory");
    }
    char *string_for_name[1000];
   
    while((de = readdir(dr)) != NULL) {
      if (strcmp(de -> d_name, ".") != 0 && strcmp(de -> d_name, "..") != 0) {
         if(de -> d_type == DT_DIR) {
             for(int i = 0; i < 2*lvl; i++) {
                 printf(" ");
             }
             printf("\e[1;34m%s\e[0m\n", de -> d_name );

             
             strcpy(string_for_name, name_dir);
             strcat(string_for_name, "/");
             strcat(string_for_name, de -> d_name);
             
             show_dir(string_for_name, lvl + 1);
             count_for_direct++;
         }  else {
           for(int i = 0; i < 2*lvl; i++) {
               printf(" ");
           }
           printf("%s\n", de -> d_name);
           count_for_files++;
         }
         
      }
    }
    
    closedir(dr);
}

/*void size_of_directory(char DirNameSize) {
    
    struct dirent Dr;
    DIR *directory = opendir(DirNameSize);

}*/