#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "listas_se.h"
#include "mostrarDatos.h"
#include "compDatos.h"

// ======== EJEMPLO DE IMPLEMENTACIÓN ========
int main(void)
{
    Nodo *lista;
    Nodo *nodito;
    int num_a = 10;
    int num_b = 1;
    int num_c = 50;
    int num_d = 234;

    /* Crear lista */
    lista = crearLista();
    printf("- Dirección de memoria de la lista %p.\n",&lista);

    /* Insertar al inicio */
    insertarInicio(&lista, &num_a, sizeof(num_a));  // Lista: 10
    insertarInicio(&lista, &num_b, sizeof(num_b));  // Lista: 1 -> 10
    insertarInicio(&lista, &num_c, sizeof(num_c));  // Lista: 50 -> 1 -> 10

    /* Insertar al final */
    insertarFinal(&lista,&num_d, sizeof(num_d));    // Lista: 50 -> 1 -> 10 -> 234

    /* Insertar entre nodos (pendiente) */

    /* Imprimir lista */
    printf("- Los datos ingresados a la lista son:");

    if (imprimirLista(lista,mostrarInt) != 0){
        printf(" - Error al imprimir la lista. \n");
    }

    printf("\n");

    /* Buscar nodos */
    nodito = buscarNodo(lista,&num_b,cmpInt);
    if(nodito != NULL){
        printf("- Nodo encontrado\n");
    }else{
        printf("No se encontró el nodo.\n");
    }

    /* Eliminar nodo */

    if(eliminarNodo(&lista,&num_b,cmpInt,NULL) != 0){
        printf(" - Error: no se encontró el nodo o la lista estaba vacia.\n");
    }else{
        printf("- Nodo eliminado.\n");
    }

    /* Liberar lista & Contador de nodos */
    printf("- Tamaño de la lista antes de liberar: %lu bytes\n",sizeof(lista));
    printf("- Cantidad de nodos de la lista antes de liberar: %d\n",contadorNodos(lista));

    liberarLista(&lista,NULL);
    printf("- Tamaño de la lista despúes de liberar: %lu\n",sizeof(lista));
    printf("- Cantidad de nodos de la lista después de liberar: %d (aclaración: sizeof(puntero) = 8 bytes)\n",contadorNodos(lista));

    if(lista == NULL){
        printf("- Memoria liberada exitosamente.\n");
    }else{
        printf("- Error al liberar memoria.\n");
    }

    return 0;
}
