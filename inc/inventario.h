#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objetos.h"

typedef struct Node* PtrToNode;
typedef PtrToNode Inventory;
typedef PtrToNode InventoryElement;

struct Node {
    Objeto objeto;
    PtrToNode next;
};

Inventory Crear_inventario_vacio(Inventory inv);

int Insertar_Objeto_en_el_Inventario(Inventory inv, Objeto obj);

int Borrar_Objeto_del_Inventario(Inventory inv, int id);

int Esta_vacio_el_Inventario(Inventory inv);

void Destruir_Inventario(Inventory inv);

void Mostrar_Inventario(Inventory inv);

Objeto* Encontrar_por_id(Inventory inv, int id);

Objeto* Encontrar_por_nombre(Inventory inv, const char* nombre);

#endif