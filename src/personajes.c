#include "personajes.h"

/**
 * @brief Crea un personaje con atributos por default y nombre dado por parametro.
 * 
 * @param nombre nombre del personaje.
 * @return jugador Instancia del personaje
 */
Jugador jugador_crear(char* nombre){
    Jugador jugador;

    jugador.nombre = malloc(strlen(nombre) + 1 );
    if(jugador.nombre == NULL){
        printf("Error: No hay memoria disponible para crear nombre del personaje\n");
        return jugador;
    }

    strcpy(jugador.nombre, nombre);

    /*VARIABLES TEMPORALES*/
    jugador.ataque = 5;
    jugador.defensa = 3;
    jugador.vida = 5;

    return jugador;
}

/**
 * @brief Imprime el estado del personaje: nombre, puntos de life, ataque y defend.
 * 
 * @param jugador Instancia de personaje.
 */
void jugador_print(Jugador jugador){

    printf("nombre: [%s]\n", jugador.nombre);
    printf("Puntos de life: [%d]\n",jugador.vida);
    printf("ataque: [%d]\n", jugador.ataque);
    printf("defend: [%d]\n", jugador.defensa);

    return;
}