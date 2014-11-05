#include <stdio.h>

int main() {
    volatile long total = 0;

    for (long i = 0; i < 100000000; i++) {
        total += i;
    }

    printf("%ld\n", total);
}
