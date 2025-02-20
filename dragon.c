#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dragon.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MAX_NOMBRE 50
#define MULT_DEFENSA_DRAGON 2
#define MULT_ORO_DRAGON 100

int MAX_LISTA = 3;

typedef enum {
    Cubrificación_masiva,// => 0
    invocacion_vampírica,// => 1

    ataque_quetzalcóatl,// => 2
    fuego_helado,// => 3

    Lluvia_dorada,// => 4
    Rayo_aureo,// => 5

    Ataque_Basico,// => 6
} Ataques;

//srtuck va en el .h del combate


void Imprimir_Lista(Dragon * Lista){
    for(int i = 0; i < MAX_LISTA; i++, Lista++){
        printf("%d,%d,%d,%f,%s\n",Lista->vida,Lista->nivel,Lista->defensa,Lista->oro,Lista->nombre);
    }
}


void ini_dragon(Dragon *num_dragon, int valor_aleatorio, char * nombre1){

    num_dragon -> vida = valor_aleatorio * MULT_VIDA_DRAGON;
    num_dragon -> nivel = valor_aleatorio;
    num_dragon -> defensa = valor_aleatorio * MULT_DEFENSA_DRAGON;
    num_dragon -> oro = valor_aleatorio * MULT_ORO_DRAGON;
    strcpy(num_dragon -> nombre, nombre1);
}

Dragon * lista_dragon(){

    int min, max; 

    Dragon * lista = (Dragon*)malloc(MAX_LISTA*sizeof(Dragon));

    if(lista == NULL){

        printf("ERROR\n");
    }

    int * randomnivel = (int*)malloc(MAX_LISTA*sizeof(int));

    if(randomnivel == NULL){
        printf("ERROR\n");
    }

    srand(time(0));

    min = 1;
    max = 50;

    for (int i = 0; i < MAX_LISTA; ++i){
        randomnivel[i] = (rand() % (max - min + 1)) + min;
    }

    ini_dragon(&lista[0], randomnivel[0], "Iulian Dragoi(El renegado)");
    ini_dragon(&lista[1], randomnivel[1], "Emerson y Jefferson(Dragon bicéfalo)");
    ini_dragon(&lista[2], randomnivel[2], "Lory Money(El dragon de oro)");

    return lista;

}

Dragon * añadir_dragon(Dragon * lista_dragones_antigua){

    int vida,nivel,defensa,oro,sum = 1;
    char nombre[MAX_NOMBRE];

    Dragon * dragon_nuevo = (Dragon *)realloc(lista_dragones_antigua, (MAX_LISTA+sum)*sizeof(Dragon));
       
    if(dragon_nuevo == NULL){
        exit(EXIT_FAILURE);
    }

    for (int i = MAX_LISTA; i < (MAX_LISTA + sum); ++i){
       
        printf("Vida del dragon:");
        scanf("%d", &vida);

        printf("Nivel del dragon:");
        scanf("%d", &nivel);

        printf("Cantidad de defensa:");
        scanf("%d", &defensa);

        printf("Cantidad de oro:");
        scanf("%d", &oro);

        printf("Nombre del dragon:");
        scanf(" ");
        fgets(nombre, MAX_NOMBRE, stdin);
        nombre[strlen(nombre)-1] = '\0';

        ini_dragon(&dragon_nuevo[i], nivel, nombre);
    }

    MAX_LISTA += sum;

    printf("Nueva lista de dragones:\n");
    Imprimir_Lista(dragon_nuevo);

    return dragon_nuevo;
}
