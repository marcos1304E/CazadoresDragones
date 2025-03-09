#include <stdio.h>
#include <stdlib.h>
#include "cazadores.h"
#include "dragon.h"
#include "combate.h"
#include "utilidades.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

void menu(Cazador *listaCazadores, int *numCazadores, Dragon *listaDragones, int *numDragones) {
    int opcion;
    do {
        printf("\n====================================\n");
        printf("       🏰 MENU PRINCIPAL 🏰       \n");
        printf("====================================\n");
        printf("1️⃣  🏹  Ver lista de cazadores\n");
        printf("2️⃣  🔥  Ver lista de dragones\n");
        printf("3️⃣  🆕  Agregar cazador\n");
        printf("4️⃣  🐉  Agregar dragón\n");
        printf("5️⃣  ⚔️  Ir a Combate\n");
        printf("6️⃣  🛒  Ir a la Tienda\n");
        printf("7️⃣  ❌  Salir del juego\n");
        printf("====================================\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimir_lista(listaCazadores, *numCazadores);
                break;
            case 2:
                Imprimir_Lista(listaDragones, *numDragones);
                break;
            case 3:
                listaCazadores = agregarCazador(listaCazadores, numCazadores);
                break;
            case 4:
                listaDragones = añadir_dragon(listaDragones, numDragones);
                break;
            case 5:
                if (*numCazadores > 0 && *numDragones > 0) {
                    int cazadorIdx, dragonIdx;
                    imprimir_lista(listaCazadores, *numCazadores);
                    printf("Elige un cazador (1-%d): ", *numCazadores);
                    scanf("%d", &cazadorIdx);

                    Imprimir_Lista(listaDragones, *numDragones);
                    printf("Elige un dragón (1-%d): ", *numDragones);
                    scanf("%d", &dragonIdx);

                    if (cazadorIdx >= 1 && cazadorIdx <= *numCazadores && dragonIdx >= 1 && dragonIdx <= *numDragones) {
                        printf("¡%s se enfrenta a %s!\n", listaCazadores[cazadorIdx - 1].nombre, listaDragones[dragonIdx - 1].nombre);
                        turnos(&listaCazadores[cazadorIdx - 1], &listaDragones[dragonIdx - 1]);
                    } else {
                        printf("❌ Selección inválida.\n");
                    }
                } else {
                    printf("⚠️ No hay suficientes cazadores o dragones para combatir.\n");
                }
                break;
            case 6:
                if (*numCazadores > 0) {
                    int cazadorIdx;
                    imprimir_lista(listaCazadores, *numCazadores);
                    printf("Elige un cazador para ir a la tienda (1-%d): ", *numCazadores);
                    scanf("%d", &cazadorIdx);

                    if (cazadorIdx >= 1 && cazadorIdx <= *numCazadores) {
                        tienda(&listaCazadores[cazadorIdx - 1]);
                    } else {
                        printf("❌ Selección inválida.\n");
                    }
                } else {
                    printf("⚠️ No hay cazadores disponibles para la tienda.\n");
                }
                break;
            case 7:
                printf("Saliendo del juego... 🏰\n");
                break;
            default:
                printf("❌ Opción no válida, intenta de nuevo.\n");
        }
    } while (opcion != 7);
}

int main() {
    Cazador *listaCazadores = NULL;
    int numCazadores = 0;
    Dragon *listaDragones = NULL;
    int numDragones = 0;

    listaCazadores = lista_cazadores(&numCazadores);
    listaDragones = lista_dragon(&numDragones);

    menu(listaCazadores, &numCazadores, listaDragones, &numDragones);

    free(listaCazadores);
    free(listaDragones);

    return 0;
}
