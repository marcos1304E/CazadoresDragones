#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "colores.h"
#include "cazadores.h"
#include "dragon.h"
#include "combate.h"
#include "utilidades.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

void category(Ataques ataque) {
    switch (ataque) {
        case Cubrificacion_masiva: 
            imprimir_con_color(COLOR_ATACAR, "Cubrificación masiva\n"); 
            break;
        case Fuego_helado: 
            imprimir_con_color(COLOR_ATACAR, "Fuego helado\n"); 
            break;
        case Lluvia_dorada: 
            imprimir_con_color(COLOR_ATACAR, "Lluvia dorada\n"); 
            break;
        case Navajazo: 
            imprimir_con_color(COLOR_ATACAR, "Navajazo\n"); 
            break;
        case LLama_a_los_presis: 
            imprimir_con_color(COLOR_ATACAR, "LLama a los presis\n"); 
            break;
        case Chiquibai: 
            imprimir_con_color(COLOR_ATACAR, "Chiquibai\n"); 
            break;
        default: 
            imprimir_con_color(COLOR_ATACAR, "Ataque Basico\n"); 
            break;
    }
}

void ataque_dragon(Dragon *dragon, Cazador *cazador) {
    int min = 0, max = 10;
    int random_ataque, random_critico;

    srand(time(0));
    random_ataque = rand() % (max - min + 1) + min;
    random_critico = rand() % (max - min + 1) + min;

    imprimir_con_color(COLOR_MENU, "\nEl dragón %s ataca!\n", dragon->nombre);

    int dano_base = dragon->nivel * 5;
    if (random_ataque == 0) {
        imprimir_con_color(COLOR_DANO, "Ataque especial del dragón!\n");
        cazador->vida -= dano_base * 2;  // Ataque especial más fuerte
    } else {
        if (random_critico > 7) {
            imprimir_con_color(COLOR_DANO, "¡Golpe crítico del dragón!\n");
            cazador->vida -= dano_base * 1.5;
        } else {
            imprimir_con_color(COLOR_DANO, "Ataque básico del dragón.\n");
            cazador->vida -= dano_base;
        }
    }
    imprimir_con_color(COLOR_VIDA, "Vida restante del cazador: %d\n", cazador->vida);
}

int ataque_cazador(Cazador *cazador, Dragon *dragon) {
    int cazador_menu;
    int random_critico_cazador;
    int n_ataque;
    
    // Opciones de acción
    imprimir_con_color(COLOR_MENU, "\n===== COMBATE =====\n");
    imprimir_con_color(COLOR_MENU, "1. Atacar\n");
    imprimir_con_color(COLOR_MENU, "2. Usar objeto\n");
    imprimir_con_color(COLOR_MENU, "3. Huir\n");
    imprimir_con_color(COLOR_MENU, "Elige una acción: ");
    imprimir_con_color(COLOR_MENU, "\n===== ======= =====\n");

    scanf("%d", &cazador_menu);

    if(cazador_menu == 1 || cazador_menu == 2){    
        switch(cazador_menu){
            case 1:  // Selección de ataque
                srand(time(0));  // Solo se llama una vez al inicio
                int min = 0, max = 10;
                random_critico_cazador = (rand() % (max - min + 1)) + min;

                imprimir_con_color(COLOR_ATACAR, "\n===== ⚔️ ATAQUE ⚔️ =====\n");
                imprimir_con_color(COLOR_ATACAR, "1. Ataque especial\n ");
                imprimir_con_color(COLOR_ATACAR, "2. Ataque básico\n ");
                imprimir_con_color(COLOR_ATACAR, "\n===== == ======= == =====\n");
                scanf("%d", &n_ataque);

                // Realiza el ataque
                switch(n_ataque){
                    case 1:
                        if (random_critico_cazador > 7) {
                            imprimir_con_color(COLOR_DANO, "¡Golpe crítico del cazador! ¡Mucho daño al dragón!\n");
                            dragon->vida -= cazador->defensa * 2;  // Golpe crítico
                        } else {
                            imprimir_con_color(COLOR_ATACAR, "Ataque especial de %s.\n", cazador->nombre);
                            dragon->vida -= cazador->defensa * 1.5;  // Ataque especial
                        }
                        break;
                    case 2:
                        if (random_critico_cazador > 7) {
                            imprimir_con_color(COLOR_DANO, "¡Golpe crítico del cazador! ¡Mucho daño al dragón!\n");
                            dragon->vida -= cazador->defensa * 2;  // Golpe crítico
                        } else {
                            imprimir_con_color(COLOR_ATACAR, "Ataque básico de %s.\n", cazador->nombre);
                            dragon->vida -= cazador->defensa;  // Daño básico
                        }
                        break;
                    default:
                        imprimir_con_color(COLOR_ERROR, "Opción de ataque no válida.\n");
                        break;
                }
                break;
            case 2:  // Menú de inventario
                imprimir_con_color(COLOR_MENU, "\nInventario:\n");
                for (int i = 0; i < 5; i++) {
                    // Suponiendo que 'inventario' es un arreglo global definido en utilidades.h
                    printf("%d. %s (x%d)\n", i + 1, inventario[i].nombre, inventario[i].cantidad);
                }
                printf("6. Volver\n");
                imprimir_con_color(COLOR_MENU, "Elige un objeto: ");
                int obj;
                scanf("%d", &obj);
                if (obj >= 1 && obj <= 5) {
                    usar_objeto(cazador, &inventario[obj - 1]);
                }
                break;
            case 3:  // Escapar
                imprimir_con_color(COLOR_MENU, "Has decidido escapar del combate.\n");
                break;
            default:
                imprimir_con_color(COLOR_ERROR, "Por favor introduce un valor válido (1,2,3).\n");
                break;
        }
    } else {
        imprimir_con_color(COLOR_ERROR, "Por favor introduce un valor válido (1,2,3), Gracias.\n");
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
            imprimir_con_color(COLOR_MENU, "Es el turno de %s (Cazador).\n", cazador->nombre);
            ataque_cazador(cazador, dragon);
            vidaDragon = dragon->vida;
            imprimir_con_color(COLOR_VIDA, "Vida del dragón después del ataque: %d\n", vidaDragon);
            turno = 0;
        } else {
            // Turno del dragón
            imprimir_con_color(COLOR_MENU, "Es el turno de %s (Dragón).\n", dragon->nombre);
            ataque_dragon(dragon, cazador);
            vidaCazador = cazador->vida;
            imprimir_con_color(COLOR_VIDA, "Vida del cazador después del ataque: %d\n", vidaCazador);
            turno = 1;
        }
    }

    // Fin del combate
    if (vidaCazador <= 0) {
        imprimir_con_color(COLOR_ERROR, "¡El cazador %s ha perdido el combate!\n", cazador->nombre);
    } else if (vidaDragon <= 0) {
        imprimir_con_color(COLOR_ERROR, "¡El dragón %s ha perdido el combate!\n", dragon->nombre);

        // Ahora el cazador gana el oro del dragón en cada victoria
        cazador->oro += dragon->oro;
        printf("¡%s ha ganado %d de oro!\n", cazador->nombre, dragon->oro);

    }
}
