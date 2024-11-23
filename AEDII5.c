/*Desarrollar un programa para la gestión de las ventas de un supermercado mediante la implementación
de una pila. Cada nodo deberá contener los siguientes datos asociados a un producto: código del producto,
código de rubro, cantidad, precio unitario y descripción. Además de programar todas las operaciones
básicas, se solicita:
a) Escribir una función que calcule y retorne el monto total recaudado.
b) Implementar un menú principal que contenga todas las operaciones disponibles.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
  int codigoProducto;
  int codigoRubro;
  int cantidad;
  float precioUnitario;
  char descripcion[50];
  struct Nodo *siguiente;
}tPilasProductos;

tPilasProductos *cima = NULL;

void agregar(int codigoP, int codigoR, int cantidad, float precio, char descripcion[]);
int desenpilar();
void verProductos();
float calcularTotal();

int main(){
  int codigoProducto, codigoRubro, cantidad;
  float precioUnitario;
  char descripcion[50];
  int opcion;

  while(1){
    printf("*** MENU ***\n");
    printf("1. Agregar elementos en la cola\n");
    printf("2. Eliminar elemento de la pila\n");
    printf("3. Ver producto superior\n");
    printf("4. Calcular total\n");
    printf("5. Salir\n");
    printf("Ingrese una de las opciones: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      printf("Ingrese el codigo del producto: ");
      scanf("%d",&codigoProducto);
      printf("Ingrese el codigo de rubro del producto: ");
      scanf("%d",&codigoRubro);
      printf("Ingrese la cantidad de productos: ");
      scanf("%d",&cantidad);
      printf("Ingrese el precio de unitario de cada producto: ");
      scanf("%f",&precioUnitario);
      printf("Ingrese la descripcion del producto: ");
      scanf("%s",descripcion);
      agregar(codigoProducto,codigoRubro,cantidad,precioUnitario,descripcion);
      break;
    case 2:
      desenpilar();
      break;
    case 3:
      verProductos();
      break;
    case 4:
      printf("El monto total recaudado es: %.2f\n",calcularTotal());
      break;
    case 5:
      printf("Saliendo...\n");
      exit(0);
    default:
      printf("Incorrecto. ingrese una de las opciones predeterminadas\n");
      break;
    }
  }
  return 0;
}

void agregar(int codigoP, int codigoR, int cantidad, float precio, char descripcion[]){
  tPilasProductos *nuevoNodo = (tPilasProductos*)malloc(sizeof(tPilasProductos));
  if(nuevoNodo == NULL){
    printf("Error al asignar memoria\n");
  }
  nuevoNodo->codigoProducto=codigoP;
  nuevoNodo->codigoRubro=codigoR;
  nuevoNodo->cantidad=cantidad;
  nuevoNodo->precioUnitario=precio;
  strcpy(nuevoNodo->descripcion,descripcion);
  nuevoNodo->siguiente=cima;
  cima=nuevoNodo;
  printf("Elemento %d añadido en la pila\n",codigoP);
}

int desenpilar(){
  if(cima == NULL){
    printf("La pila esta vacia\n");
    return -1;
  }
  int codigoProducto = cima->codigoProducto;
  tPilasProductos *temp = cima;
  cima=cima->siguiente;
  free(temp);
  printf("Elemento %d eliminado de la pila\n",codigoProducto);
  return codigoProducto;
}

void verProductos(){
  if(cima == NULL){
    printf("La pila esta vacia\n");
  }
  else{
    printf("Codigo del producto: %d\n",cima->codigoProducto);
    printf("Codigo de rubro del producto: %d\n",cima->codigoRubro);
    printf("Cantidad de productos: %d\n",cima->cantidad);
    printf("Precio Unitario de cada producto: %.2f\n",cima->precioUnitario);
    printf("Descripcion del productos: %s\n",cima->descripcion);
  }
}

float calcularTotal(){
  tPilasProductos *actual = cima;
  float total = 0;
  while(actual!=NULL){
    total = total+actual->cantidad * actual->precioUnitario;
    actual=actual->siguiente;
  }
  return total;
}