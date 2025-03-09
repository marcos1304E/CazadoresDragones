#ifndef CAZADORES_H
#define CAZADORES_H

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

typedef struct {
    char nombre[50];
    int vida;
    int defensa;
    int ataque;
    int oro;
} Cazador;

// Prototipos de funciones
void imprimir_lista(Cazador *lista, int numCazadores);
void inicializarCazador(Cazador *cazador, char *nombre, int vida, int defensa, int oro);
Cazador *lista_cazadores(int *numCazadores);
Cazador *agregarCazador(Cazador *lista, int *numCazadores);

#endif
