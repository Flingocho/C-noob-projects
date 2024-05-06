#include <stdio.h>
#include <stdint.h>

void fizz_buzz(){
    
    for(uint_fast8_t i = 0; i <= 100; i++){
        if(i % 3 == 0){
            if(i % 5 == 0){
                printf("Fizz-Buzz! (%d)\n", i);
            }
            printf("Fizz! (%d)\n", i);
        }
        else if(i % 5 == 0){
            printf("Buzz! (%d)\n", i);
        }
        else{
            printf("%d\n", i);
        }
    }
}

int main() {
    fizz_buzz();
    return 0;
}
