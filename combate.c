#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cazador.h"
#include "dragon.h"

typedef enum {
    Cubrificación_masiva,// => 0
    invocacion_vampírica,// => 1

    ataque_quetzalcóatl,// => 2
    fuego_helado,// => 3

    Lluvia_dorada,// => 4
    Rayo_aureo,// => 5

    Ataque_Basico,// => 6
} Ataques_Dragon;

typedef enum {
    Cubrificación_masiva,// => 0
    invocacion_vampírica,// => 1

    ataque_quetzalcóatl,// => 2
    fuego_helado,// => 3

    Lluvia_dorada,// => 4
    Rayo_aureo,// => 5

    Ataque_Basico,// => 6
} Ataques_Cazador;

/*
 *  Autor: Leo-nardo Marescutti, David Castejon y Marcos Escamilla
 */

int ataque_dragon(){

    //ataques
        //ataque basico+nivel (con posibilidad de critico)
        //cada 3 turnos ataque especial
}

int ataque_cazador(){

    //ataques
        //ataque basico
        //cada 1 turnos ataque especial

    //items (con posibilidad de critico)
        //despliegue objetos
        //seleccionar objeto con swich (1,2,3,4,5...)
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
                                                         