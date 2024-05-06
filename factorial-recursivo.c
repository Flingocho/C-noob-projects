#include <stdio.h>
#include <stdint.h>

int factorial_recursivo(int32_t num){

    if(num < 0){
        printf("Factorial negativo!");
        return 0;
    }
    else if(num == 0){
        return 1;
    }

    return num * factorial_recursivo(num - 1);
}

int main(){

    int32_t num = 5;
    printf("%d",factorial_recursivo(num));
    return 0;
}