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

Cazador *agregarCazador(Cazador *lista, int *numCazadores) {
    // Aumentar la cantidad de cazadores
    (*numCazadores)++;

    // Reasignar memoria para la lista de cazadores
    lista = (Cazador*) realloc(lista, (*numCazadores) * sizeof(Cazador));

    if (lista == NULL) {
        printf("Error en la asignación de memoria.\n");
        exit(EXIT_FAILURE);
    }

    // Solicitar y validar el nombre del cazador
    printf("Introduce el nombre del cazador (máximo 49 caracteres): ");
    scanf("%49s", lista[*numCazadores - 1].nombre);

    // Solicitar y validar la vida del cazador
    do {
        printf("Introduce la vida del cazador (debe ser mayor que 0): ");
        scanf("%d", &lista[*numCazadores - 1].vida);
        if (lista[*numCazadores - 1].vida < 1) {
            printf("La vida tiene que ser un número positivo. Intenta de nuevo.\n");
        }
    } while (lista[*numCazadores - 1].vida < 1);

    // Solicitar y validar la defensa del cazador
    do {
        printf("Introduce la defensa del cazador (debe ser mayor que 0): ");
        scanf("%d", &lista[*numCazadores - 1].defensa);
        if (lista[*numCazadores - 1].defensa < 1) {
            printf("La defensa tiene que ser un número positivo. Intenta de nuevo.\n");
        }
    } while (lista[*numCazadores - 1].defensa < 1);

    return lista; // Devolver la lista actualizada
}


/*int main() {

    int numCazadores = MAX_CAZADORES;

    Cazador *lista = lista_cazadores();

    imprimir_lista(lista, numCazadores);
    
    printf("\nAgregando un nuevo cazador...\n");
    lista = agregarCazador(lista, &numCazadores);
    
    imprimir_lista(lista, numCazadores);

    free(lista);
    
    return 0;
}
*/