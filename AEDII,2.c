/*2. Modificar el ejercicio 1 para que se puedan realizar todas las operaciones básicas para el manejo de una
lista enlazada:
a) Generar o inicializar la lista.
b) Función para determinar si una lista está vacía.
c) Insertar el primer producto (nodo) de la lista.
d) Insertar un producto al principio de la lista.
e) Eliminar el primer producto de la lista.
f) Insertar un producto en una determinada posición dentro de la lista.
g) Eliminar un producto de una determinada posición de la lista.
h) Visualizar todos los datos de los productos que están en la lista*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo{
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;
  struct Nodo *siguiente;
}tListaProductos;

tListaProductos *crearNodo(int codigoProductoT,char descripcionProductoT[],float precioProductoT);
void ingresoDatos(tListaProductos **cabeza);
void salidaDatos(tListaProductos *cabeza);
tListaProductos *eliminarPrimerNodo(tListaProductos *cabeza);
tListaProductos *insertarEnPosicion(tListaProductos *cabeza,int posicion);
tListaProductos *eliminarEnPosicion(tListaProductos *cabeza, int posicion);

int main(){
  tListaProductos *cabeza = NULL;
  int opcion;
  int posicion;
  do{
    printf("***Eliga las siguientes opciones***\n");
    printf("1. Ingresar productos\n");
    printf("2. Mostrar productos\n");
    printf("3. Eliminar primer producto\n");
    printf("4. Insertar producto en posicion\n");
    printf("5. Eliminar producto en posicion\n");
    printf("6. Salir\n");
    printf("Eliga la opcion: ");
    scanf("%d",&opcion);

    switch (opcion){
    case 1:
      ingresoDatos(&cabeza);
      break;
    case 2:
      salidaDatos(cabeza);
      break;
    case 3:
      cabeza=eliminarPrimerNodo(cabeza);
      break;
    case 4:
      printf("Eliga en que posicion insertar: ");
      scanf("%d",&posicion);
      cabeza=insertarEnPosicion(cabeza,posicion);
      break;
    case 5:
      printf("Eliga en que posicion eliminar: ");
      scanf("%d",&posicion);
      cabeza=eliminarEnPosicion(cabeza,posicion);
      break;
    case 6:
      printf("Saliendo...\n");
      break;
    default:
      printf("Eliga las opciones marcadas\n");
      break;
    }
  }while(opcion != 6);

  return 0;
}

tListaProductos *crearNodo(int codigoProductoT,char descripcionProductoT[],float precioProductoT){
  tListaProductos *nuevoNodo = (tListaProductos*)malloc(sizeof(tListaProductos));
  nuevoNodo->codigoProducto=codigoProductoT;
  strcpy(nuevoNodo->descripcionProducto,descripcionProductoT);
  nuevoNodo->precioProducto=precioProductoT;
  nuevoNodo->siguiente=NULL;

  return nuevoNodo;
}

void ingresoDatos(tListaProductos **cabeza){
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;

  printf("Ingrese el codigo del producto: ");
  scanf("%d",&codigoProducto);
  printf("Ingrese la descripcion del producto: ");
  scanf("%s",descripcionProducto);
  printf("Ingrese el precio del producto: ");
  scanf("%f",&precioProducto);

  tListaProductos *nuevoNodo = crearNodo(codigoProducto,descripcionProducto,precioProducto);
  nuevoNodo->siguiente=*cabeza;
  *cabeza=nuevoNodo;
}

void salidaDatos(tListaProductos *cabeza){
  tListaProductos *actual = cabeza;
  while (actual == NULL)
  {
    printf("La lista esta vacia\n");
    return;
  }

  while(actual != NULL){
    printf("El codigo del producto es: %d\n",actual->codigoProducto);
    printf("La descripcion del producto es: %s\n",actual->descripcionProducto);
    printf("El precio del producto es: %.2f\n",actual->precioProducto);
    actual=actual->siguiente;
  }
}

tListaProductos *eliminarPrimerNodo(tListaProductos *cabeza){
  if(cabeza == NULL){
    printf("La lista esta vacia\n");
    return NULL;
  }

  tListaProductos *temp = cabeza;  //se guarda a la persona que esta al frente de la fila en una variable//
  cabeza=cabeza->siguiente;  //la persona que estaba detras toma el primer lugar//
  free(temp);  //La primera persona se va de la fila//
  return cabeza;
}

tListaProductos *insertarEnPosicion(tListaProductos *cabeza,int posicion){
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;

  printf("Ingrese el codigo del producto: ");
  scanf("%d",&codigoProducto);
  printf("Ingrese la descripcion del producto: ");
  scanf("%s",descripcionProducto);
  printf("Ingrese el precio del producto: ");
  scanf("%f",&precioProducto);

  if(posicion == 1){ //verificamos si queremos insertar una persona al principio de la fila//
    tListaProductos *nuevoNodo = crearNodo(codigoProducto,descripcionProducto,precioProducto); //creamos a la nueva persona//
    nuevoNodo->siguiente=cabeza;//la nueva persona se convierte en la cabeza de la fila (la persona que estaba primera pasa a ser la segunda)//
    return nuevoNodo;//Decimos que nuevoNodo se convierta en la primera persona en la fila//
  }

  tListaProductos *actual = cabeza;
  for(int i = 0; actual != NULL && i < posicion - 1; i++){
    actual=actual->siguiente;
  }

  if(actual == NULL){
    printf("La posicion esta fuera de rango\n");
    return cabeza;
  }

  tListaProductos *nuevoNodo = crearNodo(codigoProducto,descripcionProducto,precioProducto);//creamos nuevoNodo//
  nuevoNodo->siguiente=actual->siguiente;//hace que la nueva persona apunte hacia la persona que estaba originalmente en la posicion deseada//
  actual->siguiente=nuevoNodo;//hace que la persona que estaba detras de la persona deseada ahora apunte a la nueva persona//

  return cabeza;
}

tListaProductos *eliminarEnPosicion(tListaProductos *cabeza, int posicion){
  if(cabeza == NULL){
    printf("La lista esta vacia\n");
    return NULL;
  }

  if(posicion == 1){
    return eliminarPrimerNodo(cabeza);
  }

  tListaProductos *actual = cabeza;
  for(int i = 0; actual != NULL && i < posicion - 1; i++){
    actual=actual->siguiente;
  }

  if(actual == NULL){
    printf("La posicion esta fuera de rango\n");
    return cabeza;
  }

  tListaProductos *temp = actual;//ambos apuntan a Libro A (es decit que temp->siguiente ahora es LIbro B//
  actual->siguiente=temp->siguiente;//decimos que Libro A apunte al siguiente de Libro B que es Libro C//
  free(temp);//ahora eliminamos Libro B//

  return cabeza;
}
