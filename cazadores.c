#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAZADORES 3
/*Marcos*/

typedef struct{
	char nombre [50];
	char habilidad[50];
	int vida;
	int dano;
} Cazador;


void inicializarCazadores(Cazador * nuevoCazador, char * nombre1, char *habilidad1, int vida1, int dano1) {

    printf("Inicializando cazador ...\n");

   	nuevoCazador -> vida = vida1;
   	nuevoCazador -> dano = dano1;
   	strcpy(nuevoCazador -> nombre, nombre1);
   	strcpy(nuevoCazador -> habilidad, habilidad1);
   }



Cazador * lista_cazadores(void){

Cazador * lista= (Cazador *)malloc(MAX_CAZADORES * sizeof(Cazador));

if (lista == NULL)
{
	printf("Error en la asignación de memoria");
	exit(EXIT_FAILURE);
}


	inicializarCazadores(&lista[0],"El Vaquilla","navajazo",1234,1234);
	inicializarCazadores(&lista[1],"El Pequeño Nicolás","LLama a los presis",1234,1234);
	inicializarCazadores(&lista[2],"cazadorX","habilidad1",1234,1234);
	return lista;

}

Cazador * agregarCazador(Cazador * nuevoCazador){

	//Malloc de Cazador * nuevo

	printf("Introduce el nombre del cazador:");
	scanf("%49s", nuevoCazador -> nombre);


}
