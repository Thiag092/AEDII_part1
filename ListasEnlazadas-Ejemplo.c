/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// 	printf("\n");
/* Declaración de tipos de datos personalizados */
typedef char tString[25];

typedef struct {
	int codigo;
	tString descripcion;	
} tElem;

typedef struct nodo {
	tElem info;
	struct nodo * siguiente;
} tLista;

/* 	Declaración de prototipos de funciones 
	asociadas a las operaciones que se puede realizar 
	con la lista */
void inicializarLista();
bool listaVacia( tLista * );

void insertarPrimero( tElem );
void insertarAdelante( tElem );
void insertarElemento( tElem );

void eliminarPrimero();

void visualizarElementos( tLista * );

void insertarEnPos( int, tElem );

void eliminarEnPos( int );

/* Declaración de variables globales*/
tLista * lista;

/* Función principal */
int main() {	
	tElem data;
	
	inicializarLista();
	
	printf("Esta vacia? %s\n", listaVacia(lista) == true ? "si" : "no" );
	
	data.codigo = 111;
	strcpy(data.descripcion, "Papas fritas");
	
	insertarElemento(data);
	
	data.codigo = 222;
	strcpy(data.descripcion, "Hamburguesa");
	
	insertarElemento(data);
	
	printf("Esta vacia? %s\n", listaVacia(lista) == true ? "si" : "no" );
	
	visualizarElementos(lista);
	
	eliminarPrimero();
	
	visualizarElementos(lista);
	
	
	return 0;
}

/* Implementación de funciones */
void inicializarLista() {	
	lista = NULL;
	printf("Lista inicializada\n");
}

bool  listaVacia( tLista * pLista ) {
	return ( pLista == NULL );
}

void insertarPrimero( tElem pElem ) {
	/* 1. Se crea el nodo que se va a insertar */
	tLista * nuevoNodo;
	
	/* 2. Se asigna memoria al nodo */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = pElem;
	
	/* 4. Se indica que el primer nodo apunta a NULL */
	nuevoNodo->siguiente = NULL;
	
	/* 5. Se agrega el nodo a la lista la lista debe apuntar al nuevo nodo */
	lista = nuevoNodo;
	
	printf("Primer elemento insertado: %d-%s\n", pElem.codigo, pElem.descripcion);	
}

void insertarAdelante( tElem pElem ) {
	/* 1. 	Se crea el nodo que se va a insertar */
	tLista * nuevoNodo;
	
	/* 2. 	Se asigna memoria al nodo */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 3. 	Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = pElem;
	
	/* 4. 	Como la inserción es por la parte de adelante de la lista, 
			se indica que al nuevo nodo le sigue el resto de la lista */
	nuevoNodo->siguiente = lista;
			
	/* 5. 	Como en el nuevo nodo quedó la lista completa, nos queda indicar que la lista que se recibe 
			como parámetro es igual a nuevo nodo */
	lista = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", pElem.codigo, pElem.descripcion);	

}

void insertarElemento( tElem pElem ) {
	if ( listaVacia( lista ) ) {
		insertarPrimero( pElem );
	}else {
		insertarAdelante( pElem );
	}		
}

void eliminarPrimero() {
	if ( listaVacia( lista ) ) {
		printf("No hay elementos para quitar!\n");
	} else {
		/* 1. Se guarda en una variable auxiliar el primer nodo de la lista */
		tLista * nodoSuprimir = lista;
	
		/* 2. Se avanza el puntero una vez, es decir se pasa al siguiente nodo de la lista */
		lista = lista->siguiente;
		
		printf("Elemento eliminado: %d-%s\n", nodoSuprimir->info.codigo, nodoSuprimir->info.descripcion );	
	
		/* 3. Se libera la memoria del nodo a suprimir que contenía el primer elemento de la lista */
		free(nodoSuprimir);
		
		/* 4. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
		nodoSuprimir = NULL;
	}
	
}

void visualizarElementos( tLista * pLista ) {
	tLista * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		/* Hay elementos para mostrar */
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("%d-%s\n", aux->info.codigo, aux->info.descripcion);
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}

void insertarEnPos( int pos, tElem nuevoDato ) {
			
}

void eliminarEnPos( int pos ) {

}

