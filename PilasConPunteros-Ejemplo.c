/* Pila implementada con punteros ( utilizando listas enlazadas ) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Tipos de datos personalizados */

typedef char tString [25];

typedef struct {
	int code;
	tString description;
	float price;
}tData;

typedef struct node {
	tData data;
	struct node * next; // siguiente
}tStack; // tPila

/* Declaración de prototipos */

void stackInit(); // inicializar pila
bool emptyStack( tStack * ); // pila vacia
void insertNode( tData ); // apilar
void removeNode(); // desapilatr
void showData( tStack * ); // mostrar elementos 
tData topNode( tStack * ); // elemento de la cima
tStack * topNode2( tStack * ); // elemento de la cima

/* Declaración de variables */

tStack * stack;
tData emptyData;

/* Bloque principal */

int main() {
	tData data;
	
	emptyData.code = 0;
	strcpy(emptyData.description, " ");
	emptyData.price = 0.0;
	
	stackInit();
	
	data.code = 100;
	strcpy(data.description, "Palta");
	data.price = 237.50;	
	insertNode(data);
	
	data.code = 101;
	strcpy(data.description, "Rucula");
	data.price = 125.75;	
	insertNode(data);
	
	data.code = 102;
	strcpy(data.description, "Tomates cherry");
	data.price = 650.25;	
	insertNode(data);
	
	showData(stack);
	
	removeNode();
	
	showData(stack);	
	
	printf("\nTop node: %s \n", topNode(stack).description);
	printf("Top node(version 2): %s \n", topNode2(stack)->data.description);
	
	return 0;
}

/* Implementación de funciones */
void stackInit() {
	stack = NULL;
	printf("Stack initialized ... \n"); // Pila inicializada
}

bool emptyStack( tStack * pStack ) {
	return pStack == NULL;
}

void insertNode( tData pData ) {
	/* 1. Crear el nodo que se va a insertar */
	tStack * newNode;
	
	/* 2. Reservar y asignar memoria al nuevo nodo */
	newNode = (tStack * ) malloc(sizeof( tStack ));
	
	/* 3. Asignar el dato al campo del contenido */
	newNode->data = pData;
	// 	(*newNode).data = pData;
	
	/* 4. Asignar un valor al campo siguiente (al puntero) */
	newNode->next = stack;
	
	/* 5. Asignar la memoria del nuevo nodo a la pila */
	stack = newNode;
	
	printf("The new node has been inserted!\n"); // El nuevo nodo ha sido insertado		
}



void removeNode() {
	if( !emptyStack(stack) ) {
		/* 1. Guardar el nodo que vamos a eliminar en una variable auxiliar*/
		tStack * deleteNode; // nodo a suprimir
		deleteNode = stack;
		
		/* 2. Pasar al siguiente nodo de la lista, es decir romper el enlace */
		stack = stack->next;
		
		printf("Node removed: %s\n", deleteNode->data.description);
		
		/* 3. Liberar la memoria del nodo eliminado */
		free(deleteNode);
		
		/* 4. Asignar NULL a la variable puntero auxiliar utilizada para eliminar */
		deleteNode = NULL;
	} else {
		printf("Empty stack!\n"); 
	}
}

void showData( tStack * pStack ) {	
	if(emptyStack(pStack)) {
		printf("Empty stack!\n"); // Pila vacía
	} else {
		tStack * aux = pStack;
		/* Hay elementos para visualizar */
		printf("\nInformation\n");
		printf("-----------\n");
		printf("Code | Description | Price\n");
		while(aux != NULL) {
			printf("%d | %s | $ %.2f\n", 
					aux->data.code, 
					aux->data.description, 
					aux->data.price );
			aux = aux->next; // Pasamos al siguiente nodo
		}
	}
}

tData topNode( tStack * pStack ) { 

	/* if(emptyStack(pStack) == true) {
		return emptyData;
	} else {
		return pStack->data;
	} */

	return emptyStack(pStack) == true ? emptyData : pStack->data;
}

tStack * topNode2( tStack * pStack ) {
	/* if(emptyStack(pStack) == true) {
		return NULL;
	} else {
		return pStack;
	}*/

	return emptyStack(pStack) == true ? NULL : pStack;
}



