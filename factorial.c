#include <stdio.h>

void factorial(int num){
    int i;
    int resultado = 1;
    if(num < 1){
        printf("Aviso! Factorial 0 o negativo!\n");
        return;
        
        }
    else{
        for(i = 1; i <= num; i++){
        resultado = resultado*i;
        }
        printf("El resultado del factorial es:\n%d", resultado);
    }
}

int main(){

    int num;
    printf("Indique el número a factorizar:");
    scanf("%d", &num);
    factorial(num);
    
    return 0;
}