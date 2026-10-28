#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "personajes.h"
#include "inventario.h"
#include "combate.h"
#include "archivos.h"
#include "historial.h" 

void limpiar_buffer() 
{
    while(getchar() != '\n');
}

void iniciar_juego() 
{
    Character jugador = character_create("Aria");
    Inventory inventario = Crear_inventario_vacio(NULL);
    
    if (!cargar_partida(&jugador, inventario, "partida.txt")) 
    {
        printf("Iniciando una nueva partida con el personaje %s.\n", jugador.name);
    }

    int opcion = 0;

    while (opcion != 5) 
    {
        printf("\n===== MENU DE JUEGO =====\n");
        printf("Personaje: %s\n", jugador.name);
        printf("1. Ver personaje\n");
        printf("2. Explorar zona\n");
        printf("3. Inventario\n");
        printf("4. Historial\n");
        printf("5. Guardar y Salir\n");
        printf("> ");

        if (scanf("%d", &opcion) != 1) 
        {
            printf("Error: Entrada invalida. Ingresa un numero.\n");
            limpiar_buffer();
            continue;
        }

        switch (opcion) 
        {
            case 1:
                printf("\n--- ESTADO DEL PERSONAJE ---\n");
                character_print(jugador);
                break;

            case 2:
                printf("\nZonas disponibles:\n");
                printf("1. Bosque Sombrio (dificultad baja)\n");
                printf("2. Cueva Humeda (dificultad media)\n");
                printf("3. Ruinas Antiguas (dificultad alta)\n");
                printf("> ");
                
                int zona;
                if (scanf("%d", &zona) != 1) 
                {
                    printf("Entrada invalida.\n");
                    limpiar_buffer();
                    break;
                }

                printf("Entras a la zona elegida...\n");
                printf("Caminas entre los arboles. No encuentras nada.\n");
                printf("¡Un grupo de enemigos te bloquea el paso!\n");
                
                cola_enemigo cola_combate;
                inicializar_cola(&cola_combate);
                
                encolar(&cola_combate, 1, "Goblin", 15, 4);
                encolar(&cola_combate, 2, "Lobo", 20, 5);
                
                iniciar_combate(&jugador, inventario, &cola_combate);
                liberar_cola(&cola_combate); 
                
                if (jugador.life <= 0) 
                {
                    printf("\nFin del juego. Has muerto.\n");
                    opcion = 5; 
                }
                break;

            case 3:
                Mostrar_Inventario(inventario);
                break;

            case 4:
                printf("\nHistorial aun no implementado por el grupo.\n");
                break;

            case 5:
                printf("\nGuardando progreso...\n");
                guardar_partida(&jugador, inventario, "partida.txt");
                printf("Saliendo del juego. ¡Hasta pronto!\n");
                break;

            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
                break;
        }
    }

    Destruir_Inventario(inventario);
    if (jugador.name != NULL) free(jugador.name);
}