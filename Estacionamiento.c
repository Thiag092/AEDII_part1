/* 	En el estacionamiento de un shopping, existe solo un carril en el que entran hasta 20 automóviles. 
	Los vehículos llegan por el extremo sur del estacionamiento y salen por el extremo norte del mismo. 
	El empleado de la cochera registra algunos datos de los automóviles que están en el carril. 
	Se solicita escribir un programa que permita al usuario ingresar matrícula, marca y modelo de los 
	automóviles en una cola hasta que la misma se llene o el usuario haya decidido no ingresar más datos. 
	Además, se pide generar un listado de todos los vehículos que están en el carril y se desea saber 
	cuánta disponibilidad hay en ese carril. Utilizar implementación con frente fijo. */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

/* Declaración de tipos de datos personalizados */
typedef char tString[20];

typedef struct{
	tString matricula;
	tString marca;
	tString modelo;
}tVehiculo;

typedef tVehiculo tListaVehiculos[MAX];

typedef struct {
	tListaVehiculos vehiculos;
	int frente;
	int final;	
}tColaVehiculos;

/* Declaración de prototipos */
void inicializarCola(tColaVehiculos *);
bool colaVacia(tColaVehiculos);
bool colaLlena(tColaVehiculos);
void agregarVehiculo(tColaVehiculos *, tVehiculo);
void quitarVehiculoFF(tColaVehiculos *);
tVehiculo primerVehiculo(tColaVehiculos); 
void visualizarVehiculos(tColaVehiculos); 
int lugaresDisponibles(tColaVehiculos);
tVehiculo ingresarVehiculo();
void menu();
void mostrarOpcionesMenu();

/* Declaración de variables globales */
tColaVehiculos colaVehiculos;
tVehiculo vehiculoVacio;

/* Bloque principal */
int main() {
	strcpy(vehiculoVacio.matricula, " ");
	strcpy(vehiculoVacio.marca, " ");
	strcpy(vehiculoVacio.modelo, " ");
	
	inicializarCola(&colaVehiculos);
	menu();	
	return 0;
}

/* Implementación de funciones */

void inicializarCola(tColaVehiculos * pColaVehiculos) {
	pColaVehiculos->frente = -1;
	pColaVehiculos->final = -1;
	printf("Cola de vehiculos inicializada!\n");
}

bool colaVacia(tColaVehiculos pColaVehiculos) {
	return (pColaVehiculos.frente == -1 && pColaVehiculos.final == -1);
}

bool colaLlena(tColaVehiculos pColaVehiculos) {
	return (pColaVehiculos.final == (MAX-1));
}

void agregarVehiculo(tColaVehiculos * pColaVehiculos, tVehiculo pVehiculo) {
	if( !colaLlena( *pColaVehiculos ) ) {
		/* Se puede insertar*/
		
		/* Actualizar el índice que hace referencia al final de la lista */
		pColaVehiculos->final = pColaVehiculos->final + 1;
		// (*pColaVehiculos).final++; 
		
		/* Almacenar el vehiculo en la lista */
		pColaVehiculos->vehiculos[pColaVehiculos->final] = pVehiculo;		
		// (*pColaVehiculos).vehiculos[pColaVehiculos->final] = pVehiculo;		
		
		// strcpy(pColaVehiculos->vehiculos[pColaVehiculos->final].matricula, pVehiculo.matricula);
		// strcpy(pColaVehiculos->vehiculos[pColaVehiculos->final].marca, pVehiculo.marca);
		// strcpy(pColaVehiculos->vehiculos[pColaVehiculos->final].modelo, pVehiculo.modelo);
		
		/* Verificar si es el primer vehiculo */
		if(pColaVehiculos->final == 0) {
			pColaVehiculos->frente = 0;
		}
		
		printf("Vehiculo insertado!\n");			
	}else {
		printf("El carril esta lleno!\n");
	}
}

