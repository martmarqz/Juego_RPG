#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "inventario.h"
#include "historial.h" 

int guardar_partida(Jugador* jugador, Inventario inv, Stack historial, char* ruta_archivo) 
{
    FILE* archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL) 
    {
        printf("Error: No se pudo abrir el archivo para guardar la partida.\n");
        return 0;
    }

    fprintf(archivo, "%s\n", jugador->nombre);
    fprintf(archivo, "%d %d %d\n", jugador->vida, jugador->ataque, jugador->defensa);
    
    PtrToNode actual = inv->next;
    while (actual != NULL) 
    {
        fprintf(archivo, "%d %d %d %s\n", actual->objeto.id, actual->objeto.tipo, actual->objeto.valor_efecto, actual->objeto.nombre);
        actual = actual->next;
    }
    fprintf(archivo, "-1\n"); 

    // Guardado del historial
    Ptr_nodo_historial nodo_hist = historial->siguiente;
    while (nodo_hist != NULL) 
    {
        fprintf(archivo, "%d\n%s\n", nodo_hist->accion.tipo, nodo_hist->accion.desc);
        nodo_hist = nodo_hist->siguiente;
    }
    fprintf(archivo, "-1\n"); 

    fclose(archivo);
    printf("Partida guardada exitosamente en '%s'.\n", ruta_archivo);
    return 1; 
}

int cargar_partida(Jugador* jugador, Inventario inv, Stack historial, char* ruta_archivo) 
{
    int id_obj, tipo_obj, valor_obj;
    char nombre_obj[100];

    FILE* archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL) 
    {
        printf("Error: No se encontro ninguna partida guardada en '%s'.\n", ruta_archivo);
        return 0;
    }

    char buffer_nombre[100];
    if (fscanf(archivo, "%99s", buffer_nombre) != 1) 
    {
        printf("Error: Archivo corrupto o vacio al leer el nombre.\n");
        fclose(archivo);
        return 0;
    }

    if (jugador->nombre != NULL) 
    {
        free(jugador->nombre);
    }
    jugador->nombre = (char*)malloc(strlen(buffer_nombre) + 1);
    if (jugador->nombre == NULL) 
    {
        printf("Error fatal: Memoria insuficiente al cargar nombre.\n");
        fclose(archivo);
        return 0;
    }

    strcpy(jugador->nombre, buffer_nombre);

    if (fscanf(archivo, "%d %d %d", &jugador->vida, &jugador->ataque, &jugador->defensa) != 3) 
    {
        printf("Error: Archivo corrupto al leer atributos del personaje.\n");
        fclose(archivo);
        return 0;
    }

    while (fscanf(archivo, "%d", &id_obj) == 1 && id_obj != -1) 
    {
        fscanf(archivo, "%d %d %99s", &tipo_obj, &valor_obj, nombre_obj);
        Objeto nuevo_obj = Crear_Objeto(id_obj, nombre_obj, tipo_obj, valor_obj);
        Insertar_Objeto_en_el_Inventario(inv, nuevo_obj);
    }

    int tipo_accion;
    char desc_accion[256];
    while (fscanf(archivo, "%d\n", &tipo_accion) == 1 && tipo_accion != -1) 
    {
        if (fgets(desc_accion, sizeof(desc_accion), archivo) != NULL) 
        {
            desc_accion[strcspn(desc_accion, "\n")] = 0; 
            historial_registrar_accion(historial, desc_accion, tipo_accion);
        }
    }

    fclose(archivo);
    printf("Partida cargada exitosamente.\n");
    return 1;
}