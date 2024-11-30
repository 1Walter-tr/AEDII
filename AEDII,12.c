/*5. Escribir un programa que permita construir un árbol binario de búsqueda correspondiente a una lista de
números enteros. Se debe considerar el nodo raíz del árbol, el primer elemento que se inserta en la lista.
Los siguientes nodos serán descendientes derechos si son mayores, y descendientes izquierdos si son
menores (tener en cuenta el orden de la lista dada). Además, programar funciones para el recorrido en
pre-orden, in-orden y post-orden*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol{
  int valor;
  struct NodoArbol *izquierdo;
  struct NodoArbol *derecho;
}tNodos;

tNodos *nuevoNodo(int valor);
tNodos *insertar(tNodos *nodo, int valor);
void enOrden(tNodos *nodo);
void preOrden(tNodos *nodo);
void postOrden(tNodos *nodo);

int main(){
  tNodos *raiz = NULL;
  int opcion, valor;

  do
  {
    printf("1. Agregar valor\n");
    printf("2. Mostrar valor en orden\n");
    printf("3. Mostrar valor pre orden\n");
    printf("4. Mostrar valor post orden\n");
    printf("5. Salir\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      printf("Ingrese una valor: ");
      scanf("%d",&valor);
      raiz = insertar(raiz,valor);
      break;
    case 2:
      enOrden(raiz);
      break;
    case 3:
      preOrden(raiz);
      break;
    case 4:
      postOrden(raiz);
      break;
    case 5:
      printf("Saliendo...\n");
      break;
    default:
      printf("Incorrecto. Ingrese una de las opciones ya definidas\n");
      break;
    }
  }while(opcion!=5);
  
  return 0;
}

tNodos *nuevoNodo(int valor){
  tNodos *nodo = (tNodos*)malloc(sizeof(tNodos));
  nodo->valor=valor;
  nodo->izquierdo=NULL;
  nodo->derecho=NULL;

  return nodo;
}


tNodos *insertar(tNodos *nodo, int valor){
  if(nodo == NULL){
    return nuevoNodo(valor);
  }
  if(valor < nodo->valor){
    nodo->izquierdo=insertar(nodo->izquierdo,valor);
  }
  else if(valor > nodo->valor){
    nodo->derecho=insertar(nodo->derecho,valor);
  }

  return nodo;
}


void enOrden(tNodos *nodo){
  if(nodo!=NULL){
    enOrden(nodo->izquierdo);
    printf("%d\n",nodo->valor);
    enOrden(nodo->derecho);
  }
}


void preOrden(tNodos *nodo){
  if(nodo!=NULL){
    printf("%d\n",nodo->valor);
    preOrden(nodo->izquierdo);
    preOrden(nodo->derecho);
  }
}


void postOrden(tNodos *nodo){
  if(nodo!=NULL){
    postOrden(nodo->izquierdo);
    postOrden(nodo->derecho);
    printf("%d\n",nodo->valor);
  }
}