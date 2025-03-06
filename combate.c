#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cazador.h"
#include "dragon.h"

/*
 *  Autor: Leo-nardo Marescutti, David Castejon y Marcos Escamilla
 */

typedef enum {
    Cubrificación_masiva,// => 0
    Ataque_Basico,// => 1
} Ataques_Dragon;

typedef enum {
    Fuego_helado,// => 0
    Ataque_Basico,// => 1
} Ataques_Dragon1;

typedef enum {
    Lluvia_dorada,// => 0
    Ataque_Basico,// => 1
} Ataques_Dragon2;

typedef enum {
    Navajazo,// => 0
    Ataque_Basico,// => 1
} Ataques_Cazador1;

typedef enum {
    LLama_a_los_presis,// => 0
    Ataque_Basico,// => 1
} Ataques_Cazador2;

typedef enum {
    Chiquibai,// => 0
    Ataque_Basico,// => 1
} Ataques_Cazador3;


void category(int ataque){

    switch(ataque){
        case 0:printf("Cubrificación masiva");
            break; 
        default:printf("Ataque Basico");
    }
}

void category(int ataque){

    switch(ataque){
        case 0:printf("Fuego helado");
            break; 
        default:printf("Ataque Basico");
    }
}

void category(int ataque){

    switch(ataque){
        case 0:printf("Lluvia dorada");
            break; 
        default:printf("Ataque Basico");
    }
}


int ataque_dragon(){

    int random_ataque;
    int random_critico;

    srand(time(0));

    min = 0;
    max = 10;

    random_ataque = (rand() % (max - min + 1)) + min;
    
    if(){
        
        
        
    }
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
                                                         