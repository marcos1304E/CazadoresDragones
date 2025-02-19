#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MAX_NOMBRE 50
#define MULT_VIDA_DRAGON 2


typedef struct{
    int vida;
    int nivel;
    int defensa;
    float oro;
    char nombre[MAX_NOMBRE];
}Dragon;