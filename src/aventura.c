#include "aventura.h"

/**
 * @brief Funcion para elegir zona a explorar
 * 
 * @return int Retorna la zona seleccionada
 */


void explorar_zona(int N, Inventory inv) // < N = pasos para generar un evento
{
    int pasos = 0;
    char continuar;

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
            int evento = 1; 
            
            switch (evento)
            {
                case 1:
                    printf("¡Encuentras un objeto en el suelo!\n"); 
                    obtener_objetos(inv); // < Función obtener objeto
                    break;
                case 2:
                    printf("Encuentras enemigo\n"); // < Función encontrar enemigo
                    break;
                case 3:
                    printf("No encuentras nada\n"); // < No pasa nada              
                    break;
            }

            printf("¿Seguir explorando? (s/n) > ");
            scanf(" %c", &continuar);
            if (continuar == 's' || continuar == 'S') {
                printf("Caminas entre los arboles. No encuentras nada.\n");
            }
            
            break;
        }
    }

    return;
}

Objeto obtener_objetos(Inventory inv)
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
        Borrar_Objeto(obj); 
    }

    return obj;
}






