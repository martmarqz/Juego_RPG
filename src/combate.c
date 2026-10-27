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

int contar_enemigos_espera(cola_enemigo* cola) 
{
    int contador = 0;
    nodo_enemigo* actual = cola->primero;
    while (actual != NULL) 
    {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void iniciar_combate(Character* jugador, cola_enemigo* cola) 
{
    int vida_max = jugador->life; 
    int enemigos_espera;

    printf("\nCOMBATE\n");

    while (!vacia(cola) && jugador->life > 0) 
    {
        nodo_enemigo enemigo_actual = desencolar(cola); 
        enemigos_espera = contar_enemigos_espera(cola);

        while (enemigo_actual.vida > 0 && jugador->life > 0) 
        {
            printf("\n%s: %d/%d PV | Ataque %d | Defensa %d\n", 
                   jugador->name, jugador->life, vida_max, jugador->attack, jugador->defend);
            printf("Enemigo actual: %s (%d PV)\n", enemigo_actual.nombre, enemigo_actual.vida);
            printf("Enemigos en espera: %d\n", enemigos_espera);
            printf("1. Atacar\n");
            printf("2. Ver inventario\n");
            printf("3. Usar objeto\n");
            printf("> ");

            int opcion;
            if (scanf("%d", &opcion) != 1) 
            {
                printf("Error: Entrada invalida. Ingresa un numero.\n");
                while(getchar() != '\n'); 
                continue;
            }

            switch (opcion) 
            {
                case 1:
                    printf("Atacas al %s: %d de dano.\n", enemigo_actual.nombre, jugador->attack);
                    enemigo_actual.vida -= jugador->attack;
                    
                    if (enemigo_actual.vida < 0) enemigo_actual.vida = 0;
                    printf("%s: %d PV.\n", enemigo_actual.nombre, enemigo_actual.vida);
                    break;

                case 2:
                    printf("Mostrando inventario...\n");
                    continue; 

                case 3:
                    printf("Usando objeto...\n");
                    break;

                default:
                    printf("Opcion no valida. Intenta de nuevo.\n");
                    continue; 
            }

            if (enemigo_actual.vida > 0) 
            {
                int dano_recibido = enemigo_actual.ataque - jugador->defend;
                if (dano_recibido < 0) dano_recibido = 0; 

                jugador->life -= dano_recibido;
                if (jugador->life < 0) jugador->life = 0;

                printf("El %s te ataca: recibes %d de dano. %s: %d/%d PV.\n", 
                       enemigo_actual.nombre, dano_recibido, jugador->name, jugador->life, vida_max);
            }
        }

        if (jugador->life <= 0) 
        {
            printf("¡Has sido derrotado por el %s!\n", enemigo_actual.nombre);
        } 
        else 
        {
            printf("¡Derrotaste al %s!\n", enemigo_actual.nombre);
            if (enemigos_espera > 0) 
            {
                printf("Se retira de la cola de combate.\n");
            }
        }
    }

    if (jugador->life > 0) 
    {
        printf("¡Combate terminado!\n");
    }
}