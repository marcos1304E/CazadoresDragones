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

Dragon *añadir_dragon(Dragon *lista_dragones_antigua) {
    int vida, nivel, defensa, oro, sum = 1;
    char nombre[MAX_NOMBRE];

    // Reasignar memoria para un nuevo dragón
    Dragon *dragon_nuevo = (Dragon *)realloc(lista_dragones_antigua, (MAX_LISTA + sum) * sizeof(Dragon));
    
    if (dragon_nuevo == NULL) {
        printf("Error al reasignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    // Ingresar el nuevo dragón
    for (int i = MAX_LISTA; i < (MAX_LISTA + sum); ++i) {
        // Control de errores para la vida
        do {
            printf("Vida del dragón (debe ser mayor que 0): ");
            scanf("%d", &vida);
            if (vida < 1) {
                printf("La vida tiene que ser positiva. Intenta de nuevo.\n");
            }
        } while (vida < 1);

        // Ingresar nivel
        printf("Nivel del dragón: ");
        scanf("%d", &nivel);

        // Control de errores para la defensa
        do {
            printf("Cantidad de defensa (debe ser mayor que 0): ");
            scanf("%d", &defensa);
            if (defensa < 1) {
                printf("La defensa tiene que ser positiva. Intenta de nuevo.\n");
            }
        } while (defensa < 1);

        // Control de errores para el oro
        do {
            printf("Cantidad de oro (debe ser mayor que 0): ");
            scanf("%d", &oro);
            if (oro < 1) {
                printf("El oro tiene que ser positivo. Intenta de nuevo.\n");
            }
        } while (oro < 1);

        // Ingresar nombre del dragón
        printf("Nombre del dragón: ");
        scanf(" "); // Limpiar el buffer
        fgets(nombre, MAX_NOMBRE, stdin);
        nombre[strlen(nombre) - 1] = '\0'; // Eliminar el salto de línea al final

        // Inicializar el dragón
        ini_dragon(&dragon_nuevo[i], nivel, nombre);
    }

    // Incrementar el tamaño de la lista
    MAX_LISTA += sum;

    // Imprimir la lista de dragones
    printf("Nueva lista de dragones:\n");
    Imprimir_Lista(dragon_nuevo);

    return dragon_nuevo;
}


int main() {
    // Crear una lista inicial de dragones
    Dragon *lista_dragones = lista_dragon();

    // Imprimir la lista de dragones inicial
    printf("Lista de dragones inicial:\n");
    Imprimir_Lista(lista_dragones);

    // Preguntar al usuario si desea añadir un nuevo dragón
    char respuesta;
    printf("¿Deseas agregar un nuevo dragón? (s/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 's' || respuesta == 'S') {
        lista_dragones = añadir_dragon(lista_dragones);
    }

    // Imprimir la lista final de dragones
    printf("Lista final de dragones:\n");
    Imprimir_Lista(lista_dragones);

    // Liberar memoria
    free(lista_dragones);

    return 0;
}