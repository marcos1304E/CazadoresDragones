#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cazadores.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

void imprimir_lista(Cazador *lista, int numCazadores) {
    printf("\nLista de Cazadores:\n");
    for (int i = 0; i < numCazadores; i++) {
        printf("Cazador %d: %s | Vida: %d | Defensa: %d | Oro: %d\n",
               i + 1, lista[i].nombre, lista[i].vida, lista[i].defensa, lista[i].oro);
    }
}


void inicializarCazador(Cazador *cazador, char *nombre, int vida, int defensa, int oro) {
    strcpy(cazador->nombre, nombre);
    cazador->vida = vida;
    cazador->defensa = defensa;
    cazador->oro = oro;
}

Cazador *lista_cazadores(int *numCazadores) {
    *numCazadores = 3;  // Número inicial de cazadores
    Cazador *lista = (Cazador *)malloc((*numCazadores) * sizeof(Cazador));

    if (lista == NULL) {
        printf("Error al asignar memoria para los cazadores.\n");
        exit(EXIT_FAILURE);
    }

    printf("Inicializando cazadores...\n");
    inicializarCazador(&lista[0], "El Vaquilla", 100, 20, 50);
    inicializarCazador(&lista[1], "El Pequeño Nicolás", 120, 15, 40);
    inicializarCazador(&lista[2], "Gigante Noble", 150, 25, 60);

    return lista;
}

Cazador *agregarCazador(Cazador *lista, int *numCazadores) {
    // Aumentar la cantidad de cazadores
    (*numCazadores)++;

    // Reasignar memoria para la lista de cazadores
    lista = (Cazador*) realloc(lista, (*numCazadores) * sizeof(Cazador));

    if (lista == NULL) {
        printf("Error en la asignación de memoria.\n");
        free(lista);
        exit(EXIT_FAILURE);
       
    }

    // Solicitar y validar el nombre del cazador
    printf("Introduce el nombre del cazador (máximo 49 caracteres): ");
    scanf("%49s", lista[*numCazadores - 1].nombre);

    // Solicitar y validar la vida del cazador
    do {
        printf("Introduce la vida del cazador (debe ser mayor que 0): ");
        scanf("%d", &lista[*numCazadores - 1].vida);
        if (lista[*numCazadores - 1].vida < 1 || lista[*numCazadores -1].vida > 200) {
            printf("La vida debe estar entre 1 y 200. Intenta de nuevo.\n");
        }
    } while (lista[*numCazadores - 1].vida < 1 || lista[*numCazadores -1].vida > 200);

    // Solicitar y validar la defensa del cazador
    do {
        printf("Introduce la defensa del cazador (1 - 80): ");
        scanf("%d", &lista[*numCazadores - 1].defensa);
        if (lista[*numCazadores - 1].defensa < 1 || lista[*numCazadores - 1].defensa > 80) {
            printf("La defensa debe estar entre 1 y 80. Intenta de nuevo.\n");
        }
    } while (lista[*numCazadores - 1].defensa < 1 || lista[*numCazadores - 1].defensa > 80);

    printf("¡Cazador añadido con éxito!\n");

    return lista; 
}


/*int main() {

    int numCazadores = MAX_CAZADORES;

    Cazador *lista = lista_cazadores();

    imprimir_lista(lista, numCazadores);
    
    printf("\nAgregando un nuevo cazador...\n");
    lista = agregarCazador(lista, &numCazadores);
    
    imprimir_lista(lista, numCazadores);

    free(lista);
    
    return 0;
}
*/