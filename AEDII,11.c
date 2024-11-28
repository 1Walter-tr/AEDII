/*Dado el siguiente nodo correspondiente a un árbol de búsqueda binaria:
Escribir en lenguaje c, la declaración del tipo de dato tArbolTipoProductos
que corresponde al nodo dado, teniendo en cuenta que el árbol se balancea
según el campo código.
codigo, descripcion*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoArbol{
  int codigo;
  char descripcion[50];
  struct NodoArbol *izquierda;
  struct NodoArbol *derecha;
}tNodos;

tNodos *nuevoNodo(int codigo, char descripcion[]);
tNodos *insertar(tNodos *nodo, int codigo, char descripcion[]);
void enOrden(tNodos *nodo);

int main(){
  tNodos *raiz = NULL;
  int opcion, codigo;
  char descripcion[50];

  do
  {
    printf("1. Ingresar producto\n");
    printf("2. Mostrar prodcutos en orden\n");
    printf("3. Salir del programa\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      printf("1. Ingrese el codigo del producto: ");
      scanf("%d",&codigo);
      printf("Ingrese la descripcion del producto: ");
      scanf("%s",descripcion);
      raiz = insertar(raiz,codigo,descripcion);
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

tNodos *nuevoNodo(int codigo, char descripcion[]){
  tNodos *nodo = (tNodos*)malloc(sizeof(tNodos));
  nodo->codigo=codigo;
  strcpy(nodo->descripcion,descripcion);
  nodo->izquierda=NULL;
  nodo->derecha=NULL;

  return nodo;
}

tNodos *insertar(tNodos *nodo, int codigo, char descripcion[]){
  if(nodo==NULL){
    return nuevoNodo(codigo,descripcion);
  }
  if(codigo < nodo->codigo){
    nodo->izquierda=insertar(nodo->izquierda,codigo,descripcion);
  }
  else if(codigo > nodo->codigo){
    nodo->derecha=insertar(nodo->derecha,codigo,descripcion);
  }

  return nodo;
}

void enOrden(tNodos *nodo){
  if(nodo!=NULL){
    enOrden(nodo->izquierda);
    printf("Descripcion: %s, Codigo: %d\n",nodo->descripcion,nodo->codigo);
    enOrden(nodo->derecha);
  }
}
