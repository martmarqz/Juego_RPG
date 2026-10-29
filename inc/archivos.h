#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "personajes.h"
#include "inventario.h"
#include "historial.h"

int guardar_partida(Character* jugador, Inventory inv, Stack historial, char* ruta_archivo);
int cargar_partida(Character* jugador, Inventory inv, Stack historial, char* ruta_archivo);

#endif