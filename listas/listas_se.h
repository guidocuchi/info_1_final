/* ---  Prototipos funciones genéricas de listas (para cualquier tipo de dato) --- */
#ifndef LISTAS_SE_H
#define LISTAS_SE_H

#include <stddef.h> 		// Para size_t 

typedef struct nodo{
	void *data;				// Puntero genérico para asignar cualquier tipo de dato.
	struct nodo *psig;		// Puntero al siguiente nodo.
} Nodo;

typedef int (*Comparador)(const void *a, const void *b); // Comparador es un puntero a funcion que recibe los parámetros a y b. Devuelve un entero.
typedef void (*Destructor)(void *dato);					 // Destructor para liberar memoria.

Nodo *crearLista    (void);
Nodo *crearNodo     (void *dato, size_t sizeDato);
int  insertarInicio (Nodo **head, void *dato, size_t sizeDato);
int  insertarFinal  (Nodo **head, void *dato, size_t sizeDato);
void imprimirLista  (Nodo *head, void (*mostrarDato)(void *));
void liberarLista   (Nodo **head, Destructor dest);
int  contadorNodos  (Nodo *head);
Nodo *buscarNodo    (Nodo *head, void *dato, Comparador comp);
int  eliminarNodo   (Nodo **head, void *dato, Comparador comp, Destructor dest);


#endif

