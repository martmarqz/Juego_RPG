#ifndef AVENTURA_H
#define AVENTURA_H

#include "objetos.h"
#include "personajes.h"
#include "inventario.h"
#include "combate.h"
#include "personajes.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



void explorar_zona(int N, Inventario inv, int zona, Stack s, Jugador *jugador);
Objeto obtener_objetos(Inventario inv);
//void encontrar_enemigos();
//int elegir_zona();

#endif