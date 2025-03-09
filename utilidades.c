#include <stdio.h>
#include "utilidades.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

void tienda(Cazador *cazador) {
    int opcion;
    int oro = cazador->oro;  // Suponiendo que cada cazador tiene una cantidad de oro

    do {
        printf("\n===== 🛒 TIENDA DEL CAZADOR 🛒 =====\n");
        printf("1. Poción de vida (+20 HP) - 50 Oro\n");
        printf("2. Armadura ligera (+10 Defensa) - 100 Oro\n");
        printf("3. Espada afilada (+15 Ataque) - 150 Oro\n");
        printf("4. Salir de la tienda\n");
        printf("Tu oro actual: %d\n", oro);
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (oro >= 50) {
                    cazador->vida += 20;
                    oro -= 50;
                    printf("Has comprado una Poción de vida. Vida actual: %d\n", cazador->vida);
                } else {
                    printf("No tienes suficiente oro.\n");
                }
                break;
            case 2:
                if (oro >= 100) {
                    cazador->defensa += 10;
                    oro -= 100;
                    printf("Has comprado una Armadura ligera. Defensa actual: %d\n", cazador->defensa);
                } else {
                    printf("No tienes suficiente oro.\n");
                }
                break;
            case 3:
                if (oro >= 150) {
                    cazador->ataque += 15;
                    oro -= 150;
                    printf("Has comprado una Espada afilada. Ataque actual: %d\n", cazador->ataque);
                } else {
                    printf("No tienes suficiente oro.\n");
                }
                break;
            case 4:
                printf("Saliendo de la tienda...\n");
                break;
            default:
                printf("Opción no válida, intenta de nuevo.\n");
        }
    } while (opcion != 4);

    cazador->oro = oro;  // Guardamos la cantidad de oro restante
}
