#include "historial.h"


int historial_vacio(Stack s){
    if(s->siguiente == NULL )
        return 1;
    return 0;
}

Stack historial_push(Accion accion, Stack s){

    Ptr_nodo_historial aux_historial;
    aux_historial = malloc(sizeof(Nodo_historial));
    if (aux_historial == NULL){
        printf("Error: Falta de memoria\n");
        return s;
    }

    aux_historial->accion = accion;
    aux_historial->siguiente = s->siguiente;
    s->siguiente = aux_historial;

    return s;
}

Stack historial_pop(Stack s){

    Ptr_nodo_historial primero;
    if(historial_vacio(s)){
        printf("Error: historial vacío\n");
        return s;
    }
    
    primero = s->siguiente;
    s->siguiente = s->siguiente->siguiente;
    free(primero->accion.desc);
    free(primero->accion.nombre);
    free(primero);
    return s;
}

Stack historial_deshacer_accion(Stack s){
    if(historial_vacio(s)){
        printf("Error: historial vacío\n");
        return s;
    }

    if(s->siguiente->accion.tipo == 1){ //< Accion deshacer objeto
        printf("Se deshizo la acción. Recuperas el objeto descartado\n");
        historial_pop(s);
        
    }
    else
        printf("No es posible deshacer la última acción\n");

    return s;

}

Stack historial_registrar_accion(Stack s, char* desc, int tipo){
    Accion nueva = {0};
    nueva.tipo = tipo;
    nueva.desc = malloc(strlen(desc) + 1);

    if (nueva.desc == NULL){
        printf("Error: Falta de memoria\n");
        free(nueva.desc);     // free(NULL) es seguro
        return s;
    }

    strcpy(nueva.desc, desc);

    historial_push(nueva, s);
    return s;
}

Stack historial_inicializar(){

    Stack s = malloc(sizeof(Nodo_historial));
    if (s == NULL){
        printf("Error: Falta de memoria\n");
        return NULL;
    }

    s->siguiente = NULL;

    return s;
}


void historial_print(Stack s){

    if (s == NULL){
        printf("Error: historial no inicializado\n");
        return;
    }

    if (historial_vacio(s)){
        printf("El historial está vacío.\n");
        return;
    }

    Ptr_nodo_historial nodo = s->siguiente;
    printf("------------- Historial -------------\n");

    int i = 1;

    while (nodo != NULL)
    {
        printf("%2d.\tTipo: %d\tDescripción: %s\n", i, nodo->accion.tipo,nodo->accion.desc);
        nodo = nodo->siguiente;
        i++;
    }

    return;
}


void historial_liberar(Stack s){
    while (!historial_vacio(s))
        historial_pop(s);
    free(s);
}