#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define TAB4 "\t\t\t\t"

/* Declaración de tipos de datos personalizados */
typedef char tString [25];

typedef struct {
	int codigo;
	tString descripcion;
}tDatos;

typedef struct nodo {
	tDatos datos;
	struct nodo * siguiente;
}tNodo;

typedef struct {
	tNodo * principio;
	tNodo * final;
}tCola;

/* Declaración de prototipos */
void inicializarCola( tCola * );
bool colaVacia( tCola );
void push( tDatos, tCola * ); // insertar un elemento al final de la lista
void pop( tCola * );	// quitar un elemento del frente de la lista
void visualizarElementos( tCola );
tNodo * primerElemento( tCola );
tDatos primerElemento2( tCola );

/* Declaración de variables */
tCola cola, colaProductos;
tDatos datoNulo;

/* Bloque principal */
int main() {
	tDatos dato, primeroB, producto;
	tNodo * primero;
	
	
	datoNulo.codigo = 0;
	strcpy(datoNulo.descripcion, " ");	
	
	inicializarCola(&cola);
	inicializarCola(&colaProductos);
	
	primero = primerElemento(cola);	
	if(primero != NULL) {
		printf("Primer elemento: %d-%s\n", primero->datos.codigo, primero->datos.descripcion);
	}
	
	dato.codigo = 111;
	strcpy(dato.descripcion, "Vestido de fiesta");	
	push( dato, &cola );
	
	dato.codigo = 222;
	strcpy(dato.descripcion, "Jean");	
	push( dato, &cola );
	
	visualizarElementos(cola);
	
	primero = primerElemento(cola);	
	if(primero != NULL) {
		printf("Primer elemento: %d-%s\n", primero->datos.codigo, primero->datos.descripcion);
	}
	
	primeroB = primerElemento2(cola);
	printf("Primer elemento(version 2): %d-%s\n", primeroB.codigo, primeroB.descripcion);
	
	pop( &cola );
	
	visualizarElementos(cola);
	
	producto.codigo = 10;
	strcpy(producto.descripcion, "Producto 1");
	push(producto, &colaProductos);
	
	visualizarElementos(colaProductos);
	
	visualizarElementos(cola);
	
	return 0;
}

/* Implementación de funciones */
void inicializarCola( tCola * pCola ) {
	(*pCola).principio = NULL;
	pCola->final = NULL;
	printf("Cola inicializada ... \n");	
}

bool colaVacia( tCola pCola ) {
	return ( pCola.principio == NULL && pCola.final == NULL );
}

void push( tDatos pDatos, tCola * pCola ) {	
	/* 1. Crear un nodo */
	tNodo * nuevoNodo;
	
	/* 2. Asignar memoria al nuevo nodo */
	nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
	
	/* 3. 	Asignar valores a la parte de datos del nodo 
			y al campo siguiente */
	nuevoNodo->datos = pDatos;
	nuevoNodo->siguiente = NULL;
			
	/* 4. 	Si la cola está vacía estaríamos insertando el primer nodo
			entonces ambos punteros deben apuntar al nuevo nodo
			
			caso contrario significa que ya hay elementos en la cola,
			y solo se actualiza el puntero del final */
	if(colaVacia( *pCola )) {
		(*pCola).principio = nuevoNodo;
		pCola->final = nuevoNodo;
	}else {
		(*pCola).final->siguiente = nuevoNodo;
		(*pCola).final = nuevoNodo;
	}
	
	printf("Se inserto el elemento: %d-%s\n", pDatos.codigo, pDatos.descripcion);
}

void pop( tCola * pCola) {	
	/* 1.	Si hay elementos en la cola, se puede quitar */	
	if(!colaVacia( *pCola )){
		/* 2. 	Resguardar el nodo del principio, que es el que se va a quitar */	
		tNodo * nodoSuprimir = pCola->principio;
		
		/* 3.	Tener en cuenta si la cola es unitaria para inicializarla
			caso contrario solo se debe actualizar el puntero del principio */		
		if ( pCola->principio == pCola->final ) {
			// se quita el último elemento
			inicializarCola( &(*pCola) );
		}else {
			// la cola tiene más elementos, quito el del principio
			pCola->principio = nodoSuprimir->siguiente;			
		}
		
		printf("Se quito el elemento: %d-%s\n", 
			nodoSuprimir->datos.codigo, nodoSuprimir->datos.descripcion);
		
		/* 4.	Liberar la memoria del nodo eliminado */
		free(nodoSuprimir);
		nodoSuprimir = NULL;
	} else {
		printf("No hay elementos para quitar!\n");	
	}	
}
	
void visualizarElementos( tCola pCola ) {
	if(colaVacia(pCola)) {
		printf("No hay elementos para visualizar!\n");	
	}else {
		tNodo * aux = pCola.principio;
		printf("\n*** ELEMENTOS EN LA COLA ***\n");
		printf("Codigo | Descripcion\n");
		while(aux != NULL) {
			printf("%d | %s\n", aux->datos.codigo, aux->datos.descripcion);
			aux = aux->siguiente;
		}
	}
}

tNodo * primerElemento( tCola pCola ) {
	return pCola.principio;
}

tDatos primerElemento2( tCola pCola ) {
	return colaVacia(pCola) == true ? datoNulo : pCola.principio->datos;	
}


