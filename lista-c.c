#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Función para insertar un elemento al final de la lista
void insertar(struct Nodo **cabeza, int dato) {
    // Creamos un nuevo nodo
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }

    // Si la lista no está vacía, recorremos hasta el último nodo
    struct Nodo *temp = *cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    // Insertamos el nuevo nodo al final de la lista
    temp->siguiente = nuevoNodo;
}

// Función para imprimir la lista
void imprimir(struct Nodo *cabeza) {
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

int main() {
    // Inicializamos la lista vacía
    struct Nodo *lista = NULL;

    // Insertamos algunos elementos en la lista
    insertar(&lista, 10);
    insertar(&lista, 20);
    insertar(&lista, 30);

    // Imprimimos la lista
    printf("Lista: ");
    imprimir(lista);

    return 0;
}
