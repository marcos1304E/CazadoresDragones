
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "cazadores.h"
#include "combate.h"
/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */


typedef struct {
    char nombre[50];
    int vidaExtra;
    int defensaExtra;
    int ataqueExtra;
    int precio;
    int cantidad;  // Número de unidades que el jugador tiene
} Objeto;

// Lista global de objetos disponibles en la tienda y el combate
extern Objeto inventario[];

void tienda(Cazador *cazador);
void usar_objeto(Cazador *cazador, Objeto *objeto);


#endif // UTILIDADES_H
