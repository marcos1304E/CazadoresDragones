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

// INVENTARIO: cantidades limitadas para cada objeto
static int inv_pocion = 5;
static int inv_galleta = 2;
static int inv_explosivo = 3;
static int inv_varita = 1;
static int inv_dobleElefante = 1;

int ataque_cazador(Dragon *dragon, Cazador *cazador) {
	int cazador_menu;
	int random_critico_cazador;
	int n_ataque;
	int menu_inventario;
	int min = 0, max = 10;

	printf("\nSelecciona que hacer:\n");
	printf("1. Ataque\n");
	printf("2. Inventario\n");
	printf("3. Escapar\n");

	scanf("%d", &cazador_menu);

	if(cazador_menu == 1){
		srand(time(NULL));
		random_critico_cazador = rand() % (max - min + 1) + min;
		printf("Selecciona un ataque:\n");
		printf("1. Ataque especial\n");
		printf("2. Ataque básico\n");
		scanf("%d", &n_ataque);
		switch(n_ataque){
			case 1:
				if(random_critico_cazador > 7) {
					printf("¡Golpe crítico del cazador! ¡Mucho daño al dragón!\n");
					dragon->vida -= cazador->defensa * 2;
				} else {
					printf("Ataque especial de %s.\n", cazador->nombre);
					dragon->vida -= cazador->defensa * 1.5;
				}
				break;
			case 2:
				if(random_critico_cazador > 7) {
					printf("¡Golpe crítico del cazador! ¡Mucho daño al dragón!\n");
					dragon->vida -= cazador->defensa * 2;
				} else {
					printf("Ataque básico de %s.\n", cazador->nombre);
					dragon->vida -= cazador->defensa;
				}
				break;
			default:
				printf("Opción de ataque no válida.\n");
				break;
		}
	} else if(cazador_menu == 2) {
		printf("\nInventario:\n");
		printf("1. Poción herbovitalizante (%d disponibles)\n", inv_pocion);
		printf("2. Galleta celestial (%d disponibles)\n", inv_galleta);
		printf("3. Explosivo demoniaco (%d disponibles)\n", inv_explosivo);
		printf("4. Varita de hiperrayos magicos de guerra mundiales explosivos (%d disponibles)\n", inv_varita);
		printf("5. Doble elefante telepata de guerra (%d disponibles)\n", inv_dobleElefante);
		printf("6. Volver atrás\n");
		scanf("%d", &menu_inventario);
		switch(menu_inventario){
			case 1:
				if(inv_pocion > 0){
					printf("Usando Poción herbovitalizante.\n");
					cazador->vida += 50;  // Cantidad de curación
					inv_pocion--;
					printf("Vida del cazador: %d\n", cazador->vida);
				} else {
					printf("No quedan Pócimas herbovitalizantes.\n");
				}
				break;
			case 2:
				if(inv_galleta > 0){
					printf("Usando Galleta celestial.\n");
					cazador->vida += 30;
					inv_galleta--;
					printf("Vida del cazador: %d\n", cazador->vida);
				} else {
					printf("No quedan Galletas celestiales.\n");
				}
				break;
			case 3:
				if(inv_explosivo > 0){
					printf("Usando Explosivo demoniaco.\n");
					dragon->vida -= cazador->defensa * 3;  // Daño extra
					inv_explosivo--;
					printf("Vida del dragón: %d\n", dragon->vida);
				} else {
					printf("No quedan Explosivos demoniacos.\n");
				}
				break;
			case 4:
				if(inv_varita > 0){
					printf("Usando Varita de hiperrayos magicos.\n");
					dragon->vida -= cazador->defensa * 2;
					inv_varita--;
					printf("Vida del dragón: %d\n", dragon->vida);
				} else {
					printf("No queda Varita de hiperrayos magicos.\n");
				}
				break;
			case 5:
				if(inv_dobleElefante > 0){
					printf("Usando Doble elefante telepata de guerra.\n");
					dragon->vida -= cazador->defensa * 4;
					inv_dobleElefante--;
					printf("Vida del dragón: %d\n", dragon->vida);
				} else {
					printf("No queda Doble elefante telepata de guerra.\n");
				}
				break;
			case 6:
				printf("Volviendo al menú principal.\n");
				break;
			default:
				printf("Opción no válida en el inventario.\n");
				break;
		}
	} else if(cazador_menu == 3) {
		printf("Intentas escapar... pero no puedes huir del destino.\n");
	} else {
		printf("Por favor, introduce un valor válido (1,2,3).\n");
	}

	return 0;
}

void turnos(Cazador *cazador, Dragon *dragon) {
	// El combate continúa hasta que la vida del cazador o del dragón sea 0 o menos
	while(cazador->vida > 0 && dragon->vida > 0) {
		printf("\n--- Turno del cazador %s ---\n", cazador->nombre);
		ataque_cazador(dragon, cazador);
		if(dragon->vida <= 0)
			break;
		printf("\n--- Turno del dragón %s ---\n", dragon->nombre);
		ataque_dragon(dragon, cazador);
		if(cazador->vida <= 0)
			break;
		printf("\nEstado actual: Cazador %s: %d vida, Dragón %s: %d vida\n",
				cazador->nombre, cazador->vida, dragon->nombre, dragon->vida);
	}
	if(cazador->vida <= 0) {
		printf("\nEl cazador %s ha caído. Fin del juego.\n", cazador->nombre);
		// Aquí se podría llamar a alguna función de utilidades() para gestionar el fin de partida.
	} else if(dragon->vida <= 0) {
		printf("\nEl dragón %s ha sido derrotado. ¡Victoria del cazador!\n", dragon->nombre);
	}
}

int main() {
	// Inicializar cazadores y dragones usando funciones definidas en los archivos anteriores.
	Cazador *cazadores = lista_cazadores();
	Dragon *dragones = lista_dragon();

	// Usamos el primer cazador y el primer dragón para el combate.
	Cazador *jugador = &cazadores[0];
	Dragon *jefe = &dragones[0];

	printf("El cazador %s inicia con %d vida y %d defensa.\n", jugador->nombre, jugador->vida, jugador->defensa);
	printf("El dragón %s inicia con %d vida, nivel %d y %d defensa.\n", jefe->nombre, jefe->vida, jefe->nivel, jefe->defensa);

	// Iniciar los turnos de combate
	turnos(jugador, jefe);

	// Liberar memoria asignada
	free(cazadores);
	free(dragones);

	return 0;
}

