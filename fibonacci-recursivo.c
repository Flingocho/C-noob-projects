#include <stdio.h>

int fibonacci_recursivo(int num) {
    if (num <= 0) {
        printf("La posición tiene que ser mayor que 0");
        return -1; 
    } else if (num == 1) {
        return 0;
    } else if (num == 2) {
        return 1;
    } else {
        return fibonacci_recursivo(num - 1) + fibonacci_recursivo(num - 2);
    }
}

int main() {
    int num = 10;
    printf("El número de Fibonacci en la posición %d es %d", num, fibonacci_recursivo(num));
    return 0;
}
