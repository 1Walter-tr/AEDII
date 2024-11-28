/*Diagramar el árbol de búsqueda binaria que corresponde en cada caso, si sus elementos son insertados
de la siguiente manera:
a) 54 -72 -25 -10 -15 -5
b) 74 -22 125 -10 -150 35*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol{
    int valor;
    struct NodoArbol *izquierda;
    struct NodoArbol *derecha;
}tNodos;

tNodos *nuevoNodo(int valor);
tNodos *insertar(tNodos *nodo, int valor);
void enOrden(tNodos *nodo);

int main(){
    tNodos *raiz = NULL;
    int valor;
    int opcion;

    do
    {
        printf("1. Ingresar valor\n");
        printf("2. Mostrar numeros en orden\n");
        printf("3. Salir\n");
        printf("Ingrese una de las opciones predeterminadas: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese un valor: ");
            scanf("%d",&valor);
            raiz = insertar(raiz,valor);
            break;
        case 2:
            enOrden(raiz);
            break;
        case 3:         
            printf("Saliendo...\n");
            break;
        default:
            printf("Incorrecto. Ingrese una de las opciones ya definidas\n");
            break;
        }
    } while (opcion!=3);
    
    return 0;
}

tNodos *nuevoNodo(int valor){
    tNodos *nodo = (tNodos*)malloc(sizeof(tNodos));
    nodo->valor=valor;
    nodo->izquierda=NULL;
    nodo->derecha=NULL;

    return nodo;
}

tNodos *insertar(tNodos *nodo, int valor){
    if(nodo==NULL){
        return nuevoNodo(valor);
    }
    if(valor < nodo->valor){
        nodo->izquierda=insertar(nodo->izquierda,valor);
    }
    else if(valor > nodo->valor){
        nodo->derecha=insertar(nodo->derecha,valor);
    }

    return nodo;
}

void enOrden(tNodos *nodo){
    if(nodo!=NULL){
        enOrden(nodo->izquierda);
        printf("%d\n",nodo->valor);
        enOrden(nodo->derecha);
    }
}
