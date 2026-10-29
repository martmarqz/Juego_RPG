#include "objetos.h"

/**
 * @brief Reserva espacio de memoria para crear un objeto nuevo
 * @param id Identificador único del objeto
 * @param nombre Nombre descriptivo del objeto
 * @param tipo Categoría del objeto (ej. arma, poción)
 * @param valor_efecto Valor numérico del efecto del objeto (ataque, curación, etc.)
 * @return Objeto La estructura del objeto creada e inicializada
 * 
 * @author Eban Delgado
 */
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

/**
 * @brief Muestra por pantalla el objeto y sus datos
 * @param obj Objeto que se desea mostrar en consola
 * 
 * @author Eban Delgado
 */
void Mostrar_Objeto(Objeto obj)
{
    printf("[%d] %s (Tipo: %d, Efecto/Valor: %d)\n", obj.id, obj.nombre, obj.tipo, obj.valor_efecto);
}

/**
 * @brief Borra un objeto
 * @param obj Objeto cuya memoria interna (como su nombre) se va a liberar
 * 
 * @author Eban Delgado
 */
void Borrar_Objeto(Objeto obj)
{
    if (obj.nombre != NULL) 
    {
        free(obj.nombre);
    }
}

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