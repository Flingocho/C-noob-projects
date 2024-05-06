/*
 * Escribe un programa que se encargue de comprobar si un número es o no primo.
 * Hecho esto, imprime los números primos entre 1 y 100.
 */

#include <stdio.h>
#include <stdint.h>

int esPrimo(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int32_t num;
    char opcion;
    
    do {
        printf("Num to check: ");
        scanf(" %d", &num);
        
        if (esPrimo(num)) {
            printf("%d es primo.\n", num);
        } else {
            printf("%d no es primo.\n", num);
        }
        
        printf("Ahora veamos todos los números primos del 1 al 100:\n");
        for(int i=1; i<=100-1; i++){
            if(esPrimo(i)==1){
                printf("%d, ", i);
            }
        }
        
        printf("\n¿Deseas verificar otro número? (s/n): ");
        scanf(" %c", &opcion);
        
    } while (opcion == 's');
    
    printf("¡Hasta luego!\n");

    return 0;
}
