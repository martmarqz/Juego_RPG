/**
 * @file personajes.h
 * @author Yanira Mansilla
 * @brief Cabecera para las funciones relacionadas con personaje.
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estructura que representa un personaje.
 * 
 */
typedef struct _jugador
{
    char* nombre;
    int vida;
    int ataque;
    int defensa;
} Jugador;




Jugador jugador_crear(char* nombre);
void jugador_print(Jugador jugador);
#endif