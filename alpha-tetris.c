#include <stdio.h>
//CONSTANTES
#define FILAS 10
#define COLUMNAS 10
//movimientos
enum Movement {
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3,
    ROTATE = 4
};
//función pintar pantalla
void print_screen(char screen[FILAS][COLUMNAS]) {
    //imprime el estado de screen (ver move_piece()*1)
    printf("Matriz:\n");
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}
//función para mover las piezas
void move_piece(enum Movement movement, char screen[FILAS][COLUMNAS], int *rotation){

    //variables locales
    //Pantalla en blanco para operar
    char new_screen[FILAS][COLUMNAS] ={
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
    //X a mover de la pieza
    int rotation_item = 0;
    //rotaciones entre estados
    int rotations[4][4][2] ={
            {{1, 1}, {0, 0}, {-2, 0}, {-1, -1}},
            {{0, 1}, {-1, 0}, {0, -1}, {1, -2}},
            {{0, 2}, {1, 1}, {-1, 1}, {-2, 0}},
            {{0, 1}, {1, 0}, {2, -1}, {1, -2}},
        };
    //damos a new rotation el valor de *rotation (puntero)
    int new_rotation;
    new_rotation = *rotation;

    //en caso de rotación se incrementa el estado de rotation 0-3
    if(movement == ROTATE){
        new_rotation = new_rotation + 1;
    //si llegamos a 4 volvemos a 0
            if(new_rotation == 4){
                new_rotation = 0;
            }
    }
    //paseamos todas las filas y columnas
    for(int row_index = 0; row_index < FILAS; row_index++){
        for(int column_index = 0; column_index < COLUMNAS; column_index++ ){
            //si el valor de la casilla es X
            if(screen[row_index][column_index] == 'X'){
                //se define un nuevo índice cada vez que lo queremos mover
                int new_row_index = 0;
                int new_column_index = 0;
                //operativa lógica movimientos
                switch (movement)
                {
                    case DOWN:
                        new_row_index = row_index +1;
                        new_column_index = column_index;
                        break;

                    case RIGHT:
                        new_row_index = row_index;
                        new_column_index = column_index + 1;
                        break;

                    case LEFT:
                        new_row_index = row_index;
                        new_column_index = column_index - 1;
                        break;

                    case ROTATE:
                
                        //estado rotacion, pieza a rotar, fila(0) o columna(1)
                        new_row_index = row_index + rotations[new_rotation][rotation_item][0];
                        new_column_index = column_index + rotations[new_rotation][rotation_item][1];
                        rotation_item = rotation_item + 1;
                        break;
                }
                //metemos la X en cada vuelta del bucle que corresponda
                new_screen[new_row_index][new_column_index] = 'X';
            }
        }
    }
    //salida de los bucles
    *rotation = new_rotation;
    //damos los valores a screen de new screen
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            screen[i][j] = new_screen[i][j];
        }
    }

    //imprimimos estado de la pantalla tras el movimiento
    //(*1)En C se pasan los arrays de char como punteros 
    //así que print "screen" o "new screen" dará el mismo resultado
    //diremos new_screen por legibilidad 
    print_screen(new_screen);
}
//cuerpo principal e inicio del programa
int main() {
    //pantalla inicial (pieza)
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
    //estado de rotación inicial
    int rotation = 0;
    //puntero de rotation como parámetro para guardar cambios de estado
    int *p_rotation;
    p_rotation = &rotation;
    //print pantalla inicial
    print_screen(screen);
    //movimientos 
    //**Implementarlos por teclado en prox version**//
    move_piece(ROTATE, screen, p_rotation);
    move_piece(DOWN, screen, p_rotation);
    move_piece(ROTATE, screen, p_rotation);
    move_piece(ROTATE, screen, p_rotation);
    return 0;
}
