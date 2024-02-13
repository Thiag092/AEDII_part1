/* Ejemplo de Pila con Vectores (Parametrizado) - Almacena números enteros */
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef int tArrayEnteros[MAX];

typedef struct {
	tArrayEnteros listaEnteros;
	int tope; 
}tPila;

tPila pila, pila2;
int i;

void CrearPilaVacia(tPila *);
bool PilaVacia(tPila); 
bool PilaLlena(tPila);
void Apilar(tPila *, int);
void Desapilar(tPila *);
int cima(tPila);
void visualizarElementos(tPila);

int main() {
	CrearPilaVacia(&pila);	
	/*	este ejercicio no contempla el pedido de datos por teclado porque se realizó 
		solo a manera de ejemplificar para mostrar cómo utilizar los procedimientos y/o funciones	
	*/
	printf("Pila vacia? %s\n", PilaVacia(pila) ? "si" : "no");	
	Apilar(&pila, 1);
	printf("Pila vacia? %s\n", PilaVacia(pila) ? "si" : "no");
	Apilar(&pila, 2);
	Apilar(&pila, 3);
	Apilar(&pila, 4);
	visualizarElementos(pila);	
	Desapilar(&pila);	
	printf("Elementos en pila luego de desapilar: \n");	
	visualizarElementos(pila);	
	printf("Elemento en la cima de la pila: %d \n\n", cima(pila));	
	Apilar(&pila, 5);	
	printf("Elementos en pila luego de agregar el 5: \n");	
	visualizarElementos(pila);	
	Apilar(&pila, 6);
	Apilar(&pila, 7);		
	printf("Elementos en pila luego de agregar 6 y 7: \n");	
	visualizarElementos(pila);	
	
	CrearPilaVacia(&pila2);
	Apilar(&pila2, 100);
	Apilar(&pila2, 200);		
	printf("Pila 2: \n");	
	visualizarElementos(pila2);	
	printf("Elemento en la cima de la pila 2: %d \n\n", cima(pila2));	
	printf("Elemento en la cima de la pila 1: %d \n\n", cima(pila));
	return 0;
}

void CrearPilaVacia(tPila * pPila) {
	pPila->tope = -1;	
}

bool PilaVacia(tPila pPila) {
	return (pPila.tope == -1);
}

bool PilaLlena(tPila pPila) {
	return (pPila.tope == (MAX-1));
}

void Apilar(tPila * pPila, int pElemento) {
	if (PilaLlena(*pPila) != true) {		
		pPila->tope = pPila->tope + 1;
		pPila->listaEnteros[pPila->tope] = pElemento;		
		printf("Elemento Insertado! %d\n", pPila->listaEnteros[pPila->tope]);
	}
	else
		printf("Pila Llena!\n");
}

void Desapilar(tPila * pPila) {
	if (PilaVacia(*pPila) == true)
		printf("Pila Vacia!!!\n");
	else {
		pPila->listaEnteros[pPila->tope] = 0;
		pPila->tope = pPila->tope - 1;
		printf("Elemento eliminado!!!\n");		
	}
}

int cima(tPila pPila) {
	return pPila.listaEnteros[pPila.tope];
}

void visualizarElementos(tPila pPila) {
	int i;
	printf("Elementos en pila: \n");
	for (i = 0; i <= pPila.tope; i++) {
		printf("%d ", pPila.listaEnteros[i]);
	}
	printf("\n\n");	
}
