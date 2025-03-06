#include <stdio.h>
#include <stdlib.h>
#include "cazadores.h"
#include "dragon.h"

void menu(Cazador *lista, int *numCazadores, Dragon *listaDragones, int *numDragones) {
    int opcion;
    do {
        printf("\nMenú:\n");
        printf("1. Ver lista de cazadores\n");
        printf("2. Elegir un cazador\n");
        printf("3. Agregar un cazador\n");
        printf("4. Ver lista de dragones\n");
        printf("5. Elegir un dragón para luchar\n");
        printf("6. Agregar un dragón\n");
        printf("7. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimir_lista(lista, *numCazadores);
                break;
            case 2: {
                int eleccion;
                imprimir_lista(lista, *numCazadores);
                printf("Elige un cazador (1-%d): ", *numCazadores);
                scanf("%d", &eleccion);
                if (eleccion >= 1 && eleccion <= *numCazadores) {
                    printf("Has elegido a %s\n", lista[eleccion - 1].nombre);
                } else {
                    printf("Selección inválida\n");
                }
                break;
            }
            case 3:
                lista = agregarCazador(lista, numCazadores);
                break;
            case 4:
                Imprimir_Lista(listaDragones);
                break;
            case 5: {
                int eleccion;
                Imprimir_Lista(listaDragones);
                printf("Elige un dragón para luchar (1-%d): ", *numDragones);
                scanf("%d", &eleccion);
                if (eleccion >= 1 && eleccion <= *numDragones) {
                    printf("Vas a luchar contra %s\n", listaDragones[eleccion - 1].nombre);
                } else {
                    printf("Selección inválida\n");
                }
                break;
            }
            case 6:
                listaDragones = añadir_dragon(listaDragones);
                (*numDragones)++;
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida, intenta de nuevo.\n");
        }
    } while (opcion != 7);
}



int main(){

	 Cazador *listaCazadores = NULL;  // Inicializa la lista de cazadores
    int numCazadores = 0;  // Número de cazadores
    Dragon *listaDragones = NULL;  // Inicializa la lista de dragones
    int numDragones = 0;  // Número de dragones

    // Puedes inicializar listas o realizar operaciones adicionales aquí, si es necesario.

    menu(listaCazadores, &numCazadores, listaDragones, &numDragones);

    // Liberar memoria si es necesario
    free(listaCazadores);
    free(listaDragones);

    return 0;
}

/*int opcion;

    printf("Seleccione una opción\n\
        1.");

    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    */