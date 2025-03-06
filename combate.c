#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cazadores.h"
#include "dragon.h"

/*
 *  Autor: Leonardo Marescutti, David Castejon y Marcos Escamilla
 */

typedef enum {
    Cubrificacion_masiva,
    Fuego_helado,
    Lluvia_dorada,
    Navajazo,
    LLama_a_los_presis,
    Chiquibai,
    Ataque_Basico
} Ataques;

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

int ataque_cazador(){

    int cazador_menu;
    int random_critico_cazador;
    int n_ataque;
    int menu_inventario;
    int 1 = 5;
    int 2 = 1;
    int 3 = 3;
    int 4 = 1;
    int 5 = 1;

    printf("Selecciona que hacer:\n");
    printf("1 Ataque\n ");
    printf("2 Inventario\n ");
    printf("3 Escapar\n ");

    scanf("%d", cazador_menu);

    if(cazador_menu == 1 || cazador_menu == 2){    
        switch(cazador_menu){

            case 1:

                srand(time(0));

                min = 0;
                max = 10;

                random_critico_cazador = (rand() % (max - min + 1)) + min;
                
                printf("Selecciona un ataque:\n");
                printf("1 Ataque especial\n ");
                printf("2 Ataque basico\n ");

                scanf("%d", &n_ataque);
                if(cazador_menu == 1 || cazador_menu == 2){
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
            }
            case 2:

                printf("Inventario:\n");
                printf("1. Poción herbovitalizante (%d)\n ",1);
                printf("2. Galleta celestial (%d)\n ",2);
                printf("3. Explosivo demoniaco (%d)\n ",3);
                printf("4. Varita de hiperrayos magicos de guerra mundiales explosivos (%d)\n ",4);
                printf("5. Doble elefante telepata de guerra (%d)\n ",5);
                printf("6. Volver atras");

                scanf("%d", menu_inventario);
                if(cazador_menu < 7 && cazador_menu >= 0){
                    switch(menu_inventario){

                        case 1:
                            //Poción herbovitalizante
                        break;
                            
                        case 2:
                            //Galleta celestial
                        break;

                        case 3:
                            //Explosivo demoniaco
                        break;

                        case 4:
                            //Varita de hiperrayos magicos de guerra mundiales explosivos genericos chinos explotados
                        break;

                        case 5:
                            //Doble elefante telepata de guerra
                        break;
                    }
                }
            break;
        }

    }else{printf("Por Favor introduce un valor valido(1,2,3), Gracias");}
}
        int turnos(){

            do{

                //ataque cazador(turno)

                //ataque dragon(turno)

            }while(/*Vida de Cazador != 0*/||/*Vida de Dragon != 0*/);

            if (/*Vida de Cazador == 0*/){

                //llamar (utilidades())

            }

    return ;
}
                                                         