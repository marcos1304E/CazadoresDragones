#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cazadores.h"
#include "dragon.h"
#include "combate.h"
#include "utilidades.h"


/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

void category(Ataques ataque) {
    switch (ataque) {
        case Cubrificacion_masiva: printf("Cubrificación masiva\n"); break;
        case Fuego_helado: printf("Fuego helado\n"); break;
        case Lluvia_dorada: printf("Lluvia dorada\n"); break;
        case Navajazo: printf("Navajazo\n"); break;
        case LLama_a_los_presis: printf("LLama a los presis\n"); break;
        case Chiquibai: printf("Chiquibai\n"); break;
        default: printf("Ataque Basico\n"); break;
    }
}

void ataque_dragon(Dragon *dragon, Cazador *cazador) {
    int min = 0, max = 10;
    int random_ataque, random_critico;

    srand(time(0));
    random_ataque = rand() % (max - min + 1) + min;
    random_critico = rand() % (max - min + 1) + min;

    printf("\nEl dragón %s ataca!\n", dragon->nombre);

    int dano_base = dragon->nivel * 5;
    if (random_ataque == 0) {
        printf("Ataque especial del dragón!\n");
        cazador->vida -= dano_base * 2;  // Ataque especial más fuerte
    } else {
        if (random_critico > 7) {
            printf("¡Golpe crítico del dragón!\n");
            cazador->vida -= dano_base * 1.5;
        } else {
            printf("Ataque básico del dragón.\n");
            cazador->vida -= dano_base;
        }
    }
    printf("Vida restante del cazador: %d\n", cazador->vida);
}

int ataque_cazador(Cazador *cazador, Dragon *dragon) {
    int cazador_menu;
    int random_critico_cazador;
    int n_ataque;
    int menu_inventario;
    
    // Opciones de acción
    printf("\n===== COMBATE =====\n");
    printf("1. Atacar\n");
    printf("2. Usar objeto\n");
    printf("3. Huir\n");
    printf("Elige una acción: ");
    printf("\n===== ======= =====\n");

    scanf("%d", &cazador_menu);

    if(cazador_menu == 1 || cazador_menu == 2){    
        switch(cazador_menu){
            case 1:  // Selección de ataque
                srand(time(0));  // Solo se llama una vez al inicio
                int min = 0, max = 10;
                random_critico_cazador = (rand() % (max - min + 1)) + min;

                printf("\n===== ⚔️ ATAQUE ⚔️ =====\n");
                printf("1. Ataque especial\n ");
                printf("2. Ataque básico\n ");
                printf("\n===== == ======= == =====\n");
                scanf("%d", &n_ataque);

                // Realiza el ataque
                switch(n_ataque){
                    case 1:
                        if (random_critico_cazador > 7) {
                            printf("¡Golpe crítico del cazador! ¡Mucho daño al dragón!\n");
                            dragon->vida -= cazador->defensa * 2;  // Golpe crítico
                        } else {
                            printf("Ataque especial de %s.\n", cazador->nombre);
                            dragon->vida -= cazador->defensa * 1.5;  // Ataque especial
                        }
                        break;
                    case 2:
                        if (random_critico_cazador > 7) {
                            printf("¡Golpe crítico del cazador! ¡Mucho daño al dragón!\n");
                            dragon->vida -= cazador->defensa * 2;  // Golpe crítico
                        } else {
                            printf("Ataque básico de %s.\n", cazador->nombre);
                            dragon->vida -= cazador->defensa;  // Daño básico
                        }
                        break;
                    default:
                        printf("Opción de ataque no válida.\n");
                        break;
                }
                break;
            case 2:  // Menú de inventario
                printf("\nInventario:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s (x%d)\n", i + 1, inventario[i].nombre, inventario[i].cantidad);
                }
                printf("6. Volver\n");
                printf("Elige un objeto: ");
                int obj;
                scanf("%d", &obj);
                if (obj >= 1 && obj <= 5) {
                    usar_objeto(cazador, &inventario[obj - 1]);
                }
                break;

            case 3:  // Escapar
                printf("Has decidido escapar del combate.\n");
                break;
            default:
                printf("Por favor introduce un valor válido(1,2,3).\n");
                break;
        }
    } else {
        printf("Por favor introduce un valor válido(1,2,3), Gracias.\n");
    }
    return 0;
}

void turnos(Cazador *cazador, Dragon *dragon) {
    int turno = 1;  // 1: turno del cazador, 0: turno del dragón
    int vidaCazador = cazador->vida;
    int vidaDragon = dragon->vida;

    srand(time(0));  // Inicializamos el generador de números aleatorios

    // Bucle de combate
    while (vidaCazador > 0 && vidaDragon > 0) {
        if (turno == 1) {
            // Turno del cazador
            printf("Es el turno de %s (Cazador).\n", cazador->nombre);
            // Aquí puedes llamar a la función de ataque del cazador
            ataque_cazador(cazador, dragon);  // Aquí debería estar la función para que el cazador ataque
            vidaDragon = dragon->vida; // Actualiza la vida del dragón después del ataque
            printf("Vida del dragón después del ataque: %d\n", vidaDragon);
            turno = 0; // Cambiar al turno del dragón
        } else {
            // Turno del dragón
            printf("Es el turno de %s (Dragón).\n", dragon->nombre);
            // Aquí puedes llamar a la función de ataque del dragón
            ataque_dragon(dragon, cazador);  // Aquí debería estar la función para que el dragón ataque
            vidaCazador = cazador->vida; // Actualiza la vida del cazador después del ataque
            printf("Vida del cazador después del ataque: %d\n", vidaCazador);
            turno = 1; // Cambiar al turno del cazador
        }
    }

    // Fin del combate
    if (vidaCazador <= 0) {
        printf("¡El cazador %s ha perdido el combate!\n", cazador->nombre);
    } else if (vidaDragon <= 0) {
        printf("¡El dragón %s ha perdido el combate!\n", dragon->nombre);

        //Ahora el cazador gana el oro del dragón en cada victoria
        cazador->oro += dragon->oro;
        printf("¡%s ha ganado %d de oro!\n", cazador->nombre, dragon->oro);

    }
}
