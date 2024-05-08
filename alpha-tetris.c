#include <stdio.h>

#define FILAS 10
#define COLUMNAS 10

enum Movimientos {
    ABAJO = 1,
    DERECHA = 2,
    IZQUIERDA = 3,
    ROTAR = 4
};

void print_screen(char screen[FILAS][COLUMNAS]) {
    printf("Matriz:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", screen[i][j]);
        }
        printf("\n");
    }
}

void mover_pieza(char screen[FILAS][COLUMNAS], enum Movimientos movimiento) {
    char nueva_screen[FILAS][COLUMNAS] = {
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
    };

    
        


    for (int fila_actual = 0; fila_actual < FILAS; fila_actual++) {
        for (int columna_actual = 0; columna_actual < COLUMNAS; columna_actual++) {
            if (screen[fila_actual][columna_actual] == 'X') {
                int nueva_fila = fila_actual;
                int nueva_columna = columna_actual;
                switch (movimiento) {
                    case ABAJO:
                        nueva_fila = fila_actual + 1;
                        break;
                    case DERECHA:
                        nueva_columna = columna_actual + 1;
                        break;
                    case IZQUIERDA:
                        nueva_columna = columna_actual - 1;
                        break;
                    case ROTAR:
                        printf("Rotar\n");
                        break;
                }
                nueva_screen[nueva_fila][nueva_columna] = 'X';
            }
        }
    }
    // Actualizar la matriz screen con los valores de nueva_screen
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            screen[i][j] = nueva_screen[i][j];
        }
    }
    print_screen(screen);
}

int main() {
    // Matriz de pantalla
    char screen[FILAS][COLUMNAS] = {
        {'X','O','O','O','O','O','O','O','O','O'},
        {'X','X','X','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
        {'O','O','O','O','O','O','O','O','O','O'},
    };
    
    print_screen(screen);
    mover_pieza(screen, ABAJO);
    mover_pieza(screen, DERECHA);
    mover_pieza(screen, DERECHA);
    mover_pieza(screen, ABAJO);
    return 0;
}
