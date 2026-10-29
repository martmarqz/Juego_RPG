#ifndef AVENTURA_H
#define AVENTURA_H

#include "objetos.h"
#include "personajes.h"
#include "inventario.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct _accion
{
    int tipo;
    char * nombre;
    char* desc;
} Accion;

void explorar_zona(int N, Inventory inv);
Objeto obtener_objetos(Inventory inv);
//void encontrar_enemigos();
//int elegir_zona();

#endif