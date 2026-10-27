#ifndef COMBATE_H
#define COMBATE_H

//========== STRUCTS ==========

typedef struct nodo_enemigo 
{
    int vida;
    int tipo;
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
 * @brief Agrega a la cola
 * 
 * @param cola 
 * @param vida 
 * @param tipo 
 * 
 * @author Martina Marquez
 */
void encolar(cola_enemigo* cola, int vida, int tipo);

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

#endif