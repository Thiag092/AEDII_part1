/* Punteros */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef char tString[20];

typedef struct {
	tString nombre;
	int dni;
}tPersona;

void asignacionEstatica();
void asignacionDinamicaFloat();
void asignacionDinamicaPersona();

int main() {
 	asignacionEstatica();
 	asignacionDinamicaFloat();
 	asignacionDinamicaPersona();
	return 0;
}

void asignacionEstatica() {
	char codigo;
	char * apCodigo;
	
	codigo = 'A';
		
	/* 	Se asigna al puntero la dirección de la variable referenciada */
	apCodigo = &codigo;
	
	/* 	Se asigna un valor a la variable referenciada por el puntero, 
	es decir a la variable "codigo" */
	*apCodigo = 'B';
	
	printf("\n-----------------------------------------\n");
	printf("\n*** EJEMPLO ASIGNACION ESTATICA (int) ***");
	printf("\n-----------------------------------------\n");
	
	printf("El valor de codigo es: %c\n", codigo);
	printf("El valor de codigo mediante el puntero es: %c\n", *apCodigo);	
	
	printf("El valor del puntero: %p\n", apCodigo);
	printf("La direccion de la varaible codigo: %p\n", &codigo);
	
	printf("La direccion de la variable puntero: %p\n", &apCodigo);

}

void asignacionDinamicaFloat() {
	float * apNro;
	
	/*	Se asigna memoria para la variable referenciada por el puntero
		y se coloca la dirección de esa variable dentro el puntero */
	apNro = (float *) malloc(sizeof(float));	
	
	/* 	Se asigna un valor a la variable referenciada por el puntero */
	*apNro = 100.25;	
	
	printf("\n-------------------------------------------\n");
	printf("\n*** EJEMPLO ASIGNACION DINAMICA (float) ***");
	printf("\n-------------------------------------------\n");
	printf("\nEl valor de la variable referenciada por apNro: %.2f\n", *apNro);	
	
		/* Se libera la memoria del puntero */
	free(apNro);	
	apNro = NULL;

	/* 	Al descomentar este código el programa debería fallar porque ya se liberó 
		la memoria del puntero */
	/*printf( "\nLuego del free\n" );
	printf( "\nValor de la variable referenciada por apNro: %s\n", *apNro );
	printf( "\nDireccion de la variable a la que hace referencia apNro: %p\n", apNro );*/
	
}

void asignacionDinamicaPersona() {
	tPersona * apPersona;
	
	/*	Se asigna memoria para la variable referenciada por el puntero
		y se coloca la dirección de esa variable dentro el puntero */
	apPersona = (tPersona *) malloc(sizeof(tPersona));
	
	/* 	Se asigna valores a la variable compuesta referenciada por el puntero */
	apPersona->dni = 43521568;
	strcpy(apPersona->nombre, "Agus");
	
	printf("\n----------------------------------------------\n");
	printf("\n*** EJEMPLO ASIGNACION DINAMICA (tPersona) ***");
	printf("\n----------------------------------------------\n");
	/* Se puede acceder con el operador "->" de la siguiente manera: */
	printf("\nDNI: %d\n", apPersona->dni);
	printf("Nombre: %s\n", apPersona->nombre);
	
	/* También se puede acceder con el operador "*" de la siguiente manera: */
	printf("\nDNI: %d\n", (*apPersona).dni);
	printf("Nombre: %s\n", (*apPersona).nombre);
	
	/* Se libera la memoria del puntero */
	free(apPersona);	
	apPersona = NULL;

	/* 	Al descomentar este código el programa debería fallar porque ya se liberó 
		la memoria del puntero */
	/*printf( "\nLuego del free\n" );
	printf( "\nValor de la variable referenciada por apPersona: %s\n", apPersona->nombre );
	printf( "\nDireccion de la variable a la que hace referencia apPersona: %p\n", apPersona );*/

}

