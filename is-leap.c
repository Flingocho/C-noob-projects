#include <stdio.h>

int is_leap(int year) {
    int isLeap = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                isLeap = 1;
            }
        } 
        else {
            isLeap = 1;
        }
    }
    return isLeap;
}

int main() {
    int year;
    printf("Introduce the year: ");
    scanf("%d", &year);
    if (is_leap(year) == 1) {
        printf("The year is leap.");
    } else {
        printf("The year is not leap.");
    }

    return 0;
}
