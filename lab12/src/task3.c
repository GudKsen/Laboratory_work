#include <lib.h>

int main() {
    char arr[N2];
    for (int i = 0; i < N2; i++) {
        if(stdin != ' ')
        arr[i] = getc(stdin);
    }
    for (int i = 0; i < N2; i++) {
        putc(arr[i], stdout);
    }
    printf("\n");
    return 0;
}