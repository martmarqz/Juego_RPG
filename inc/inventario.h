#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objetos.h"

typedef struct Node* PtrToNode;
typedef PtrToNode Inventario;
typedef PtrToNode InventarioElement;

struct Node {
    Objeto objeto;
    PtrToNode next;
};

Inventario Crear_inventario_vacio(Inventario inv);

int Insertar_Objeto_en_el_Inventario(Inventario inv, Objeto obj);

int Borrar_Objeto_del_Inventario(Inventario inv, int id);

int Esta_vacio_el_Inventario(Inventario inv);

void Destruir_Inventario(Inventario inv);

void Mostrar_Inventario(Inventario inv);

Objeto* Encontrar_por_id(Inventario inv, int id);

Objeto* Encontrar_por_nombre(Inventario inv, const char* nombre);

#endif