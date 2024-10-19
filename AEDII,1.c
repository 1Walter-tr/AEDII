/*1. Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un
producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo,
y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos
del primer nodo almacenado.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;
  struct Nodo *siguiente;
}tListaProductos;

tListaProductos *crearNodo(int codigoProductoT,char descripcionProductoT[],float precioProductoT){
  tListaProductos *nuevoNodo = (tListaProductos*)malloc(sizeof(tListaProductos));
  nuevoNodo->codigoProducto=codigoProductoT;
  strcpy(nuevoNodo->descripcionProducto,descripcionProductoT);
  nuevoNodo->precioProducto=precioProductoT;
  nuevoNodo->siguiente=NULL;

  return nuevoNodo;
}

void ingresoDatos(tListaProductos **cabeza);
void salidaDatos(tListaProductos *cabeza);

int main(){
  tListaProductos *cabeza = NULL;

  ingresoDatos(&cabeza);
  salidaDatos(cabeza);

  return 0;
}

void ingresoDatos(tListaProductos **cabeza){
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;

  printf("Ingrese el codigo del producto: ");
  scanf("%d",&codigoProducto);
  printf("Ingrese la descripcion del producto: ");
  scanf("%s",descripcionProducto);
  printf("Ingrese el precio unitario del producto: ");
  scanf("%f",&precioProducto);

  tListaProductos *nuevoNodo = crearNodo(codigoProducto,descripcionProducto,precioProducto);
  nuevoNodo->siguiente = *cabeza;
  *cabeza = nuevoNodo;
}

void salidaDatos(tListaProductos *cabeza){
  tListaProductos *actual = cabeza;
  while (actual != NULL)
  {
    printf("Codigo del producto: %d\n",actual->codigoProducto);
    printf("Descripcion del producto: %s\n",actual->descripcionProducto);
    printf("Precio del producto: %.2f\n",actual->precioProducto);
    actual=actual->siguiente;
  }
}