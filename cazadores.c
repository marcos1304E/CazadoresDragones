#include <stdio.h>
#include <stdlib.h>

#define MAX_CAZADORES 3


typedef struct{
	char nombre [50];
	char habilidad[50];
	int vida;
	int daño;
} Cazador;


void inicializarCazadores(Cazador * num_cazador, char * nombre1, char habilidad1, int vida1, int daño1) {

    printf("Lista de cazadores:\n");

   	num_cazador -> vida = vida1;
   	num_cazador -> daño = daño1;
   	strcpy(num_cazador -> nombre, nombre1);
   	strcpy(num_cazador -> habilidad, habilidad1);
   }



Cazador * lista_cazadores(){


Cazador * lista_cazadores = (Cazador *)malloc(MAX_CAZADORES * sizeof(Cazador));

if (lista_cazadores == NULL)
{
	printf("Error en la asignación de memoria");
	return EXIT_FAILURE;
}


	inicializarCazadores(&lista_cazadores[0],"El Vaquilla","navajazo",1234,1234);
	inicializarCazadores(&lista_cazadores[1],"El Pequeño Nicolás","LLama a los presis",1234,1234);
	inicializarCazadores(&lista_cazadores[2],"","habilidad1",1234,1234);

}

/*printf("Lista de cazadores:\n");

    for (int i = 0; i < MAX_CAZADORES; i++) {

        printf("nombre %s\n", cazadores[i].nombre);
        printf("habilidad %s\n", cazadores[i].habilidad);
        printf("vida %d\n", cazadores[i].vida);
        printf("daño %d\n", cazadores[i].daño);

        printf("\n");
    }*/