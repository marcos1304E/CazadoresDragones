#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dragon.h"
#include "combate.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MAX_LISTA 3

void Imprimir_Lista(Dragon *lista, int numDragones) {
    for (int i = 0; i < numDragones; i++) {
        printf("Nombre: %s | Vida: %d | Nivel: %d | Defensa: %d | Oro: %d\n",
               lista[i].nombre, lista[i].vida, lista[i].nivel, lista[i].defensa, lista[i].oro);
    }
}

void ini_dragon(Dragon *num_dragon, int valor_aleatorio, char * nombre1){
    num_dragon->vida = valor_aleatorio * MULT_VIDA_DRAGON;
    num_dragon->nivel = valor_aleatorio;
    num_dragon->defensa = valor_aleatorio * MULT_DEFENSA_DRAGON;
    num_dragon->oro = valor_aleatorio * MULT_ORO_DRAGON;
    strcpy(num_dragon->nombre, nombre1);
}

Dragon *lista_dragon(int  *numDragones) {
    *numDragones = 3;
    int min = 1, max = 50;

    Dragon *lista = (Dragon*)malloc(MAX_LISTA * sizeof(Dragon));
    if (lista == NULL) {
        printf("ERROR al asignar memoria para la lista de dragones.\n");
        exit(EXIT_FAILURE);
    }

    int *randomnivel = (int*)malloc(MAX_LISTA * sizeof(int));
    if (randomnivel == NULL) {
        free(lista);
        printf("ERROR al asignar memoria para los niveles de los dragones.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(0));
    for (int i = 0; i < MAX_LISTA; ++i) {
        randomnivel[i] = (rand() % (max - min + 1)) + min;
    }

    ini_dragon(&lista[0], randomnivel[0], "Iulian Dragoi(El renegado)");
    ini_dragon(&lista[1], randomnivel[1], "Emerson y Jefferson(Dragon bicéfalo)");
    ini_dragon(&lista[2], randomnivel[2], "Lory Money(El dragon de oro)");

    free(randomnivel); // Ahora sí liberamos la memoria de randomnivel antes de salir
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
    printf("Introduce el nombre del nuevo dragón (máximo 49 caracteres): ");
    scanf(" %49[^\n]", nuevoDragon->nombre);  // Evita desbordamientos de buffer

    printf("Introduce el nivel del nuevo dragón: ");
    scanf("%d", &nuevoDragon->nivel);

    nuevoDragon->vida = nuevoDragon->nivel * MULT_VIDA_DRAGON;
    nuevoDragon->defensa = nuevoDragon->nivel * MULT_DEFENSA_DRAGON;
    nuevoDragon->oro = nuevoDragon->nivel * MULT_ORO_DRAGON;

    printf("¡Dragón añadido con éxito!\n");
    return listaDragones;
}
