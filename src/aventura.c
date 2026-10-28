#include "aventura.h"

/**
 * @brief Funcion para elegir zona a explorar
 * 
 * @return int Retorna la zona seleccionada
 */


void explorar_zona(int N) // < N = pasos para generar un evento
{
    int pasos = 0;

    while(pasos < N){
        pasos++;
        int evento = (rand()%3)+1;

        if(pasos == N){ //< Se genera un evento y se rompe el ciclo
            switch (evento)
            {
                case 1:
                    printf("Encuentras un objeto\n"); // < Función obtener objeto
                    break;
                case 2:
                    printf("Encuentras enemigo\n"); // < Función encontrar enemigo
                    break;
                case 3:
                    printf("No encuentras nada\n"); // < No pasa nada              
                    break;
            }

            break;
        }
        printf("No encuentras nada.\n"); // < SI no se genera evento llega hasta acá
    }

    return;
}

Objeto obtener_objetos(Inventory inv){
    Objeto obj = Crear_Objeto(1, "objetoNombre", 2, 3);
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
            printf("Rango inválido\n");
    } while (opcion < 1 || opcion > 2);
    
    if(opcion == 1){
        printf("Guardas el objeto...\n");
        Insertar_Objeto_en_el_Inventario(inv, obj);
    }

    return obj;
}






