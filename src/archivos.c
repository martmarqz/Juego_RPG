#include <stdio.h>
#include "archivos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"

int guardar_partida(Character* jugador, const char* ruta_archivo) 
{
    FILE* archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL) 
    {
        printf("Error: No se pudo abrir el archivo para guardar la partida.\n");
        return 0;
    }

    fprintf(archivo, "%s\n", jugador->name);
    fprintf(archivo, "%d %d %d\n", jugador->life, jugador->attack, jugador->defend);
    fclose(archivo);
    printf("Partida guardada exitosamente en '%s'.\n", ruta_archivo);
    return 1; // Éxito
}

int cargar_partida(Character* jugador, const char* ruta_archivo) 
{
    FILE* archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL) 
    {
        printf("Error: No se encontro ninguna partida guardada en '%s'.\n", ruta_archivo);
        return 0; // Falla
    }

    char buffer_nombre[100];
    if (fscanf(archivo, "%99s", buffer_nombre) != 1) 
    {
        printf("Error: Archivo corrupto o vacio al leer el nombre.\n");
        fclose(archivo);
        return 0;
    }

    if (jugador->name != NULL) 
    {
        free(jugador->name);
    }
    jugador->name = (char*)malloc(strlen(buffer_nombre) + 1);
    if (jugador->name == NULL) 
    {
        printf("Error fatal: Memoria insuficiente al cargar nombre.\n");
        fclose(archivo);
        return 0;
    }

    strcpy(jugador->name, buffer_nombre);

    if (fscanf(archivo, "%d %d %d", &jugador->life, &jugador->attack, &jugador->defend) != 3) 
    {
        printf("Error: Archivo corrupto al leer atributos del personaje.\n");
        fclose(archivo);
        return 0;
    }

    fclose(archivo);
    printf("Partida cargada exitosamente.\n");
    return 1;
}