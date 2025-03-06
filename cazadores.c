#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_CAZADORES 3

/*Marcos*/

//esto tiene que ir en el cazador.h
typedef struct{
	char nombre [50];
	int vida;
	int defensa;
} Cazador;

typedef enum{

	Navajazo,
	LLama_a_los_presis,
	Chiquibai,

}Habilidades;


void inicializarCazadores(Cazador * nuevoCazador, char * nombre1, int vida1, int defensa1) {

    
   	nuevoCazador -> vida = vida1;
   	nuevoCazador -> defensa = defensa1;
   	strcpy(nuevoCazador -> nombre, nombre1);
   	
   }


Cazador * lista_cazadores(void){

Cazador * lista= (Cazador *)malloc(MAX_CAZADORES * sizeof(Cazador));

if (lista == NULL)
{
	printf("Error en la asignación de memoria");
	exit(EXIT_FAILURE);
}


	printf("Inicializando cazadores...\n");

	inicializarCazadores(&lista[0],"El Vaquilla",1234,1234);
	inicializarCazadores(&lista[1],"El Pequeño Nicolás",1234,1234);
	inicializarCazadores(&lista[2],"Gigante Noble",1234,1234);

	return lista;

}

void imprimir_lista(Cazador *lista, int numCazadores) {
    printf("Lista de Cazadores:\n");
    for (int i = 0; i < numCazadores; i++) {
        printf("Cazador %d: %s, Vida: %d, Defensa: %d\n",
               i + 1, lista[i].nombre, lista[i].vida, lista[i].defensa);
    }
}

Cazador * agregarCazador(Cazador * lista, int *numCazadores){//Para realloc necesitamos saber cuantos cazadores hay en la lista para calcular el nuevo tamaño

	*numCazadores += 1;//Aumentamos cantidad

	lista = (Cazador*) realloc(lista, (*numCazadores)*sizeof(Cazador));	

	if (lista == NULL)
	{
		printf("Error en la asignacion de memoria");
		exit(EXIT_FAILURE);
	}

//Nosotros al hacer un array, si antes teniamos 2 cazadores, [0][1], al agregar 1, incremento, ahora vale 3, pero como se empieza en 0, la posicion del tercer cazador sería [2] (3 - 1 = 2). Sería como lista [3-1], lista [2]
	printf("Introduce el nombre del cazador:");
	scanf("%49s", lista[*numCazadores -1].nombre);

    printf("Introduce la vida del cazador: ");
    scanf("%d", &lista[*numCazadores -1].vida);

    printf("Introduce la defensa del cazador: ");
    scanf("%d", &lista[*numCazadores -1].defensa);

    return lista;//Pq agregarCazador devuelve un puntero a la lista actualizada

	}

int main() {

    int numCazadores = MAX_CAZADORES;

    Cazador *lista = lista_cazadores();

    imprimir_lista(lista, numCazadores);
    
    printf("\nAgregando un nuevo cazador...\n");
    lista = agregarCazador(lista, &numCazadores);
    
    imprimir_lista(lista, numCazadores);

    free(lista);
    
    return 0;
}