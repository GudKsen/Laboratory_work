#include <lib.h>

int main() {
    float arr[N2];
    printf("Input numbers: ");
    for (int i = 0; i < N2; i++){
        fread(&arr[i], sizeof(float), 3, stdin);
    }
    for(int i = 0; i < N2; i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}



/*void print_number(int value) {
    char buf[12];
    //itoa(value, buf, 10);
    gcvt(value, 10, buf);
    fwrite(&buf, sizeof(char), strlen(buf) + 1, stdout);
    

    sprintf(buf, "%d", value);
}
*/


/*int main (){
    char str[] = "Hello";
    fwrite(&str, sizeof(char), strlen(str) + 1, stdout); //output string
    
    int a = 110;
    //fwrite(&a, sizeof(a), 1, stdout);
print_number(a);

    float arr[N2];
    //float arr[N2] = {10.2, 5.3, 6.3, 2.4, 2.5, 2.9, 1.2, 1.8, 1, 10};
    int count_of_intervals = 0, start_index_max, end_index_max, max_count = 0;
    printf("Input numbers: ");
    for (int i = 0; i < N2; i++){
        fread("%f", &arr[i]);
    }
    return 0;
    }*/
  

/*void print_number(int value) {
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
 }*/

 /*int main() {
    char* ff = "test.txt";
    FILE* f = fopen(ff, "w");
    char buf[100];
    while(!feof(f)) {
        fgets(buf, 99, f);
        printf("%s", buf);
    }
    return  0;
 }*/

 /*
    char *s = "123jhfb";
    chsr *buf;
    int v = strol(s, &buf, 10):
    free(buf);
    return 0;
 */