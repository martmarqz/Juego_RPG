#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "personajes.h"
#include "historial.h"
#include "inventario.h"

//========== FUNCIONES ==========

/**
 * @brief Carga el progreso del juego
 * 
 * @author Martina Marquez
 */
int cargar_partida(Character* jugador, Inventory inv, const char* ruta_archivo);

/**
 * @brief Guarda el estado actual del juego en un archivo de texto
 * 
 * @param jugador 
 * @param ruta_archivo 
 * @return int 
 * 
 * @author Martina Marquez
 */
int guardar_partida(Character* jugador, Inventory inv, const char* ruta_archivo);

#endif