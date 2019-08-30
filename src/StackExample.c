/*
 ============================================================================
 Name        : StackExample.c
 Author      : Marco Toscano  - martosfre
 Version     :
 Copyright   : Copyright @ martosfre
 Description : Ejemplo Stack
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANO_STACK 5

struct stack {
	int numeros[TAMANO_STACK];
	int top;
};

struct stack pila;

void push();
int pop();
void display();

int main() {
	int opcion;
	pila.top = -1;

	do {
		printf("-------------------------------------\n");
		printf("              EJEMPLO STACK           \n");
		printf("--------------------------------------\n");
		printf("1. Ingresar un elemento en la Pila \n");
		printf("2. Remover un elemento en la Pila \n");
		printf("3. Mostrar elementos \n");
		printf("4. Salir \n");

		printf("Ingrese operación:");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Hasta pronto....!!!");
			return -1;
		default:
			printf("Opción Incorrecta!! \n");
			break;
		}
		fflush(stdin);
	} while (opcion != 4);
}

/**
 * Función para añadir un elemento a la Pila
 */

void push() {
	int valorPila = 0;
	if (pila.top == (TAMANO_STACK - 1)) {
		printf("Pila esta llena \n");
	} else {
		printf("Ingrese el elemento a ingresar a la Pila:");
		scanf("%d", &valorPila);
		pila.top = pila.top + 1;
		pila.numeros[pila.top] = valorPila;
		printf("Valor ingresado correctamente !!! \n");
	}
	return;
}


/**
 * Función para eliminar un elemento en la Pila
 */
int pop() {
	int valorPila;
	if (!isEmpty()){
		valorPila = pila.numeros[pila.top];
		printf("Elemento eliminado = %d\n", pila.numeros[pila.top]);
		pila.top = pila.top - 1;
	}
	return valorPila;
}

/**
 * Función para desplegar los elementos de la Pila
 */
void display() {
	int i;
	if (!isEmpty()){
		printf("\nElementos de la Pila \n");
		printf("--------\n");
		for (i = pila.top; i >= 0; i--) {
			printf("%d\n", pila.numeros[i]);
			printf("--------\n");
		}
	}
}

/**
 * Función para comprobar si está vacía la pila
 */
bool isEmpty (){
	if (pila.top == -1) {
		return true;
	}else{
		return false;
	}
}
