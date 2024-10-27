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

// Definición de la estructura del nodo de la lista enlazada
typedef struct Nodo{
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;
  struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} tListaProductos;

// Funciones para operar sobre la lista enlazada
tListaProductos *crearNodo(int codigoProductoT, char descripcionProductoT[], float precioProductoT);
void ingresoDatos(tListaProductos **cabeza);
void salidaDatos(tListaProductos *cabeza);
tListaProductos* eliminarPrimerNodo(tListaProductos *cabeza);
tListaProductos* insertarEnPosicion(tListaProductos *cabeza, int posicion);
tListaProductos* eliminarEnPosicion(tListaProductos *cabeza, int posicion);

int main() {
  tListaProductos *cabeza = NULL; // Inicializamos la lista vacía
  int opcion, posicion;

  do {
    printf("\n=== MENU ===\n");
    printf("1. Insertar producto\n");
    printf("2. Mostrar productos\n");
    printf("3. Eliminar primer producto\n");
    printf("4. Insertar producto en posicion\n");
    printf("5. Eliminar producto en posicion\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
      case 1:
        ingresoDatos(&cabeza);
        break;
      case 2:
        salidaDatos(cabeza);
        break;
      case 3:
        cabeza = eliminarPrimerNodo(cabeza);
        break;
      case 4:
        printf("Ingrese la posicion donde desea insertar: ");
        scanf("%d", &posicion);
        cabeza = insertarEnPosicion(cabeza, posicion);
        break;
      case 5:
        printf("Ingrese la posicion del producto a eliminar: ");
        scanf("%d", &posicion);
        cabeza = eliminarEnPosicion(cabeza, posicion);
        break;
      case 6:
        printf("Saliendo del programa...\n");
        break;
      default:
        printf("Opcion invalida. Intente de nuevo.\n");
    }
  } while(opcion != 6);

  return 0;
}

// ===========================
// Crear un nuevo nodo
// ===========================
tListaProductos *crearNodo(int codigoProductoT, char descripcionProductoT[], float precioProductoT) {
  tListaProductos *nuevoNodo = (tListaProductos*)malloc(sizeof(tListaProductos));
  nuevoNodo->codigoProducto = codigoProductoT;
  strcpy(nuevoNodo->descripcionProducto, descripcionProductoT);
  nuevoNodo->precioProducto = precioProductoT;
  nuevoNodo->siguiente = NULL; // El nuevo nodo apunta a NULL (al final de la lista)

  return nuevoNodo;
}

// ==========================================
// Ingresar datos de un nuevo producto
// ==========================================
void ingresoDatos(tListaProductos **cabeza) {
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;

  printf("Ingrese el codigo del producto: ");
  scanf("%d", &codigoProducto);
  printf("Ingrese la descripcion del producto: ");
  scanf("%s", descripcionProducto);
  printf("Ingrese el precio del producto: ");
  scanf("%f", &precioProducto);

  tListaProductos *nuevoNodo = crearNodo(codigoProducto, descripcionProducto, precioProducto);
  nuevoNodo->siguiente = *cabeza; // El nuevo nodo apunta al primer nodo de la lista
  *cabeza = nuevoNodo; // El nuevo nodo se convierte en el primero de la lista
}

// ======================================
// Mostrar los productos en la lista
// ======================================
void salidaDatos(tListaProductos *cabeza) {
  tListaProductos *actual = cabeza;
  if (actual == NULL) {
    printf("La lista está vacía.\n");
    return;
  }
  
  while (actual != NULL) {
    printf("Codigo del producto: %d\n", actual->codigoProducto);
    printf("Descripcion del producto: %s\n", actual->descripcionProducto);
    printf("Precio del producto: %.2f\n", actual->precioProducto);
    actual = actual->siguiente; // Avanzamos al siguiente nodo
  }
}

// ==========================================
// Eliminar el primer nodo de la lista
// ==========================================
tListaProductos* eliminarPrimerNodo(tListaProductos *cabeza) {
  if (cabeza == NULL) {
    printf("La lista ya está vacía.\n");
    return NULL;
  }
  tListaProductos *temp = cabeza; // Guardamos el nodo a eliminar
  cabeza = cabeza->siguiente; // El segundo nodo se convierte en el primero
  free(temp); // Liberamos la memoria del nodo eliminado

  return cabeza;
}

// ==============================================
// Insertar un nodo en una posición específica
// ==============================================
tListaProductos* insertarEnPosicion(tListaProductos *cabeza, int posicion) {
  int codigoProducto;
  char descripcionProducto[50];
  float precioProducto;

  // Solicitar los datos del producto al usuario
  printf("Ingrese el codigo del producto: ");
  scanf("%d", &codigoProducto);
  printf("Ingrese la descripcion del producto: ");
  scanf("%s", descripcionProducto);
  printf("Ingrese el precio del producto: ");
  scanf("%f", &precioProducto);

  if (posicion == 0) { // Si es la primera posición
    tListaProductos *nuevoNodo = crearNodo(codigoProducto, descripcionProducto, precioProducto);
    nuevoNodo->siguiente = cabeza;
    return nuevoNodo;
  }

  tListaProductos *actual = cabeza;
  for (int i = 0; actual != NULL && i < posicion - 1; i++) {
    actual = actual->siguiente; // Navegamos hasta la posición deseada
  }

  if (actual == NULL) {
    printf("La posición está fuera de rango.\n");
    return cabeza;
  }

  tListaProductos *nuevoNodo = crearNodo(codigoProducto, descripcionProducto, precioProducto);
  nuevoNodo->siguiente = actual->siguiente;
  actual->siguiente = nuevoNodo; // Insertamos el nuevo nodo en la posición indicada

  return cabeza;
}

// ==============================================
// Eliminar un nodo en una posición específica
// ==============================================
tListaProductos* eliminarEnPosicion(tListaProductos *cabeza, int posicion) {
  if (cabeza == NULL) {
    printf("La lista está vacía.\n");
    return NULL;
  }

  if (posicion == 0) {
    return eliminarPrimerNodo(cabeza); // Si es la primera posición, eliminamos el primer nodo
  }

  tListaProductos *actual = cabeza;
  for (int i = 0; actual != NULL && i < posicion - 1; i++) {
    actual = actual->siguiente; // Navegamos hasta el nodo anterior al que queremos eliminar
  }

  if (actual == NULL || actual->siguiente == NULL) {
    printf("La posición está fuera de rango.\n");
    return cabeza;
  }

  tListaProductos *temp = actual->siguiente; // Nodo a eliminar
  actual->siguiente = temp->siguiente; // Ajustamos los punteros
  free(temp); // Liberamos la memoria del nodo eliminado

  return cabeza;
}
