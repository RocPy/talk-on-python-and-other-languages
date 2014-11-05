#include <stdio.h>

class Adder {
    public:
        Adder() : total(0) {}

        void add(long i) { total += i; }

        long total;
};

int main() {
    Adder adder;

    for (long i = 0; i < 100000000; i++) {
        adder.add(i);
    }

    printf("%ld\n", adder.total);
}
