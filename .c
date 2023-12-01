#include <stdio.h>
#include <string.h>
#include "proyecto final modde.h"

struct Tarea tareas[MAX_TAREAS];
int cantidadTareas = 0;

void mostrarMenu() {
    printf("\n1. Agregar una nueva tarea.\n");
    printf("2. Marcar una tarea como completada.\n");
    printf("3. Listar todas las tareas pendientes.\n");
    printf("4. Listar todas las tareas.\n");
    printf("5. Buscar una tarea por titulo.\n");
    printf("6. Salir.\n");
}

void agregarTarea() {
    if (cantidadTareas < MAX_TAREAS) {
        printf("Ingrese el titulo de la tarea: ");
        scanf("%s", tareas[cantidadTareas].titulo);
        tareas[cantidadTareas].completada = 0; 
        cantidadTareas++;
        printf("Tarea agregada con exito.\n");
    } else {
        printf("Se ha alcanzado el limite maximo de tareas.\n");
    }
}

void marcarTareaCompletada() {
    int indiceTarea;
    printf("Ingrese el numero de la tarea que desea marcar como completada: ");
    scanf("%d", &indiceTarea);
    if (indiceTarea >= 0 && indiceTarea < cantidadTareas) {
        tareas[indiceTarea].completada = 1;
        printf("Tarea marcada como completada.\n");
    } else {
        printf("Indice de tarea no valido.\n");
    }
}

void listarTareasPendientes() {\
    int i;
    printf("Tareas pendientes:\n");
    for ( i = 0; i < cantidadTareas; i++) {
        if (tareas[i].completada == 0) {
            printf("%d. %s (pendiente)\n", i, tareas[i].titulo);
        }
    }
}

void listarTodasTareas() {
	int i;
    printf("Todas las tareas:\n");
    for (i = 0; i < cantidadTareas; i++) {
        printf("%d. %s (%s)\n", i, tareas[i].titulo, tareas[i].completada == 0 ? "pendiente" : "completada");
    }
}

void buscarTareaRecursiva(char titulo[], int index) {
    if (index >= cantidadTareas) {
        printf("La tarea \"%s\" no se encontro en la lista.\n", titulo);
        return;
    }

    if (strcmp(tareas[index].titulo, titulo) == 0) {
        printf("%d. %s (%s)\n", index, tareas[index].titulo, tareas[index].completada == 0 ? "pendiente" : "completada");
        return;
    }

    buscarTareaRecursiva(titulo, index + 1);
}

void buscarTarea(char titulo[]) {
    printf("Resultados de la busqueda:\n");
    buscarTareaRecursiva(titulo, 0);
}
