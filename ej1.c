#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

    #define CANT_ESTUDIANTES 3

typedef struct estudiante{
    char *nombre;
    int   legajo;
    float promedio;

} ESTUDIANTE;

int main(void)
{
    ESTUDIANTE estudiantes[CANT_ESTUDIANTES];
    int i,j,k;                        // Iteradores.
    char buffer_aux[100];             // Buffer auxiliar para almacenar los nombres de los estudiantes.

    srand(time(NULL));                // Semilla para generar legajos aleatorios.

    for(i = 0; i < CANT_ESTUDIANTES; i++){

        printf("---- Datos del estudiante %d ----\n", i+1);

        // ---- Nombre ----
        printf("Nombre: ");
        scanf(" %[^\n]", buffer_aux);                                       // Almaceno el string en un buffer auxiliar.

        estudiantes[i].nombre = (char *)malloc(strlen(buffer_aux) + 1);     // Pedir memoria exacta para el nombre + '\0'.

        if(estudiantes[i].nombre == NULL){                                  // Informe de errores.
            printf("Error al asignar memoria dinámica. \n");
            for(k = 0; k < i; k++){
                free(estudiantes[k].nombre);
            }
            return -1;
        }

        strcpy(estudiantes[i].nombre,buffer_aux);                           // Copiamos el contenido del buffer auxiliar al vector pedido.

        // ---- Legajo ----
        int esUnico;            // 1 si es único, 0 si está repetido.
        int legajo_aux;         
        
        do{
            legajo_aux = (rand() % 9000) + 1000;
            esUnico = 1; // Asumiendo que el legajo es único hasta que se demuestre lo contrario.
            
            for(j = 0; j < i; j++){
                if(estudiantes[j].legajo == legajo_aux){
                    esUnico = 0;
                    break;
                }
            }
        } while(esUnico == 0);
        
        estudiantes[i].legajo = legajo_aux;

        printf("Legajo asignado por el sistema: %d\n", estudiantes[i].legajo);

        // ---- Promedio ----
        int flag = 1;

        while(flag){
            printf("Promedio: ");
            scanf("%f",&(estudiantes[i].promedio));
            
            if(estudiantes[i].promedio < 0 || estudiantes[i].promedio > 10)
            {
                printf("Promedio inválido. Ingresarlo nuevamente.\n");
            }else{
                flag = 0;
            }
        }
        printf("--------------------------------\n\n");
    }
    
    // --- Pasar el contenido de la estructura a un archivo .csv ---

    FILE *f;

    f = fopen("ej1.csv","w");
    if(f == NULL){
        printf("Error al abrir el archivo. \n");
        return -1;
    }

    // --- Escribo encabezado CSV ---
    fprintf(f, "Nombre,Legajo,Promedio\n");

    // --- Escribo cada estudiante ---
    for(i = 0; i < CANT_ESTUDIANTES; i++){
        fprintf(f, "\"%s\",%d,%.2f\n", estudiantes[i].nombre, estudiantes[i].legajo, estudiantes[i].promedio);
    }

    if(fclose(f) != 0){
        printf("Error al cerrar el archivo. \n");
    }
    
    // Libero la memoria pedida para los nombres
    for(i = 0; i < CANT_ESTUDIANTES; i++){
        free(estudiantes[i].nombre);
    }

    printf("Datos volcados en ej1.csv exitosamente. \n");

    return 0;
}