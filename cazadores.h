#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAZADORES 3

/*Marcos*/


typedef struct{
	char nombre [50];
	char habilidad[50];
	int vida;
	int dano;
} Cazador;


void inicializarCazadores(Cazador *nuevoCazador, char *nombre1, char *habilidad1, int vida1, int dano1);

void imprimir_lista(Cazador *lista, int numCazadores);

Cazador * agregarCazador(Cazador * lista, int *numCazadores);