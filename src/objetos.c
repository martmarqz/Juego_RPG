#include "objetos.h"

//*Reserva espacio de memoria para crear un objeto nuevo
Objeto Crear_Objeto(int id, const char* nombre, int tipo, int valor_efecto)
{
    Objeto obj;
    obj.id=id;
    obj.tipo=tipo;
    obj.valor_efecto=valor_efecto;

    obj.nombre=malloc(strlen(nombre) + 1);
    if (obj.nombre==NULL) 
    {
        printf("Error: Memoria insuficiente para crear el objeto.\n");
        obj.id=-1;
        return obj;
    }
    strcpy(obj.nombre, nombre);

    return obj;
}

//Muestra por pantalla el objeto y sus datos
void Mostrar_Objeto(Objeto obj)
{
    printf("[%d] %s (Tipo: %d, Efecto/Valor: %d)\n", obj.id, obj.nombre, obj.tipo, obj.valor_efecto);
}

//Borra un objeto
void Borrar_Objeto(Objeto obj)
{
    if (obj.nombre != NULL) 
    {
        free(obj.nombre);
    }
}