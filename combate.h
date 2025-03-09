
#ifndef COMBATE_H
#define COMBATE_H

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


void category(Ataques ataque);
void ataque_dragon(Dragon *dragon, Cazador *cazador);
int ataque_cazador(Cazador *cazador, Dragon *dragon);
void turnos(Cazador *cazador, Dragon *dragon);  // Declaración de la función

#endif
