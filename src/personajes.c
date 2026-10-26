#include "personajes.h"

/**
 * @brief Crea un personaje con atributos por default y nombre dado por parametro.
 * 
 * @param name Nombre del personaje.
 * @return Character Instancia del personaje
 */
Character character_create(char* name){
    Character character;

    character.name = malloc(strlen(name) + 1 );
    if(character.name == NULL){
        printf("Error: No hay memoria disponible para crear nombre del personaje\n");
        return character;
    }

    strcpy(character.name, name);

    /*VARIABLES TEMPORALES*/
    character.attack = 5;
    character.defend = 3;
    character.life = 5;

    return character;
}

/**
 * @brief Imprime el estado del personaje: NOmbre, puntos de vida, ataque y defensa.
 * 
 * @param character Instancia de personaje.
 */
void character_print(Character character){

    printf("Nombre: [%s]\n", character.name);
    printf("Puntos de vida: [%d]\n",character.life);
    printf("Ataque: [%d]\n", character.attack);
    printf("Defensa: [%d]\n", character.defend);

    return;
}