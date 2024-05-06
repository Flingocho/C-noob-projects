#include <stdio.h>
#include <stdint.h>

void fibonacci() {
    uint64_t actual = 0;
    uint64_t anterior = 1;
    uint64_t temp = 0;

    for (int i = 0; i < 50; i++) {
        printf("%llu ", actual);
        temp = actual;
        actual = actual + anterior;
        anterior = temp;
    }
}

int main() {
    fibonacci();
    return 0;
}
