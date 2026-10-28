#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "objetos.h"
#include "personajes.h"
#include "inventario.h"
#include "combate.h"
#include "archivos.h"
#include "historial.h" 

Objeto datos_objetos(int obj)
{
    Objeto objeto;

    if(obj<=40){
        objeto=Crear_Objeto(1,"Espada corta de cobre",1,10);
    }
    else if(obj<=70){
        objeto=Crear_Objeto(2,"Arco primitivo",1,10);
    }
    else if(obj<=85){
        objeto=Crear_Objeto(3,"Pocion curativa menor",2,2);//tipo 2 es un consumible de cura, y el ultimo valor es lo que curara, asi que cambiara  segun la vida maxima
    }
    else if(obj<=95){
        objeto=Crear_Objeto(4,"Espada larga de hierro",1,25);
    }
    else if(obj<=100){
        objeto=Crear_Objeto(5,"Cota de malla",3,8);
    }

    return objeto;
}

void limpiar_buffer() 
{
    while(getchar() != '\n');
}

void iniciar_juego() 
{
    Character jugador = character_create("Aria");
    Inventory inventario = Crear_inventario_vacio(NULL);
    Stack historial = historial_inicializar();
    
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
                historial_registrar_accion(historial,"estado personaje",1);
                break;

            case 2:
                printf("\nZonas disponibles:\n");
                printf("1. Bosque Sombrio (dificultad baja)\n");
                printf("2. Cueva Humeda (dificultad media)\n");
                printf("3. Ruinas Antiguas (dificultad alta)\n");
                printf("> ");
                
                int zona;

                scanf("%d", &zona);

                if (zona < 1 || zona > 3) 
                {
                    printf("Entrada invalida.\n");
                    limpiar_buffer();
                    break;
                }
                srand(time(0));
                printf("Entras a la zona elegida...\n");
                int encontrar_objeto=(rand()%5)+1;
                int obj=(rand()%100)+1;
                printf(">>>%d|%d<<<",encontrar_objeto,obj);
                if(encontrar_objeto==1){
                    printf("Encunetras un objeto\n");
                    Objeto incluir=datos_objetos(obj);
                    Insertar_Objeto_en_el_Inventario(inventario,incluir);
                }
                else{
                    printf("No se encontro nada\n");
                }
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
                historial_registrar_accion(historial,"avanzar zona",2);
                break;

            case 3:
                Mostrar_Inventario(inventario);
                historial_registrar_accion(historial,"mostrar inventario",3);
                break;

            case 4:
                historial_print(historial);
                historial_registrar_accion(historial,"Mostrar historial",4);
                
                break;

            case 5:
                printf("\nGuardando progreso...\n");
                guardar_partida(&jugador, inventario, "partida.txt");
                printf("Saliendo del juego. ¡Hasta pronto!\n");
                historial_registrar_accion(historial,"Guardar y salir",5);
                break;

            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
                break;
        }
    }

    Destruir_Inventario(inventario);
    if (jugador.name != NULL) free(jugador.name);
}