#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objetos.h"
#include "inventario.h"
#include "personajes.h"
typedef struct _nodo_historial* Ptr_nodo_historial;
typedef Ptr_nodo_historial Stack;

typedef struct _accion
{
    int tipo;
    char* nombre;
    char* desc;
    Objeto objeto;
} Accion;

typedef struct _nodo_historial
{
    Accion accion;
    Ptr_nodo_historial siguiente;
} Nodo_historial;

/**
 * @brief 
 * 
 * @param s 
 * @return int 
 */
int historial_vacio(Stack s);

/**
 * @brief 
 * 
 * @param accion 
 * @param s 
 * @return Stack 
 */
Stack historial_push(Accion accion, Stack s);
/**
 * @brief 
 * 
 * @param s 
 * @return Stack 
 */
Stack historial_pop(Stack s);

/**
 * @brief 
 * 
 * @param s 
 * @param desc 
 * @param tipo 
 * @return Stack 
 */
Stack historial_registrar_accion(Stack s, char* desc, int tipo);

/**
 * @brief 
 * 
 * @return Stack 
 */
Stack historial_inicializar();

/**
 * @brief 
 * 
 * @param s 
 */
void historial_print(Stack s);

/**
 * @brief 
 * 
 * @param s 
 * @return Stack 
 */
Stack historial_deshacer_accion(Stack s, Inventario inv, Jugador* jugador);

/**
 * @brief 
 * 
 * @param s 
 */
void historial_liberar(Stack s);


Accion* historial_top(Stack s);
#endif
