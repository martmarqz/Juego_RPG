#ifndef OBJETOS_H
#define OBJETOS_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Objeto {
    int id;
    char* nombre;
    int tipo;
    int valor_efecto;
} Objeto;

Objeto Crear_Objeto(int id, const char* nombre, int tipo, int valor_efecto);

void Mostrar_Objeto(Objeto obj);

void Borrar_Objeto(Objeto obj);

Objeto datos_objetos(int obj);

#endif