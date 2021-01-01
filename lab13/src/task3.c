#include<lib.h>

int main() {
char text[] = "jf dju ffjj fjg";
	int size = strlen(text) + 1;
	int all_frequency[255];
	char all_symbols[255];
    all_freq_symb(text, all_frequency, all_symbols, size);
	int frequency[20] = {0};
	char symbols[20] = {0};
	int n = 0;
	for (int i = 0; i < 255; i++) {
		if (all_frequency[i] != 0) {
			frequency[n] = all_frequency[i];
			symbols[n] = all_symbols[i];
			n++;
		}
	}

    return 0;
}