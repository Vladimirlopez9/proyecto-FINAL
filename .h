#ifndef TAREAS_H
#define TAREAS_H

#define MAX_TAREAS 100
#define LONGITUD_TITULO 50

struct Tarea {
    char titulo[LONGITUD_TITULO];
    int completada; 
};

extern struct Tarea tareas[MAX_TAREAS];
extern int cantidadTareas;

void mostrarMenu();
void agregarTarea();
void marcarTareaCompletada();
void listarTareasPendientes();
void listarTodasTareas();
void buscarTarea(char titulo[]);

#endif 

