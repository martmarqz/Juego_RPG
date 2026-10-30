#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "personajes.h"
#include "inventario.h"
#include "historial.h"

/**
 * @brief Guarda la partida
 * 
 * @param jugador 
 * @param inv 
 * @param historial 
 * @param ruta_archivo 
 * @return int 
 * 
 * @author Martina Marquez
 */
int guardar_partida(Jugador* jugador, Inventario inv, Stack historial, char* ruta_archivo);

/**
 * @brief Carga la partida guardada
 * 
 * @param jugador 
 * @param inv 
 * @param historial 
 * @param ruta_archivo 
 * @return int 
 * 
 * @author Martina Marquez
 */
int cargar_partida(Jugador* jugador, Inventario inv, Stack historial, char* ruta_archivo);

#endif