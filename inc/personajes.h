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
typedef struct _character
{
    char* name;
    int life;
    int attack;
    int defend;
} Character;

Character character_create(char* name);
void character_print(Character character);
#endif