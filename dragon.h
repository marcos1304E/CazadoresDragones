#ifndef DRAGON_H
#define DRAGON_H
/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MULT_VIDA_DRAGON 10
#define MAX_NOMBRE 50
#define MULT_DEFENSA_DRAGON 2
#define MULT_ORO_DRAGON 100

typedef struct {
    char nombre[50];
    int vida;
    int nivel;
    int defensa;
    int oro;
} Dragon;

// Prototipos de funciones
void Imprimir_Lista(Dragon *lista, int numDragones);
Dragon *lista_dragon(int *numDragones);
void ini_dragon(Dragon *num_dragon, int valor_aleatorio, char *nombre1);
Dragon *añadir_dragon(Dragon *listaDragones, int *numDragones);

#endif