void quitarVehiculoFF(tColaVehiculos * pColaVehiculos) {		
	if(!colaVacia(*pColaVehiculos)) {		
		/* Hay elementos para quitar */
		
		int i;
		
		/* Resguardar el vehiculo que se va a quitar */
		tVehiculo vehiculoSuprimir = primerVehiculo(*pColaVehiculos);
		
		/* Eliminar efectivamente el vehículo */
		pColaVehiculos->vehiculos[pColaVehiculos->frente] = vehiculoVacio;
		
		/* Reacomodar la lista de vehiculos */
		for( i=pColaVehiculos->frente; i<pColaVehiculos->final; i++ ) {
			pColaVehiculos->vehiculos[i] = pColaVehiculos->vehiculos[i+1];			
		}
		
		/* Borrar el último vehiculo que queda duplicado */
		pColaVehiculos->vehiculos[pColaVehiculos->final] = vehiculoVacio;
		
		/* 	Verificar si la cola es unitaria, es decir si tiene un solo vehículo 
			que es el que estamos eliminando */
		if(pColaVehiculos->frente == pColaVehiculos->final) {
			/* Significa que hay un solo vehiculo */
			inicializarCola(pColaVehiculos);			
		} else {
			/* Solo se actualiza el puntero final */
			pColaVehiculos->final = pColaVehiculos->final - 1;
		}
		
		printf("Salio del carril el vehiculo: %s | %s | %s\n", 
					vehiculoSuprimir.matricula,
					vehiculoSuprimir.marca,
					vehiculoSuprimir.modelo);
		
	} else {
		printf("No hay vehiculos en el carril!\n");
	}
}

tVehiculo primerVehiculo(tColaVehiculos pColaVehiculos) {
	return ( colaVacia(pColaVehiculos) == true ? vehiculoVacio : pColaVehiculos.vehiculos[pColaVehiculos.frente] );	
}

void visualizarVehiculos(tColaVehiculos pColaVehiculos) {
	int i;
	
	if( !colaVacia(pColaVehiculos) ) {
		/* Hay vehiculos para mostrar */
		printf("** Vehiculos en el carril *** \n");
		printf("** ---------------------- *** \n");		
		printf("Matricula | Marca | Modelo\n");
		
		for( i=pColaVehiculos.frente; i<=pColaVehiculos.final; i++ ) {
			printf("%s | %s | %s\n", pColaVehiculos.vehiculos[i].matricula, 
									 pColaVehiculos.vehiculos[i].marca, 
									 pColaVehiculos.vehiculos[i].modelo);
		}
	} else {
		printf("No hay vehiculos para mostrar!\n");
	}
}

int lugaresDisponibles(tColaVehiculos pColaVehiculos) {
	return ( colaVacia(pColaVehiculos) == true ? MAX : (MAX - pColaVehiculos.final - 1) );
}

tVehiculo ingresarVehiculo() {
	tVehiculo vehiculo;
	
	printf("\nIngresar matricula: ");
	fflush(stdin);
	gets(vehiculo.matricula); 
	printf("Ingresar marca: ");
	fflush(stdin);
	gets(vehiculo.marca); 
	printf("Ingresar modelo: ");
	fflush(stdin);
	gets(vehiculo.modelo); 
	
	return vehiculo;
}

void mostrarOpcionesMenu() {
	printf("\nSeleccione una opcion:\n");
	printf("\t1-Agregar vehiculo 2-Quitar vehiculo 3-Primer Vehiculo\n");
	printf("\t4-Mostrar vehiculos 5-Disponibilidad 6-Carril lleno? 7- Carril vacio? x-Salir: ");
}

void menu() {
	char opcion;
	tVehiculo nuevoVehiculo;
	int disponibilidad = 0;
		
	mostrarOpcionesMenu();
	fflush(stdin);
	scanf("%c", &opcion);
		
	switch(opcion) {
		case '1':	nuevoVehiculo = ingresarVehiculo();	
					agregarVehiculo(&colaVehiculos, nuevoVehiculo);
					menu();
					break;
		
		case '2': 	quitarVehiculoFF(&colaVehiculos);
					menu();
					break;
					
		case '3': 	primerVehiculo(colaVehiculos);
					menu();
					break;
					
		case '4': 	visualizarVehiculos(colaVehiculos);
					menu();
					break;
					
		case '5': 	disponibilidad = lugaresDisponibles(colaVehiculos);
					printf("Quedan %d lugares disponibles\n", disponibilidad);
					menu();
					break;
					
		case '6': 	printf("El carril esta lleno: %s\n", colaLlena(colaVehiculos) == true ? "Si" : "No");
					menu();
					break;
		
		case '7': 	printf("El carril esta vacio: %s\n", colaVacia(colaVehiculos) == true ? "Si" : "No");
					menu();
					break;
					
		case 'x': 	printf("\tHasta la proxima!\n");
					break;
		
		default:	printf("\tError! No existe la opcion seleccionada\n");
					menu();
					break;
	}	
}




