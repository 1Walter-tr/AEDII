/*Agregamos funciones para eliminar un nodo seleccionado*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol{
  int valor;
  struct NodoArbol *izquierdo;
  struct NodoArbol *derecho;
}tNodos;

tNodos *nuevoNodo(int valor);
tNodos *insertar(tNodos *nodo, int valor);
tNodos *encontrarMinimo(tNodos *nodo);
tNodos *eliminar(tNodos *raiz, int valor);
void enOrden(tNodos *nodo);

int main(){
  tNodos *raiz = NULL;
  int opcion, valor;

  do
  {
    printf("1. Ingresar valor\n");
    printf("2. Eliminar nodo del arbol\n");
    printf("3. Mostrar arbol en orden\n");
    printf("4. Salir del programa\n");
    printf("ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
      printf("Ingres un valor: ");
      scanf("%d",&valor);
      raiz = insertar(raiz,valor);
      break;
    case 2:
      printf("Ingrese el valor a eliminar: ");
      scanf("%d",&opcion);
      raiz = eliminar(raiz,valor);
      break;
    case 3:
      enOrden(raiz);
      break;
    case 4:
      printf("Saliendo...\n");
      break;
    default:
        printf("Incorrecto. Ingrese una de las opciones ya definidas\n");
      break;
    }
  } while (opcion!=4);
  
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
  if(nodo==NULL){
    printf("Valor %d ingresado como nodo raiz\n",valor);
    return nuevoNodo(valor);
  }

  if(valor < nodo->valor){
    if(nodo->izquierdo==NULL){
      printf("Valor %d insertado como nodo izquierdo de %d\n",valor,nodo->valor);
    }
    nodo->izquierdo=insertar(nodo->izquierdo,valor);
  }
  else if(valor > nodo->valor){
    if(nodo->derecho==NULL){
      printf("Valor %d insertado como nodo derecho de %d\n",valor,nodo->valor);
    }
    nodo->derecho=insertar(nodo->derecho,valor);
  }

  return nodo;
}


tNodos *encontrarMinimo(tNodos *nodo){
  tNodos *actual = nodo;/*Guardamos en una variable la estructura de nodo*/
  while (actual && actual->izquierdo!=NULL){/*El bucle se ejectuta mientras actual no sea null*/
    actual=actual->izquierdo;/*Hace que el nodo actual ahora valga el hijo izquierdo de nodo actual*/
  }
  return actual;/*Una vez que el bucle termina el puntero actual se mueve al hijo izquierdo del nodooa actual, o sea nos movemos hasta el nodo mas minimo hasta que no hayan mas nodos izquierdos*/  
}


tNodos *eliminar(tNodos *raiz, int valor){
  if(raiz==NULL){/*Verifica si el arbol esta vacio es decir el valor que se quiere eliminar no se encuetra retorna null y un mensjae indicancido que el valor no se encuentra en el arbol*/
    printf("Valor %d no encontrado en el arbol\n",valor);
    return raiz;
  }

  if(valor < raiz->valor){/*Comparamos valor que queremos eliminar con el valor actual donde nos encontramos*/
    raiz->izquierdo=eliminar(raiz->izquierdo,valor);/*Si el valor a eliminar es menor que el nodo donde estamos parados descendemos al nodo izquierdo*/
  }
  else if(valor > raiz->valor){/*Si el valor a eliminar es menor que el nodo donde estamos  parados descendamos al nodo derecho*/
    raiz->derecho=eliminar(raiz->derecho,valor);
  }

  else{
    if(raiz->izquierdo==NULL){/*Una vez que estamos en el valor a eliminar verificamos si su raiz izquierdo es null, es decir no tiene arbol izquierdo, o sea tiene un arbol derecho*/
      tNodos *temp = raiz->derecho;/*Guardamos el valor de su arbol derecho en temp, es decir temp ahora apunta al arbol derecho del nodo que queremos eliminar*/
      free(raiz);/*Eliminamos el nodo que seleccionamos*/
      return temp;/*Retornamos el temp que guarda el arbol derecho del nodo eliminado*/
    }
    else if(raiz->derecho==NULL){/*Una vez que estamos en el valor a eliminar verificamos si su raiz derecho es null, es decir no tiene arbol derecho, o sea tiene arbol izqueirdo*/
      tNodos *temp = raiz->izquierdo;/*Guardamos el valor de su arbol izquierdo en temp, es decir temp ahora apunta al arbol izquierdo del nodo que queremos eliminar*/
      free(raiz);/*Eliminamos el nodo que seleccionamos*/
      return temp;/*Retornamos temp que guarda el arbol izquierdo del nodo eliminado*/
    }
/*Cuando el nodo a eliminar tiene ambos nodos es decir nodo izquierdo y derecho necesitamos encontrar su sucesor inmediato que es el valor minimo del subarbol derecho del nodo seleccionado para asi reemplazar el valor del nodo seleccionado con el nodo sucesor para asi eliminar el sucesor de su posicion inicial*/
    tNodos *temp = encontrarMinimo(raiz->derecho);/*Entonces lo que hacemos es encontrar el minimo del subarbol derecho*/
    raiz->valor=temp->valor;/*Ahora reemplaza el nodo seleccionado con el valor del sucesor*/
    raiz->derecho=eliminar(raiz->derecho,temp->valor);/*Ahora elimina el nodo sucesor de su posicion inicial*/
  }
  return raiz;/*Retornamos el nuevo valor*/
}


void enOrden(tNodos *nodo){
  if(nodo!=NULL){
    enOrden(nodo->izquierdo);
    printf("%d\n",nodo->valor);
    enOrden(nodo->derecho);
  }
}