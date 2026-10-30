#include "aventura.h"

/**
 * @brief Funcion para elegir zona a explorar
 * 
 * @return int Retorna la zona seleccionada
 */


void explorar_zona(int N, Inventario inv, int zona, Stack s, Jugador *jugador) // < N = pasos para generar un evento
{
    int pasos = 0, continuar;

    while(pasos < N)
    {
        pasos++;
        
        if (pasos == 1) 
        {
            printf("Caminas entre los arboles. No encuentras nada.\n");
        } 
        else if (pasos == 2) 
        {
            printf("Sigues por el sendero. No encuentras nada.\n");
        } 
        else if (pasos == 3) 
        {
            printf("Cruzas un pequeno arroyo. No encuentras nada.\n");
        } 
        else 
        {
            printf("No encuentras nada.\n"); 
        }

        if(pasos == N) //< Se genera un evento y se rompe el ciclo
        { 
            int evento = rand()%3+1;
            
            switch (evento)
            {
                case 1:
                    printf("¡Encuentras un objeto en el suelo!\n"); 
                    obtener_objetos(inv, s); // < Función obtener objeto
                    break;
                    
                case 2:
                    printf("Un grupo de enemigos te bloquea el paso!\n");
                    cola_enemigo cola_combate;
                    inicializar_cola(&cola_combate);
                    generar_enemigos_zona(&cola_combate, zona);
                    iniciar_combate(jugador, inv, &cola_combate, s);
                    liberar_cola(&cola_combate);
                    break;
                case 3:
                    printf("No encuentras nada\n"); // < No pasa nada              
                    break;
            }

            if (jugador->vida <= 0)
                break;

            printf("¿Seguir explorando? 1.Si 2.No > ");
            do
            {
                printf("(1-2) --> ");
                if (scanf("%d", &continuar) != 1)
                    continuar = 0;            
                while (getchar() != '\n');

                if (continuar < 1 || continuar > 2)
                    printf("Rango invalido\n");
            } while (continuar < 1 || continuar > 2);           
            
            if(continuar == 1)
                pasos = 0;
            else
                break;

        }
    }

    return;
}

Objeto obtener_objetos(Inventario inv, Stack s)
{
    int probabilidad = (rand() % 100) + 1;
    Objeto obj = datos_objetos(probabilidad); 

    int opcion = 0;
    printf("Encontraste un objeto en tu trayecto.\n");
    
    Mostrar_Objeto(obj);
    
    printf("Deseas conservarlo? 1.Si 2.No\n");
    do
    {
        printf("(1-2) --> ");
        /*se puede modificar utilizando las funciones q se esta haciendo en interfaz para limpiar*/
        
        if(scanf("%d", &opcion) != 1){
            while (getchar() != '\n');
            opcion = 0;
        }

        if (opcion < 1 || opcion > 2)
            printf("Rango invalido\n");
    } while (opcion < 1 || opcion > 2);
    
    if(opcion == 1){
        printf("Guardas el objeto...\n");
        Insertar_Objeto_en_el_Inventario(inv, obj);
        
    } 
    else 
    {
        historial_registrar_accion(s,"Se ha descartado un objeto", 6);
        Accion* a=historial_top(s);
        if (a != NULL && a->tipo == 6)
            a->objeto = obj; 
        else 
            Borrar_Objeto(obj); 
    }

    return obj;
}






