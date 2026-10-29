#ifndef COMBATE_H
#define COMBATE_H
#include "personajes.h"
#include "inventario.h"
#include "historial.h"

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
 * @param inv
 * @param historial
 * 
 * @author Martina Marquez
 */
void iniciar_combate(Jugador* jugador, Inventario inv, cola_enemigo* cola, Stack historial);
/**
 * @brief  genera enemigos dependiendo la dificultad de la zona
 * 
 * @param cola 
 * @param zona 
 * 
 * @author Martina Marquez
 */
void generar_enemigos_zona(cola_enemigo* cola, int zona);

/**
 * @brief escoge a enemigos dificiles
 * 
 * @param cola 
 * @param id
 * 
 * @author Martina Marquez 
 */
void enemigo_dificil(cola_enemigo* cola, int id);

/**
 * @brief escoge a enemigos nivel medio
 * 
 * @param cola 
 * @param id 
 * 
 * @author Martina Marquez
 */
void enemigo_medio(cola_enemigo* cola, int id);

/**
 * @brief 
 * 
 * @param cola 
 * @param id 
 * 
 * @author Martina Marquez
 */
void enemigo_facil(cola_enemigo* cola, int id);

#endif