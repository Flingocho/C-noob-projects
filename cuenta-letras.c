#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Definición de la estructura para la tabla hash
#define HASH_SIZE 26
typedef struct {
    bool is_vowel;
} HashTable[HASH_SIZE];

// Función para inicializar la tabla hash
void initHashTable(HashTable hashTable) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i].is_vowel = false;
    }
    for (unsigned long long int i = 0; i < sizeof(vowels); i++) {
        hashTable[vowels[i] - 'a'].is_vowel = true;
    }
}

// Función para contar las vocales y consonantes en una cadena
void countLetters(const char *str, HashTable hashTable, int *vowels, int *consonants) {
    for (unsigned long long int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {
            if (hashTable[c - 'a'].is_vowel) {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

int main() {
    HashTable hashTable;
    int vowels = 0, consonants = 0;
    char input[100];

    initHashTable(hashTable);

    printf("Introduzca una palabra o frase: ");
    fgets(input, sizeof(input), stdin);

    countLetters(input, hashTable, &vowels, &consonants);

    printf("Hay %d vocales y %d consonantes.\n", vowels, consonants);

    return 0;
}
