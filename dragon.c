#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dragon.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MAX_LISTA 3

void Imprimir_Lista(Dragon *lista, int numDragones) {
    for (int i = 0; i < numDragones; i++) {
        printf("Nombre: %s | Vida: %d | Nivel: %d | Defensa: %d | Oro: %.2f\n",
               lista[i].nombre, lista[i].vida, lista[i].nivel, lista[i].defensa, lista[i].oro);
    }


void ini_dragon(Dragon *num_dragon, int valor_aleatorio, char * nombre1){

    num_dragon -> vida = valor_aleatorio * MULT_VIDA_DRAGON;
    num_dragon -> nivel = valor_aleatorio;
    num_dragon -> defensa = valor_aleatorio * MULT_DEFENSA_DRAGON;
    num_dragon -> oro = valor_aleatorio * MULT_ORO_DRAGON;
    strcpy(num_dragon -> nombre, nombre1);
}

Dragon * lista_dragon(){

    int min, max; 

    Dragon * lista = (Dragon*)malloc(MAX_LISTA*sizeof(Dragon));

    if(lista == NULL){

        printf("ERROR\n");
    }

    int * randomnivel = (int*)malloc(MAX_LISTA*sizeof(int));

    if(randomnivel == NULL){
        printf("ERROR\n");
    }

    srand(time(0));

    min = 1;
    max = 50;

    for (int i = 0; i < MAX_LISTA; ++i){
        randomnivel[i] = (rand() % (max - min + 1)) + min;
    }

    ini_dragon(&lista[0], randomnivel[0], "Iulian Dragoi(El renegado)");
    ini_dragon(&lista[1], randomnivel[1], "Emerson y Jefferson(Dragon bicéfalo)");
    ini_dragon(&lista[2], randomnivel[2], "Lory Money(El dragon de oro)");

    return lista;

}

Dragon *añadir_dragon(Dragon *listaDragones, int *numDragones) {
    (*numDragones)++;
    listaDragones = (Dragon *)realloc(listaDragones, (*numDragones) * sizeof(Dragon));

    if (listaDragones == NULL) {
        printf("Error al reasignar memoria para el nuevo dragón.\n");
        exit(EXIT_FAILURE);
    }

    // Datos del nuevo dragón
    Dragon *nuevoDragon = &listaDragones[*numDragones - 1];
    printf("Introduce el nombre del nuevo dragón: ");
    scanf(" %[^\n]", nuevoDragon->nombre);  // Leer nombre con espacios

    printf("Introduce el nivel del nuevo dragón: ");
    scanf("%d", &nuevoDragon->nivel);

    nuevoDragon->vida = nuevoDragon->nivel * MULT_VIDA_DRAGON;
    nuevoDragon->defensa = nuevoDragon->nivel * MULT_DEFENSA_DRAGON;
    nuevoDragon->oro = nuevoDragon->nivel * MULT_ORO_DRAGON;

    printf("¡Dragón añadido con éxito!\n");
    return listaDragones;
}

int main() {
    // Crear una lista inicial de dragones
    Dragon *lista_dragones = lista_dragon();

    // Imprimir la lista de dragones inicial
    printf("Lista de dragones inicial:\n");
    Imprimir_Lista(lista_dragones);

    // Preguntar al usuario si desea añadir un nuevo dragón
    char respuesta;
    printf("¿Deseas agregar un nuevo dragón? (s/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 's' || respuesta == 'S') {
        lista_dragones = añadir_dragon(lista_dragones);
    }

    // Imprimir la lista final de dragones
    printf("Lista final de dragones:\n");
    Imprimir_Lista(lista_dragones);

    // Liberar memoria
    free(lista_dragones);

    return 0;
}