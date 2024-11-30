/*Escribir un programa que permita crear un árbol binario de búsqueda, el contenido de los nodos debe ser
de tipo real. Incluir los procedimientos para insertar, devolver el número de nodos y recorrer el árbol.
a) El procedimiento Insertar debe emitir una leyenda 'Es un hijo izquierdo' o 'Es un hijo derecho', según
corresponda.
b) Escribir la función que devuelva el número de nodos del árbol binario.
c) El procedimiento Recorrer debe mostrar el contenido del nodo, siguiendo algún recorrido en
profundidad.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol{
  float valor;
  struct NodoArbol *izquierda;
  struct NodoArbol *derecha;
}tNodos;

tNodos *nuevoNodo(float valor);
tNodos *insertar(tNodos *nodo, float valor);
int contarNodos(tNodos *nodo);
void preOrden(tNodos *nodo);
void enOrden(tNodos *nodo);
void postOrden(tNodos *nodo);

int main(){
  tNodos *raiz = NULL;
  int opcion;
  float valor;

  do
  {
    printf("1. Ingresar valor\n");
    printf("2. Recorrer arbol en pre orden\n");
    printf("3. Recorrer arbol en orden\n");
    printf("4. Recorrer arbol en post orden\n");
    printf("5. Contar cantidad de nodos\n");
    printf("6. Salir del programa\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      printf("Ingrese un valor: ");
      scanf("%f",&valor);
      raiz = insertar(raiz,valor);
      break;
    case 2:
      preOrden(raiz);
      break;
    case 3:
      enOrden(raiz);
      break;
    case 4:   
      postOrden(raiz);
      break;
    case 5:
      printf("Numero de nodos en el arbol: %d\n",contarNodos(raiz));
      break;
    default:
      printf("Incorrecto. Ingrese una de las opciones ya definidas\n");
      break;
    }
  } while (opcion!=6);

  return 0; 
}

tNodos *nuevoNodo(float valor){
  tNodos *nodo = (tNodos*)malloc(sizeof(tNodos));
  nodo->valor=valor;
  nodo->izquierda=NULL;
  nodo->derecha=NULL;

  return nodo;

}

tNodos *insertar(tNodos *nodo, float valor){
  if(nodo==NULL){
    printf("Valor %.2f insertado como nodo raiz\n",valor);
    return nuevoNodo(valor);
  }

  if(valor < nodo->valor){
    if(nodo->izquierda==NULL){
      printf("Valor %.2f añadido como nodo izquierdo de %.2f\n",valor,nodo->valor);
    }
    nodo->izquierda=insertar(nodo->izquierda,valor);
  }
  else if(valor > nodo->valor){
    if(nodo->derecha==NULL){
      printf("Valor %.2f añadido como nodo derecho de %.2f\n",valor,nodo->valor);
    }
    nodo->derecha=insertar(nodo->derecha,valor);
  }

  return nodo;
}

int contarNodos(tNodos *nodo){
  if(nodo==NULL){
    return 0;
  }
  else{
    return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
  }
}

void preOrden(tNodos *nodo){
  if(nodo!=NULL){
  printf("%.2f\n",nodo->valor);
  preOrden(nodo->izquierda);
  preOrden(nodo->derecha);
  }
}

void enOrden(tNodos *nodo){
  if(nodo!=NULL){
    enOrden(nodo->izquierda);
    printf("%.2f\n",nodo->valor);
    enOrden(nodo->derecha);
  }
}

void postOrden(tNodos *nodo){
  if(nodo!=NULL){
    postOrden(nodo->izquierda);
    postOrden(nodo->derecha);
    printf("%.2f\n",nodo->valor);
  }
}