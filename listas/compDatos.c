#include <stdio.h>
#include <string.h>
#include "compDatos.h"

typedef int (*Comparador)(const void *a, const void *b); // Comparador es un puntero a funcion que recibe los parámetros a y b. Devuelve un entero.

int cmpInt(const void *a, const void *b)
{
    int valor_a = *(int *)a;            // Castear y desreferenciar
    int valor_b = *(int *)b;
    if(valor_a > valor_b) return 1;
    if(valor_a < valor_b) return -1;
    return 0;                           // Retorna 0 si son iguales
}


int cmpFloat(const void *a, const void *b)
{
    float valor_a = *(float *)a;        
    float valor_b = *(float *)b;
    if(valor_a > valor_b) return 1;
    if(valor_a < valor_b) return -1;
    return 0;                           
}


int cmpDouble(const void *a, const void *b)
{
    double valor_a = *(double *)a;        
    double valor_b = *(double *)b;
    if(valor_a > valor_b) return 1;
    if(valor_a < valor_b) return -1;
    return 0;                           
}


int cmpChar(const void *a, const void *b)
{
    char valor_a = *(char *)a;          
    char valor_b = *(char *)b;
    if(valor_a > valor_b) return 1;
    if(valor_a < valor_b) return -1;
    return 0;             
}


int cmpString (const void *a, const void *b)
{
    char *strA = (char *)a;
    char *strB = (char *)b;
    return strcmp(strA,strB);
}