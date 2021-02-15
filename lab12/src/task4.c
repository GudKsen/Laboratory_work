#include <lib.h>

void print_number(float value) {
    char buf[12];
    gcvt(value, 10, buf);
    fwrite(&buf, sizeof(char), strlen(buf) + 1, stdout);
}

int main() {
    char* string;
    float arr[N2];
    int start_index_max, end_index_max, count_of_intervals, max_count;
    printf("Input numbers: ");
    fread(string, sizeof(char), 19, stdin);
    take_numbers_from_string(string, &arr);
    interval_increasing_numbers(N2, arr, &start_index_max, &end_index_max, &count_of_intervals, &max_count);
    float* result_arr = malloc(max_count * sizeof(float));
    for (int i = 0, j = start_index_max; i <= max_count && j <= end_index_max; i++, j++) {
		result_arr[i] = arr[j];
	}
    printf("\n");
    
    printf("Result: ");
    for(int i = 0; i <= max_count; i++) {
        char buf[30];
        sprintf(buf, "%f", result_arr[i]);
        fwrite(&buf, sizeof(char), strlen(buf) + 1, stdout);
        printf(" ");
    }
    printf("\n");
    free(result_arr);
    return 0;
}







/*int main (){
    char str[] = "Hello";
    fwrite(&str, sizeof(char), strlen(str) + 1, stdout); //output string
    
    int a = 110;
    //fwrite(&a, sizeof(a), 1, stdout);
print_number(a);

    return 0;
    }
  

void print_number(int value) {
    char buf[12];
    //itoa(value, buf, 10);
    gcvt(value, 10, buf);
    //fwrite(&buf, sizeof(char), strlen(buf) + 1, stdout);
    
    puts(buf);
    //sprintf(buf, "%d", value);
}

 int main() {
     char str[] = "Hello";
     char buf[10];
     fgets(buf, 9, stdin);
     int value = strtol(buf, NULL, 10);
     fwrite(&buf, sizeof(char), strlen(buf) + 1, stdout);
    return 0;
 }

 int main() {
    char* ff = "test.txt";
    FILE* f = fopen(ff, "w");
    char buf[100];
    while(!feof(f)) {
        fgets(buf, 99, f);
        printf("%s", buf);
    }
    return  0;
 }

 
    char *s = "123jhfb";
    chsr *buf;
    int v = strol(s, &buf, 10):
    free(buf);
    return 0;
 */