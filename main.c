#include <stdio.h>
#include <stdlib.h>
#include "cazadores.h"
#include "dragon.h"
#include "combate.h"
#include "utilidades.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

//Menu principal
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
        scanf("%d", &opcion);//Y leemos opcion ingresada por el usuario

        switch (opcion) {
            case 1:
                system("clear");//Limpiamos pantalla
                imprimir_lista(listaCazadores, *numCazadores);//Muestra lista de cazadores
                break;
            case 2:
                system("clear");
                Imprimir_Lista(listaDragones, *numDragones);//Muestra lista de dragones
                break;
            case 3:
                system("clear");
                listaCazadores = agregarCazador(listaCazadores, numCazadores);//Agrega un nuevo cazador
                break;
            case 4:
                system("clear");
                listaDragones = añadir_dragon(listaDragones, numDragones);//Agrega un nuevo dragón
                break;
            case 5:
                system("clear");

                if (*numCazadores > 0 && *numDragones > 0) {
                    int cazadorIdx, dragonIdx;
                    imprimir_lista(listaCazadores, *numCazadores);//Muestra lista cazadores
                    printf("Elige un cazador (1-%d): ", *numCazadores);
                    scanf("%d", &cazadorIdx);
                    
                    Imprimir_Lista(listaDragones, *numDragones);//Muestra lista dragones
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
                system("clear");
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
                system("clear");
                printf("Saliendo del juego... 🏰\n");
                break;
            default:
                system("clear");
                printf("❌ Opción no válida, intenta de nuevo.\n");
        }
    } while (opcion != 7);//Repite el menu hasta que el usuario elija salir
}

int main() {
    Cazador *listaCazadores = NULL;
    int numCazadores = 0;
    Dragon *listaDragones = NULL;
    int numDragones = 0;
//Inicializamos listas de cazadores y dragones
    listaCazadores = lista_cazadores(&numCazadores);
    listaDragones = lista_dragon(&numDragones);
//LLamamos a funcion del menú principal
    menu(listaCazadores, &numCazadores, listaDragones, &numDragones);
//Liberamos memoria
    free(listaCazadores);
    free(listaDragones);

    return 0;
}
