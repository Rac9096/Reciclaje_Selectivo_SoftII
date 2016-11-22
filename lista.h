#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _LISTA_H_
#define _LISTA_H_

/**
 * Estructura que guarda la información.
 */

typedef struct info {
  int dato1;
	
  int dato2;
  /* ... */
}Info;

/**
 * Estructura que guarda el nodo, un puntero que apunta a la Info,
 * y otro que apunta al nodo siguiente
 */

typedef struct nodo {
  Info *datos;
  struct nodo *siguiente;
}Nodo;

/**
 * Estructura que guarda la Lista, con un puntero que apunta al inicio y al
 * fin de ésta. Además, almacena el tamaño de la lista.
 */

typedef struct lista {
  Nodo *inicio;
  Nodo *fin;
  int tamano;
}Lista;

/* Funciones de las Operaciones básicas */
Lista *crearLista();
void destruirLista(Lista *plista);
Nodo *crearNodo(Info *dato, Nodo *ptro);
Info * agregar(int dato1);
bool insertar(Lista *plista, int info, int pos);
int eliminar(Lista *plista,int pos);
void recorrer(Lista *plista);

#endif /* _LISTA_H_ */
