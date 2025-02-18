#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

#define MAX_NOMBRE 50
#define MULT_VIDA_DRAGON 2

int MAX_LISTA = 3;


//srtuck va en el .h del main

typedef struct{
    int vida;
    int nivel;
    int defensa;
    float oro;
    char nombre[MAX_NOMBRE];
}Dragon;

void Imprimir_Lista(Dragon * Lista){
    for(int i = 0; i < MAX_LISTA; i++, Lista++){
        printf("%d,%d,%d,%.2f,%s\n",Lista->vida,Lista->nivel,Lista->defensa,Lista->oro,Lista->nombre);
    }
}

/*
    ini_dragon(&lista[0],(10*randomnivel[0]), randomnivel[0], (2*randomnivel[0]), (100*randomnivel[0]), "Iulian Dragoi(El renegado)");
    ini_dragon(&lista[1],(10*randomnivel[0]), randomnivel[1], (2*randomnivel[0]), (100*randomnivel[0]), "Emerson y Jefferson(Dragon bicéfalo)");
    ini_dragon(&lista[2],(10*randomnivel[0]), randomnivel[2], (2*randomnivel[0]), (1000*randomnivel[0]), "Lory Money(El dragon de oro)");

void ini_dragon_inicial(Dragon *num_dragon, int valor_aleatorio){

    num_dragon -> vida = valor_aleatorio * MULT_VIDA_DRAGON;
    num_dragon -> nivel = nivel1;
    num_dragon -> defensa = defensa1;
    num_dragon -> oro = oro1;
    strcpy(num_dragon -> nombre, nombre1);
}
*/

void ini_dragon(Dragon *num_dragon, int vida1, int nivel1, int defensa1, float oro1, char * nombre1){

    num_dragon -> vida = vida1;
    num_dragon -> nivel = nivel1;
    num_dragon -> defensa = defensa1;
    num_dragon -> oro = oro1;
    strcpy(num_dragon -> nombre, nombre1);
}

Dragon * añadir_dragon(Dragon * nuevoDragon){

int vida,nivel,defensa,sum = 1;
float oro;
char nombre[MAX_NOMBRE];

Dragon * dragon_nuevo = (Dragon*)realloc(nuevoDragon, (MAX_LISTA+sum)*sizeof(Dragon));
   
    if(dragon_nuevo == NULL){ //verificamos si el nuevo catalogo en nullo
        free(dragon_nuevo);
        exit(EXIT_FAILURE);
    }

    for (int i = MAX_LISTA; i < MAX_LISTA + sum; ++i){ //Bucle que pide el contenido del libro en base a los libros que queramos agregar
       
        printf("Vida del dragon:");
        scanf("%d", &vida);

        printf("Nivel del dragon:");
        scanf("%d", &nivel);

        printf("Cantidad de defensa:");
        scanf("%d", &defensa);

        printf("Cantidad de oro:");
        scanf("%f", &oro);

        printf("Nombre del dragon:");
        scanf(" ");
        fgets(nombre, MAX_LISTA, stdin);
        nombre[strlen(nombre)-1] = '\0';

        ini_dragon(&dragon_nuevo[i],vida, nivel, defensa, oro, nombre);
    }

    MAX_LISTA += sum;

    printf("Nueva lista de dragones:\n");
    Imprimir_Lista(nuevoDragon);

    return nuevoDragon;
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

    for (int i = 0; i < 3; ++i){
        randomnivel[i] = (rand() % (max - min + 1)) + min;
    }

    ini_dragon(&lista[0],(10*randomnivel[0]), randomnivel[0], (2*randomnivel[0]), (100*randomnivel[0]), "Iulian Dragoi(El renegado)");
    ini_dragon(&lista[1],(10*randomnivel[1]), randomnivel[1], (2*randomnivel[1]), (100*randomnivel[1]), "Emerson y Jefferson(Dragon bicéfalo)");
    ini_dragon(&lista[2],(10*randomnivel[2]), randomnivel[2], (2*randomnivel[2]), (1000*randomnivel[2]), "Lory Money(El dragon de oro)");

    return lista;
}


int main() {
    Dragon *lista = lista_dragon();
    if (lista == NULL) {
        return EXIT_FAILURE;
    }

    printf("Lista inicial de dragones:\n");
    Imprimir_Lista(lista);

    lista = añadir_dragon(lista);
    if (lista == NULL) {
        return EXIT_FAILURE;
    }

    free(lista);
    return 0;
}