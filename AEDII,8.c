/*2. Se necesita procesar los datos de los llamados que ingresan al call center de una empresa de
telecomunicaciones. Para ello se implementa una cola, en donde cada nodo contiene los siguientes datos:
nombre y apellido, número de teléfono, DNI, código de lugar de procedencia (01-Corrientes 02-Chaco).
Se solicita escribir las funciones para:
a) Conocer la cantidad de llamadas provenientes de cada lugar de procedencia y la cantidad total
de llamadas en cola de espera.
b) Generar un listado que incluya los números telefónicos de las llamadas provenientes de
Corrientes.
Tener en cuenta que se deben realizar las operaciones básicas necesarias para la manipulación de la cola con
punteros.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo{
  char nombre[50];
  char apellido[50];
  char nroTelefono[50]; /*Esto lo hice porque me tiraba error en todo momento de que no se podia utilizar long int entonces mientras tanto use esto para que funcione hasta "arreglar" este error, de igual manera el codigo cumple su funcion*/
  int dni;
  int codigoProcedencia;
  struct Nodo *siguiente;
}tNodos;

typedef struct Cola{
  tNodos *frente;
  tNodos *final;
}tColas;

void inicializar(tColas *cola);
void datosPersonas(char nombre[], char apellido[], char telefono[50], int *dni, int *codigo);
void agregarEncolar(tColas *cola, char nombre[], char apellido[], char telefono[], int dni, int codigo);
int desencolar(tColas *cola, char nombre[], char apellido[], char telefono[], int *dni, int *codigo);
void mostrarCLientes(tColas *cola);
void llamadasCorrientes(tColas *cola);

int main(){
  tColas cola;
  char nombre[50], apellido[50];
  char telefono[50];
  int dni, codigo, opcion;
  inicializar(&cola);

  while(1)
  {
    printf("1. Agregar cliente\n");
    printf("2. Eliminar cliente\n");
    printf("3. Mostrar clientes\n");
    printf("4. Mostrar la lista de espera de clientes provenientes de la localidad de Corrientes\n");
    printf("5. Salir\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      datosPersonas(nombre,apellido,telefono,&dni,&codigo);
      agregarEncolar(&cola,nombre,apellido,telefono,dni,codigo);
      break;
    case 2:
      desencolar(&cola,nombre,apellido,telefono,&dni,&codigo);
      break;
    case 3:
      mostrarCLientes(&cola);
      break;
    case 4:
      llamadasCorrientes(&cola);
      break;
    case 5:
      printf("Saliendo...\n");
      exit(0);
      break;
    default:
      printf("Incorrecto. Ingrese una de las opciones ya definidas\n");
      break;
    }
  }
  return 0;
}

void inicializar(tColas *cola){
  cola->frente=NULL;
  cola->final=NULL;
}


void datosPersonas(char nombre[], char apellido[], char telefono[], int *dni, int *codigo){
  printf("Ingrese su nombre: ");
  scanf("%s",nombre);
  printf("Ingrese su apellido: ");
  scanf("%s",apellido);
  printf("Ingrese su numero de telefono: ");
  scanf("%s",telefono);
  printf("Telefono ingresado: %s\n",telefono);
  printf("Ingrese su D.N.I: ");
  scanf("%d",dni);
  printf("Ingrese el codigo de procedencia (01-Corrientes 02-Chaco): ");
  scanf("%d",codigo);
}


void agregarEncolar(tColas *cola, char nombre[], char apellido[], char telefono[], int dni, int codigo){
  tNodos *nuevoNodo = (tNodos*)malloc(sizeof(tNodos));
  if(nuevoNodo==NULL){
    printf("Error al asignar memoria\n");
    return;
  }
  strcpy(nuevoNodo->nombre,nombre);
  strcpy(nuevoNodo->apellido,apellido);
  strcpy(nuevoNodo->nroTelefono,telefono);
  nuevoNodo->dni=dni;
  nuevoNodo->codigoProcedencia=codigo;
  nuevoNodo->siguiente=NULL;
  if(cola->final==NULL){
    cola->frente=nuevoNodo;
    cola->final=nuevoNodo;
  }
  else{
    cola->final->siguiente=nuevoNodo;
    cola->final=nuevoNodo;
  }
  printf("Cliente %s, %s añadido\n",nombre,apellido);
}


int desencolar(tColas *cola, char nombre[], char apellido[], char telefono[], int *dni, int *codigo){
  if(cola->frente==NULL){
    printf("La pila esta vacia\n");
    return 0;
  }
  tNodos *temp = cola->frente;
  strcpy(nombre,temp->nombre);
  strcpy(apellido,temp->apellido);
  strcpy(telefono,temp->nroTelefono);
  *dni=temp->dni;
  *codigo=temp->codigoProcedencia;
  cola->frente=cola->frente->siguiente;
  if(cola->frente==NULL){
    cola->final=NULL;
  }
  free(temp);
  return 1;
}


void mostrarCLientes(tColas *cola){
  tNodos *actual = cola->frente;
  int contador=1;
  if(actual==NULL){
    printf("La cola esta vacia\n");
    return;
  }
  while(actual!=NULL)
  {
    printf("Nombre: %s\n",actual->nombre);
    printf("Apellido: %s\n",actual->apellido);
    printf("Nro de Celular: %s\n",actual->nroTelefono);
    printf("D.N.I: %d\n",actual->dni);
    printf("Codigo de Procedencia: %d\n",actual->codigoProcedencia);
    printf("Cantidad de llamadas recibidas: %d\n",contador);
    contador++;
    actual=actual->siguiente;
  }
}

void llamadasCorrientes(tColas *cola){
  tNodos *actual = cola->frente;
  int contador=1;
  if(cola->frente==NULL){
    printf("La cola esta vacia\n");
    return;
  }
  printf("Llamadas provenientes de la localidad de Corrientes\n");
  while(actual!=NULL)
  {
    if(actual->codigoProcedencia==1){
      printf("%d. Nombre: %s\n",contador,actual->nombre);
      printf("Apellido: %s\n",actual->apellido);
      printf("Nro de celular: %s\n",actual->nroTelefono);
      printf("D.N.I: %d\n\n\n",actual->dni);
      contador++;
    }
    actual=actual->siguiente;
  }
}