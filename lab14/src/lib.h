#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#include <sys/stat.h>

#define YELLOW "\033[1;33m"

void sort_words(char **array_of_words, int count_of_words);

//void show_dir(char *name_dir, char *copy_of_first_name_dir);
void show_dir(char *name_dir, int lvl);