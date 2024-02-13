/* 	Ejemplo de una estructura de cola, donde cada elemento de la lista 
	contiene un dato compuesto que representa un color */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

/* Declaración de tipos de datos personalizados */
typedef char tString[20];

typedef struct{
	int codigo;
	tString nombre;
}tColor;

typedef tColor tVectorColores[MAX];

typedef struct {
	tVectorColores colores;
	int frente;
	int final;	
}tColaColores;

/* Declaración de prototipos */
void inicializarCola();
bool colaVacia(tColaColores);
bool colaLlena(tColaColores);
void agregarElemento( tColor );

/* ATENCIÓN: Sólo puede utilizarse uno de los modos de eliminación en el programa !!! */
void eliminarElementoFM(); // Eliminar frente móvil
void eliminarElementoFF(); // Eliminar frente fijo

void mostrarPrimerElemento(tColaColores);
tColor primerElemento(tColaColores);
void visualizarElementos(tColaColores);

/* Declaración de variables globales */
tColaColores colaColores;
tColor colorVacio;

/* Bloque principal */
int main() {
	tColor color;
	
	/* 	Atención! 
		Sería conveniente codificar un menú de opciones para las operaciones de la cola	*/
	
	colorVacio.codigo = 0;
	strcpy(colorVacio.nombre, " ");
	
	inicializarCola();

	printf("La lista de colores esta vacia? %s\n", colaVacia(colaColores) == true ? "si" : "no");
	printf("La lista de colores esta llena? %s\n", colaLlena(colaColores) == true ? "si" : "no");
		
	color.codigo = 1;
	strcpy(color.nombre, "Azul");
	agregarElemento(color);
	
	color.codigo = 2;
	strcpy(color.nombre, "Amarillo");	
	agregarElemento(color);
	
		
	color.codigo = 3;
	strcpy(color.nombre, "Verde");
	agregarElemento(color);
	
	color.codigo = 4;
	strcpy(color.nombre, "Violeta");	
	agregarElemento(color);
	
	printf("La lista de colores esta vacia? %s\n", colaVacia(colaColores) == true ? "si" : "no");

	visualizarElementos(colaColores);
	
	mostrarPrimerElemento(colaColores);
	
	/* eliminarElementoFM();
	eliminarElementoFM();
	eliminarElementoFM();
	eliminarElementoFM();*/
	
	eliminarElementoFF();
	eliminarElementoFF();
	eliminarElementoFF();
	eliminarElementoFF();
	
	visualizarElementos(colaColores);
		
	return 0;
}

/* Implementación de funciones */
void inicializarCola() {
	colaColores.frente = -1;
	colaColores.final = -1;
	printf("Lista de colores inicializada!\n");
}

bool colaVacia(tColaColores pCola) {
	return (pCola.frente == -1 && pCola.final == -1);
}

bool colaLlena(tColaColores pCola)  {
	return pCola.final == MAX-1;
}

void agregarElemento( tColor pColor )  {
	if( colaLlena(colaColores) ) {
		/* No hay lugar */
		printf("No hay espacio disponible\n\n");
	}else{
		/* Se puede insertar */
		
		/* Actualizar la variable auxiliar que referencia el elemento del final */
		colaColores.final++;
		
		/* Insertar el color */ 
		colaColores.colores[colaColores.final] = pColor;
		
		/* Comprobar si es el primer elemento */		
		if(colaColores.final == 0) {
			/* Actualizar la variable auxiliar que referencia el elemento del frente */
			colaColores.frente = 0;
		}
		
		printf("Se inserto el color %s\n", pColor.nombre);
	}
}

void eliminarElementoFM()  {
	tColor colorSuprimir; 
	
	if(colaVacia(colaColores)) {
		printf("\nNo hay colores para eliminar!\n");
	}else{
		/* Hay colores para eliminar */
		
		/* Resguardar el color por eliminar */
		colorSuprimir = colaColores.colores[colaColores.frente];
		
		/* Borrar el contenido que se encuentra en el frente de la lista de colores */
		colaColores.colores[colaColores.frente] = colorVacio;
		
		/* Verificar si la cola es unitaria, es decir si tiene un solo elemento que es el que se está por quitar */
		if(colaColores.frente == colaColores.final) {
			inicializarCola();
		} else {
			/* Actualizar la variable auxiliar que referencia el elemento del frente */
			colaColores.frente++;
		}						
		printf("\nColor eliminado %s\n", colorSuprimir.nombre);
	}				
}

void eliminarElementoFF() {
	tColor colorSuprimir; 
	int i;
	
	if(colaVacia(colaColores)) {
		printf("\nNo hay colores para eliminar!\n");
	}else{
		/* Hay colores para eliminar */
		
		/* Resguardar el color por eliminar */
		colorSuprimir = colaColores.colores[colaColores.frente];
		
		/* Borrar el contenido que se encuentra en el frente de la lista de colores */
		colaColores.colores[colaColores.frente] = colorVacio;
		
		/* Reacomodar la lista de colores */
		for(i=colaColores.frente; i<=colaColores.final; i++) {
			colaColores.colores[i] = colaColores.colores[i+1];
		}
		
		/* Borrar el color del final porque queda duplicado */		
		colaColores.colores[colaColores.final] = colorVacio;
		
		/* Verificar si la cola es unitaria, es decir si tiene un solo elemento que es el que se está por quitar */
		if(colaColores.frente == colaColores.final) {
			inicializarCola();
		} else {
			/* Actualizar la variable auxiliar que referencia el elemento del final */
			colaColores.final--;
		}						
		printf("\nColor eliminado %s\n", colorSuprimir.nombre);		
	}
}

void mostrarPrimerElemento(tColaColores pCola)  {	
	if(colaVacia(pCola)) {
		printf("\nNo hay colores cargados!\n");
	}else{			
		tColor color = primerElemento(pCola);		
		printf("\nElemento del frente: %d-%s", color.codigo, color.nombre);
	}
}	

tColor primerElemento(tColaColores pCola) {
	tColor color = colorVacio;	
	
	if(!colaVacia(pCola)) {
		color = pCola.colores[pCola.frente];		
	}
	
	return color;
}

void visualizarElementos(tColaColores pCola)  {
	int i;
	if(colaVacia(pCola)) {
		printf("No hay colores cargados!\n");
	}else{
		for(i=pCola.frente; i<=pCola.final; i++){
			printf("%d-%s | ", pCola.colores[i].codigo, pCola.colores[i].nombre);
		}
	}
}



