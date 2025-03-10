#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "utilidades.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

// Lista global de objetos disponibles
Objeto inventario[] = {
    {"Poción de vida", 20, 0, 0, 50, 0},
    {"Armadura ligera", 0, 10, 0, 100, 0},
    {"Espada afilada", 0, 0, 15, 150, 0},
    {"Elixir mágico", 50, 10, 10, 200, 0},
    {"Doble elefante de guerra", 0, 20, 20, 300, 0}
};

void tienda(Cazador *cazador) {
    int opcion;
    do {
        printf("\n===== 🛒 TIENDA 🛒 =====\n");
        printf("Tu oro: %d\n", cazador->oro);
        for (int i = 0; i < 5; i++) {
            printf("%d. %s (+%d HP, +%d DEF, +%d ATQ) - %d Oro (x%d)\n",
                   i + 1, inventario[i].nombre,
                   inventario[i].vidaExtra, inventario[i].defensaExtra, inventario[i].ataqueExtra,
                   inventario[i].precio, inventario[i].cantidad);
        }
        printf("6. Salir de la tienda\n");
        printf("Elige un objeto: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 5) {
            if (cazador->oro >= inventario[opcion - 1].precio) {
                cazador->oro -= inventario[opcion - 1].precio;
                inventario[opcion - 1].cantidad++;
                printf("Has comprado %s (x%d).\n", inventario[opcion - 1].nombre, inventario[opcion - 1].cantidad);
            } else {
                printf("No tienes suficiente oro.\n");
            }
        }
    } while (opcion != 6);
}

// Función para usar objetos en combate
void usar_objeto(Cazador *cazador, Objeto *objeto) {
    if (objeto->cantidad > 0) {
        printf("Usaste %s.\n", objeto->nombre);
        cazador->vida += objeto->vidaExtra;
        cazador->defensa += objeto->defensaExtra;
        cazador->ataque += objeto->ataqueExtra;
        objeto->cantidad--;
    } else {
        printf("No tienes más %s.\n", objeto->nombre);
    }
}
