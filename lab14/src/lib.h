#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#include <sys/stat.h>

#define YELLOW "\033[1;33m"

void sort_words(char **array_of_words, int count_of_words);

void show_dir(char *name_dir, int count_into);
void read_from_file(char* name_of_start_file, char* str);
void write_to_file(char* name_of_result_file, int count_of_words, char** array_of_words);

void show_size(char *name_dir, int count_into, float *full_size);