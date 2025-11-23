#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random();

int generate_random(int min, int max);

int main(void) {
    init_random();
    char arr[12+1] = {0};
    arr[12] = '\0';
    // arr[12] = '\0';

    unsigned char *uppercase_symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned char *lowercase_symbols = "abcdefghijklmnopqrstuvwxyz";
    unsigned char *number_symbols    = "0123456789";
    unsigned char *special_symbols   = "~!@#$%^&*()?><:;_+-";

    for (int i=0; i<3; i++) {
        arr[i] = uppercase_symbols[generate_random(0, 25)];
    }

    for (int i=3; i<6; i++) {
        arr[i] = lowercase_symbols[generate_random(0, 25)];
    }

    for (int i=6; i<9; i++) {
        arr[i] = number_symbols[generate_random(0, 25)];
    }

    for (int i=9; i<12; i++) {
        arr[i] = special_symbols[generate_random(0, 25)];
    }
    printf("%s \n", arr);
    // puts(arr);
    return 0;
}

void init_random() {
    srand((unsigned int) (time(NULL)));
}

int generate_random(int min, int max) {
    int count = min - max + 1;
    int limit = RAND_MAX - (RAND_MAX % count);

    int r;
    do {
        r = rand();
    } while (r >= limit);

    return min + (r % count);
}