#ifndef COMBATE_H
#define COMBATE_H
#include "personajes.h"

//========== STRUCTS ==========

typedef struct nodo_enemigo 
{
    int vida;
    int id;
    int ataque;
    char nombre[50];
    struct nodo_enemigo *siguiente;
} nodo_enemigo; 

typedef struct cola_enemigo
{
    nodo_enemigo *primero;
    nodo_enemigo *ultimo;
} cola_enemigo;

//========== FUNCIONES ==========

/**
 * @brief Inicializa la cola de enemigos
 * 
 * @param cola 
 * 
 * @author Martina Marquez
 */
void inicializar_cola(cola_enemigo* cola);

/**
 * @brief Verifica que la cola este vacia
 * 
 * @param cola 
 * @return int 
 * 
 * @author Martina Marquez
 */
int vacia(cola_enemigo* cola);

/**
 * @brief Agrega a la cola a los enemigos
 * 
 * @param cola 
 * @param id 
 * @param nombre 
 * @param vida 
 * @param ataque 
 * 
 * @author Martina Marquez
 */
void encolar(cola_enemigo* cola, int id, const char* nombre, int vida, int ataque);

/**
 * @brief Quita de la cola
 * 
 * @param cola 
 * @return nodo_enemigo 
 * 
 * @author Martina Marquez
 */
nodo_enemigo desencolar(cola_enemigo* cola);

/**
 * @brief libera toda la cola
 * 
 * @param cola 
 * 
 * @author Martina Marquez
 */
void liberar_cola(cola_enemigo* cola);

/**
 * @brief Cuenta los enemigos en la cola 
 * 
 * @param cola 
 * @return int 
 * 
 * @author Martina Marquez
 */
int contar_enemigos_espera(cola_enemigo* cola);

/**
 * @brief Inicia y maneja el combate por turnos
 * 
 * @param jugador 
 * @param cola 
 * 
 * @author Martina Marquez
 */
void iniciar_combate(Character* jugador, cola_enemigo* cola);

#endif