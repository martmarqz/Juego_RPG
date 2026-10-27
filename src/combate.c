#include <stdio.h>
#include <stdlib.h>
#include "combate.h"

void inicializar_cola(cola_enemigo* cola)
{
    cola->primero=NULL;
    cola->ultimo=NULL;
}

int vacia(cola_enemigo* cola) 
{
    return (cola->primero == NULL);
}

void encolar(cola_enemigo* cola, int vida, int tipo) 
{
    nodo_enemigo* nuevo = (nodo_enemigo*)malloc(sizeof(nodo_enemigo));
    if (nuevo == NULL) 
    {
        printf("Error fatal: Memoria insuficiente.\n");
        return;
    }
    nuevo->vida = vida;
    nuevo->tipo = tipo;
    nuevo->siguiente = NULL;

    if (vacia(cola)) 
    {
        cola->primero = nuevo;
    } 
    else 
    {
        cola->ultimo->siguiente = nuevo;
    }
    cola->ultimo = nuevo;
}

nodo_enemigo desencolar(cola_enemigo* cola) 
{
    nodo_enemigo enemigo_saliente;

    if (vacia(cola)) 
    {
        printf("La cola esta vacia.\n");
        enemigo_saliente.vida = -1;
        enemigo_saliente.tipo = -1;
        return enemigo_saliente;
    }

    nodo_enemigo* temp = cola->primero;

    enemigo_saliente.vida = temp->vida;
    enemigo_saliente.tipo = temp->tipo;

    cola->primero = cola->primero->siguiente;

    if (cola->primero == NULL) 
    {
        cola->ultimo = NULL;
    }

    free(temp);
    return enemigo_saliente;
}

void liberar_cola(cola_enemigo* cola) 
{
    while (!vacia(cola)) 
    {
        desencolar(cola);
    }

    cola->primero = NULL;
    cola->ultimo = NULL;
}
