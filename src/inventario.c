#include "inventario.h"

/**
 * @brief Aqui se crea el espacio de memoria del inventario, en caso de que ya 
 * haya uno existentese borra y crea el espacio de memoria desde cero
 * @param inv Puntero al inventario actual
 * @return Inventory Puntero al inventario inicializado o limpio
 * 
 * @author Eban Delgado
 */
Inventory Crear_inventario_vacio(Inventory inv)
{
    if (inv!=NULL) 
    {
        Destruir_Inventario(inv);
    }

    PtrToNode header=(PtrToNode)malloc(sizeof(struct Node));
    if (header==NULL) 
    {
        printf("Error: Memoria insuficiente al crear el inventario.\n");
        return NULL;
    }

    header->next=NULL;

    return header;
}

/**
 * @brief Esta funcion lo que hace es, primero verificar si el inventario existe,luego crea 
 * un espacio de memoria, e inserta el objeto que en este caso el jugador guardo
 * @param inv Puntero al inventario
 * @param obj Objeto que se desea insertar
 * @return int 1 si fue exitoso, 0 en caso de error
 * 
 * @author Eban Delgado
 */
int Insertar_Objeto_en_el_Inventario(Inventory inv, Objeto obj)
{
    if (inv==NULL) 
    {
        printf("Error: El inventario no está inicializado.\n");
        return 0;
    }

    PtrToNode nuevo_nodo=(PtrToNode)malloc(sizeof(struct Node));
    if (nuevo_nodo==NULL) 
    {
        printf("Error: Memoria insuficiente para agregar el objeto.\n");
        return 0;
    }

    nuevo_nodo->objeto=obj;

    nuevo_nodo->next=inv->next;
    inv->next=nuevo_nodo;

    return 1;
}

/**
 * @brief Al igual que la funcion anterior, se verifica si existe el inventario, luego busca
 * elimina y el item seleccionado
 * @param inv Puntero al inventario
 * @param id Identificador único del objeto a borrar
 * @return int 1 si se eliminó con éxito, 0 si no se encontró
 * 
 * @author Eban Delgado
 */
int Borrar_Objeto_del_Inventario(Inventory inv, int id)
{
    if (inv==NULL || Esta_vacio_el_Inventario(inv)) 
    {
        return 0;
    }

    PtrToNode anterior=inv;
    PtrToNode actual=inv->next;

    while (actual!=NULL) 
    {
        if (actual->objeto.id==id) 
        {
            anterior->next=actual->next;

            Borrar_Objeto(actual->objeto);

            free(actual);
            return 1;
        }

        anterior=actual;
        actual=actual->next;
    }

    return 0;
}

/**
 * @brief Verifica si el inventario esta vacio
 * @param inv Puntero al inventario
 * @return int 1 si está vacío, 0 en caso contrario
 * 
 * @author Eban Delgado
 */
int Esta_vacio_el_Inventario(Inventory inv)
{
    if (inv==NULL || inv->next ==NULL) 
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Destruye el inventario, si no hay inventario no hace nada
 * @param inv Puntero al inventario
 */
void Destruir_Inventario(Inventory inv)
{
    if (inv==NULL) 
    {
        return;
    }

    PtrToNode actual=inv->next;
    PtrToNode siguiente=NULL;

    while (actual!=NULL) 
    {
        siguiente=actual->next;
        Borrar_Objeto(actual->objeto);
        free(actual);
        actual=siguiente;
    }

    free(inv);
}

/**
 * @brief Muestra el inventario completo con todos sus objetos
 * @param inv Puntero al inventario
 * 
 * @author Eban Delgado
 */
void Mostrar_Inventario(Inventory inv)
{
    if (Esta_vacio_el_Inventario(inv)) {
        printf("El inventario está vacío.\n");
        return;
    }

    printf("\n==========================\n");
    printf("  Inventario del jugador\n");
    printf("==========================\n");
    PtrToNode actual=inv->next;
    while (actual!=NULL) {
        Mostrar_Objeto(actual->objeto);
        actual=actual->next;
        
    }
    printf("==============================\n");
}

/**
 * @brief Busca un objeto dentro del inventario mediante su ID
 * @param inv Puntero al inventario
 * @param id Identificador único del objeto
 * @return Objeto* Puntero al objeto encontrado o NULL si no existe
 * 
 * @author Eban Delgado
 */
Objeto* Encontrar_por_id(Inventory inv, int id)
{
    if (Esta_vacio_el_Inventario(inv)) {
        return NULL;
    }

    PtrToNode actual=inv->next;
    while (actual!=NULL) {
        if (actual->objeto.id==id) {
            return &(actual->objeto);
        }
        actual=actual->next;
    }

    return NULL;
}

/**
 * @brief Busca un objeto dentro del inventario mediante su nombre
 * @param inv Puntero al inventario
 * @param nombre Nombre del objeto a buscar
 * @return Objeto* Puntero al objeto encontrado o NULL si no existe
 * 
 * @author Eban Delgado
 */
Objeto* Encontrar_por_nombre(Inventory inv, const char* nombre)
{
    if (Esta_vacio_el_Inventario(inv) || nombre==NULL) {
        return NULL;
    }

    PtrToNode actual=inv->next;
    while (actual!=NULL) {
        if (strcmp(actual->objeto.nombre, nombre)==0) {
            return &(actual->objeto);
        }
        actual=actual->next;
    }

    return NULL;
}