#include "personajes.h"

/**
 * @brief Crea un personaje con atributos por default y name dado por parametro.
 * 
 * @param name name del personaje.
 * @return character Instancia del personaje
 */
Character character_create(char* name){
    Character character;

    character.name = malloc(strlen(name) + 1 );
    if(character.name == NULL){
        printf("Error: No hay memoria disponible para crear name del personaje\n");
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
 * @brief Imprime el estado del personaje: name, puntos de life, attack y defend.
 * 
 * @param character Instancia de personaje.
 */
void character_print(Character character){

    printf("name: [%s]\n", character.name);
    printf("Puntos de life: [%d]\n",character.life);
    printf("attack: [%d]\n", character.attack);
    printf("defend: [%d]\n", character.defend);

    return;
}