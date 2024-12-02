/* Construir un árbol binario de búsqueda, donde el contenido de cada nodo sea un entero positivo, y que
permita las siguientes acciones:
a) Insertar nodos en el árbol.
b) Saber si el árbol está vacío.
c) Buscar un elemento en el árbol.
d) Eliminar un nodo del árbol.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol{
  int valor;
  struct NodoArbol *izquierda;
  struct NodoArbol *derecha;
}tNodos;

tNodos *nuevoNodo(int valor);
tNodos *insertar(tNodos *nodo, int valor);
int estaVacio(tNodos *nodo);
tNodos *buscar(tNodos *nodo, int valor);
tNodos *encontrarMinimo(tNodos *nodo);
tNodos *eliminar(tNodos *raiz, int valor);
void enOrden(tNodos *nodo);


int main(){
  tNodos *raiz = NULL;
  int opcion, valor;

  do{
    printf("1. Ingresar un valor\n");
    printf("2. Verificar si el arbol esta vacio\n");
    printf("3. Buscar elemento en el arbol\n");
    printf("4. Eliminar un elemeto del arbol\n");
    printf("5. Mostrar arbol en orden\n");
    printf("6. Salir del programa\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      printf("Ingrese un valor: ");
      scanf("%d",&valor);
      raiz=insertar(raiz,valor);
      break;
    case 2:
      if(estaVacio(raiz)){
        printf("El arbol esta vacio\n");
      }
      else{
        printf("El arbol no esta vacio\n");
      }
      break;
    case 3:
        printf("Ingrese el valor que desea buscar: ");
        scanf("%d",&valor);
        tNodos *nodoEncontrado = buscar(raiz,valor);
        if(nodoEncontrado!=NULL){
          printf("Valor %d encontrado en el arbol\n",valor);
        }
        else{
          printf("Valor %d no encontrado en el arbol\n",valor);
        }
        break;
      case 4:
        printf("Ingrese el valor que desee eliminar: ");
        scanf("%d",&valor);
        raiz=eliminar(raiz,valor);
        break;
      case 5:
        enOrden(raiz);
        break;
      case 6:
        printf("Saliendo...\n");
        break;
    default:
      printf("Incorrecto. Ingrse una de las opciones ya definidas\n");
      break;
    }
  } while(opcion!=6);
  
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
    printf("Valor %d ingresado como nodo raiz\n",valor);
    return nuevoNodo(valor);
  }

  if(valor < nodo->valor){
    if(nodo->izquierda==NULL){
      printf("Valor %d insertado como nodo izquierdo de %d\n",valor,nodo->valor);
    }
    nodo->izquierda=insertar(nodo->izquierda,valor);
  }
  else if(valor > nodo->valor){
    if(nodo->derecha==NULL){
      printf("Valor %d insertado como nodo derecho de %d\n",valor,nodo->valor);
    }
    nodo->derecha=insertar(nodo->derecha,valor);
  }
  
  return nodo;
}

int estaVacio(tNodos *nodo){
  return (nodo==NULL);
}

tNodos *buscar(tNodos *nodo, int valor){
  if(nodo==NULL || nodo->valor == valor){
    return nodo;
  }
  if(valor < nodo->valor){
    return buscar(nodo->izquierda,valor);
  }  
  return buscar(nodo->derecha,valor);
}

tNodos *encontrarMinimo(tNodos *nodo){
  tNodos *actual = nodo;
  while(actual&&actual->izquierda==NULL){
    actual=actual->izquierda;
  }

  return actual;
}

tNodos *eliminar(tNodos *raiz, int valor){
  if(raiz==NULL){
    printf("Valor %d no encontrado en el arbol\n",valor);
    return raiz;
  }

  if(valor < raiz->valor){
    raiz->izquierda=eliminar(raiz->izquierda,valor);
  }
  else if(valor > raiz->valor){
    raiz->derecha=eliminar(raiz->derecha,valor);
  }
  else{
    if(raiz->izquierda==NULL){
      tNodos *temp = raiz->derecha;
      free(raiz);
      return temp;
    }
    else if(raiz->derecha==NULL){
      tNodos *temp = raiz->izquierda;
      free(raiz);
      return temp;
    }

    tNodos *temp = encontrarMinimo(raiz->derecha);
    raiz->valor=temp->valor;
    raiz->derecha=eliminar(raiz->derecha,temp->valor);
  }

  return raiz;
}

void enOrden(tNodos *nodo){
  if(nodo!=NULL){
    enOrden(nodo->izquierda);
    printf("%d\n",nodo->valor);
    enOrden(nodo->derecha);
  }
}