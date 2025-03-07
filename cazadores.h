#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */


#define MAX_CAZADORES 3

typedef struct{
	char nombre [50];
	char habilidad[50];
	int vida;
	int dano;
} Cazador;


void imprimir_lista(Cazador *lista, int numCazadores);
void inicializarCazador(Cazador *cazador, char *nombre, int vida, int defensa, int oro);
Cazador *lista_cazadores(int *numCazadores);
Cazador *agregarCazador(Cazador *lista, int *numCazadores);