#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas_se.h"
#include "mostrarDatos.h" // Librería necesaria para la función mostrarDatos
#include "compDatos.h"    // Librería necesaria para la función compararDatos

// ---- Crear lista ----
Nodo *crearLista(void)
{
	Nodo *head = NULL;
	return head;			
}

// ---- Crear nodo ----
Nodo *crearNodo(void *dato, size_t sizeDato)
{
	Nodo *nodo;
	
	nodo = (Nodo *)malloc(sizeof(Nodo));
	if(nodo == NULL){
		printf("Error al reservar memoria. \n");
		return NULL;
	}

	nodo->data = (void *)malloc(sizeDato);
	if(nodo->data == NULL){
		printf("Error al reservar memoria. \n");
		free(nodo);
		return NULL;
	}
	
	memcpy(nodo->data, dato, sizeDato);			// Copiamos el contenido del dato en a->dato
	nodo->psig = NULL;								

	return nodo;
}


// ---- Insertar al inicio (PILA)----
int insertarInicio(Nodo **head, void *dato, size_t sizeDato)
{
	Nodo *nuevoNodo;
	nuevoNodo = crearNodo(dato,sizeDato); 
	if(nuevoNodo == NULL){
		printf("Error al crear el nodo. \n");
		return -1;
	}
	nuevoNodo->psig = *head;			 // "nuevoNodo->psig" accede al contenido donde apunta "*head" 
	*head = nuevoNodo;					 // Luego hacemos que *head apunte a nuevoNodo

	return 1;						     // Inserción del nodo exitosa.
}

// ---- Insertar al final (COLA) todavia no la hice----
// int insertarFinal(Nodo **head, void *dato, size_t sizeDato)
// {
// 	Nodo *nuevoNodo;
// 	Nodo *actual = *head;
// 	nuevoNodo = CrearNodo(dato,sizeDato);
// 	if(nuevoNodo == NULL){
// 		printf("Error al crear el nodo. \n");
// 		return -1;
// 	}

// 	while(actual  NULL)
// 	nuevoNodo->psig = NULL;

// }

// ---- Mostrar elementos ----
void imprimirLista(Nodo *head, void (*mostrarDato)(void *))
{
	// Antes: Nodo *actual; --> creo que está mal
	Nodo *actual = head;		// agregué esta línea, ya que el nodo actual debe saber a donde apuntar para empezar a recorrer

	if(mostrarDato == NULL){
		printf("Error. Funcion mostrarDato no válida. \n");
		return;
	}

	if(actual == NULL){
		printf("La lista está vacia. \n");
	}else{
		while(actual != NULL){
			mostrarDato(actual->data);
			actual = actual->psig;
		}
	}
}

// ---- Liberar lista ----
void liberarLista(Nodo **head, Destructor dest)
{
	if (head == NULL || *head == NULL) return; 

	Nodo *actual = *head;
	
	while(actual != NULL){
		Nodo *temp = actual;		           // Guarda la referencia del nodo a liberar.
		actual = actual->psig;

		if(actual != NULL){
			dest(temp->data);
		}
		free(temp);
	}
		*head = NULL; 					       // Ahora la lista está vacia.
}


// ---- Contar nodos ----
int contadorNodos(Nodo *head)
{
	Nodo *actual = head;
	int i = 0;

	while(actual != NULL){
		actual = actual->psig;
		i++;
	}

	return i;
}


// ---- Buscar nodos ----
Nodo *buscarNodo(Nodo *head, void *dato, Comparador comp)
{
	Nodo *actual = head;
	
	while(actual != NULL){

		if((actual->data) != NULL && comp(actual->data,dato) == 0){
			return actual;
		}
		actual = actual->psig;
	}

	return NULL;
}

// ---- Eliminar nodos ----
int eliminarNodo(Nodo **head, void *dato, Comparador comp, Destructor dest)
{
	Nodo *actual = *head;
	Nodo *anterior = NULL; 		// Puntero necesario para reconectar la lista una vez que se borró el nodo deseado.

	while(actual != NULL){
		if(actual->data != NULL && comp(actual->data,dato) == 0){
			if(anterior == NULL){				// Caso particular eliminar el primer nodo.
				*head = actual->psig;			// Head apunta al siguiente del primer nodo.
			}else{
				anterior->psig = actual->psig;	// El siguiente del nodo anterior es el nodo siguiente del que queremos eliminar.
			}
			if(dest != NULL){		// Si le pasamos un NULL al 4to parámetro no hace nada. Ideal para valores fijos en el stack.
				dest(actual->data); // El usuario se encarga de pasar el destructor para liberar la memoria del dato.
			}
			free(actual); 			// Eliminar el nodo.
			return 1;				// Eliminación exitosa.
		}

		// Avanzar punteros
		anterior = actual;		// El actual se convierte en el anterior.
		actual = actual->psig;	// Avanzamos al siguiente.
	}
	

	return -1;				// Eliminación fallida.
}		



