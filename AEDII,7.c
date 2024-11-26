/*1. En la recepción de un banco, la recepcionista entrega un ticket con el número de atención a cada persona.
El sistema almacena los siguientes datos de cada turno: número de turno, nombre del cliente y motivo (1.
transacción 2. consulta). Además de las operaciones básicas para el manejo de la cola con punteros, se
solicita disponer de:
a) una función que devuelva la cantidad de personas que están esperando un turno para realizar una
“transacción”
b) una función que devuelva la cantidad de personas que están esperando un turno para realizar una
“consulta”
c) un listado que permita visualizar el orden, nombre y motivo de cada persona en la cola.
d) Implementar un menú principal que contenga todas las operaciones disponibles.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
  int nroTurno;
  char nombre[50];
  int motivo;
  struct Nodo *siguiente;
}tNodos;

typedef struct Cola{
  tNodos *frente;
  tNodos *final;
}tColas;

void inicializar(tColas *cola);
void datosPersonas(int *turno, char nombre[], int *motivo);
void agregarEncolar(tColas *cola, int turno, char nombre[], int motivo);
int desencolar(tColas *cola, int *turno, char nombre[], int *motivo);
void mostrarCola(tColas *cola);
void mostrarConsultas(tColas *cola);
void mostrarTransacciones(tColas *cola);

int main(){
  tColas cola;
  int nroTurno, motivo, opcion;
  char nombre[50];
  inicializar(&cola);

  while(1)
  {
    printf("1. Agregar cliente\n");
    printf("2. Eliminar cliente\n");
    printf("3. Ver cola\n");
    printf("4. Mostrar el total de personas que estan para transacciones\n");
    printf("5. Mostrar el total de personas que estan para consultas\n");
    printf("6. Salir del programa\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      datosPersonas(&nroTurno,nombre,&motivo);
      agregarEncolar(&cola,nroTurno,nombre,motivo);
      break;
    case 2:
      desencolar(&cola,&nroTurno,nombre,&motivo);
      break;
    case 3:
      mostrarCola(&cola);
      break;
    case 4:
      mostrarTransacciones(&cola);
      break;
    case 5:
      mostrarConsultas(&cola);
      break;
    default:
      printf("Incorrecto. Ingrese una de las opciones ya predeterminadas\n");
      break;
    }
  }
  return 0;
}

void inicializar(tColas *cola){
  cola->frente=NULL;
  cola->final=NULL;
}


void datosPersonas(int *turno, char nombre[], int *motivo){
  printf("Ingrese el numero del turno: ");
  scanf("%d",turno);
  printf("Ingrese su nombre: ");
  scanf("%s",nombre);
  printf("Motivo del ingreso. (1-transaccion, 2-consulta): ");
  scanf("%d",motivo);
}


void agregarEncolar(tColas *cola, int turno, char nombre[], int motivo){
  tNodos *nuevoNodo = (tNodos*)malloc(sizeof(tNodos));
  if(nuevoNodo==NULL){
    printf("Error al asignar memoria\n");
    return;
  }
  nuevoNodo->nroTurno=turno;
  strcpy(nuevoNodo->nombre,nombre);
  nuevoNodo->motivo=motivo;
  nuevoNodo->siguiente=NULL;
  if(cola->final==NULL){
    cola->frente=nuevoNodo;
    cola->final=nuevoNodo;
  }
  else{
    cola->final->siguiente=nuevoNodo;
    cola->final=nuevoNodo;
  }
  printf("Cliente %d añadido en cola\n",turno);
}


int desencolar(tColas *cola, int *turno, char nombre[], int *motivo){
  if(cola->frente==NULL){
    printf("La cola esta vacia\n");
    return 0;
  }
  tNodos *temp = cola->frente;
  *turno=temp->nroTurno;
  strcpy(nombre,temp->nombre);
  *motivo=temp->motivo;
  cola->frente=cola->frente->siguiente;
  if(cola->frente==NULL){
    cola->final=NULL;
  }
  free(temp);
  return 1;
}


void mostrarCola(tColas *cola){
  tNodos *actual = cola->frente;
  if(actual==NULL){
    printf("La cola esta vacia\n");
    return;
  }
  printf("Cola de clientes\n");
  while(actual!=NULL)
  {
    printf("Nro de Turno: %d\n",actual->nroTurno);
    printf("Nombre;: %s\n",actual->nombre);
    printf("Motivo de la consulta: %d\n",actual->motivo);
    actual=actual->siguiente;
  }
}


void mostrarTransacciones(tColas *cola){
  tNodos *actual = cola->frente;
  int contador = 1;
  if(actual==NULL){
    printf("No hay clientes para transacciones\n");
    return;
  }
  printf("Personas que estan para transacciones\n");
  while (actual!=NULL)
  {
    if(actual->motivo==1){
      printf("%d. Nro de Consulta: %d, Nombre: %s\n",contador,actual->nroTurno,actual->nombre);
      contador++;
    }
    actual=actual->siguiente;
  }
}


void mostrarConsultas(tColas *cola){
  tNodos *actual = cola->frente;
  int contador = 1;
  if(actual==NULL){
    printf("No hay personas para consultas\n");
    return;
  }
  printf("Personas que estan para consultas\n");
  while(actual!=NULL)
  {
    if(actual->motivo==2){
      printf("Nro de Turno: %d, Nombre: %s\n",actual->nroTurno,actual->nombre);
      contador++;
    }
    actual=actual->siguiente;
  }
}


