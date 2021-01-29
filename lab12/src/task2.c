#include <lib.h>

int main() {
    double arr[N2*2];
    char string[80];
    puts("Input: ");
    gets(&string);
    int n = 0;
    for (int i = 0; i < 80; i++) {
        if(isdigit(string[i])) {
            arr[n] = atof(string[i]);
            n++;
        }
    }
    for (int i = 0; i < N2*2; i++) {
        printf("%f ", arr[i]);
    }
    puts("Output: ");
    puts(string);
    
    
    getchar();
    return 0;
}