#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *  Autor: Leonardo Marescutti
 */

#define MAX_NOMBRE 20
int MAX_LISTA = 3;

typedef struct{
	int vida;
	int nivel;
	int defensa;
	float oro;
	char nombre[MAX_NOMBRE];
}Dragon;

void ini_dragon(Dragon *num_dragon, int vida1, int nivel1, int defensa1, float oro1, char * nombre1){
	num_dragon -> vida = vida1;
	num_dragon -> nivel = nivel1;
	num_dragon -> defensa = defensa1;
	num_dragon -> oro = oro1;
	strcpy(num_dragon -> nombre, nombe1);
}

Dragon * añadir_dragon(Dragon * nuevoDragon){

	int vida,nivel,defensa,sum = 1;
	float oro;
	char nombre[MAX_NOMBRE];

	lista_dragon(nuevoDragon);

	Dragon * dragon_nuevo = (Dragon*)realloc(nuevoDragon, (MAX_LISTA+sum)*sizeof(Dragon))

		if(dragon_nuevo == NULL){ //verificamos si el nuevo catalogo en nullo
			free(dragon_nuevo);
			exit(EXIT_FAILURE);
		}

	for (int i = MAX_LISTA; i < MAX_LISTA + sum; ++i){ //Bucle que pide el contenido del libro en base a los libros que queramos agregar

		printf("Vida del dragon:");
		scanf("%d", &vida);

		printf("Nivel del dragon:");
		scanf("%f", &nivel);

		printf("Cantidad de defensa:");
		scanf("%u", &defensa);

		printf("Cantidad de oro:");
		scanf("%d", &oro);

		printf("Nombre del dragon:");
		scanf(" ");
		fgets(nombre, MAX_TITTLE, nombre);
		nombre[strlen(nombre)-1] = '\0';

		ini_dragon(&lista[i],vida, nivel, defensa, oro, nombre);
	}

	MAX_TITTLE += sum;

	printf("Nueva lista de dragones:\n");
	Imprimir_Lista(nuevoDragon);
}

Dragon * lista_dragon(Dragon){

	Dragon * lista = (Dragon*)malloc(MAX_LISTA*sizeof(Dragon));

	if(lista == NULL){
		printf("ERROR\n");
		return EXIT_FAILURE;
	}

	int min, max, randomvida;

	// Inicializar el generador de números aleatorios
	srand(time(0));

	// Definir el rango
	min = 1;  // Cambia este valor según tu necesidad
	max = 100;  // Cambia este valor según tu necesidad

	// Generar el número aleatorio
	randomvida = (rand() % (max - min + 1)) + min;

	ini_dragon(&lista[0],randomvida, n, d, o, "Iulian Dragoi(El renegado)");
	ini_dragon(&lista[1],randomvida, n, d, o, "Emerson y Jefferson(Dragon bicéfalo)");
	ini_dragon(&lista[2],randomvida, n, d, o, "Loorey Mooney(El dragon de oro)");
}

void Imprimir_Lista(Dragon * Lista){

	for(int i = 0; i < MAX_LISTA; i++, Lista++){
		printf("%d,%d,%d,%d,%s,",Lista->vida,Lista->nivel,Lista->defensa,Lista->oro,Lista->nombre);
	}
}
