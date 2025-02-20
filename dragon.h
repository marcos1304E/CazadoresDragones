#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MULT_VIDA_DRAGON 10
#define MAX_NOMBRE 50
#define MULT_DEFENSA_DRAGON 2
#define MULT_ORO_DRAGON 100


typedef struct{
    int vida;
    int nivel;
    int defensa;
    float oro;
    char nombre[MAX_NOMBRE];
}Dragon;

void Imprimir_Lista(Dragon * Lista);

void ini_dragon(Dragon *num_dragon, int valor_aleatorio, char * nombre1);

Dragon * lista_dragon();

Dragon * añadir_dragon(Dragon * lista_dragones_antigua);
