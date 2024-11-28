#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NodoArbol{
  char nombre[50];
  int edad;
  float altura;
  struct NodoArbol *izquierda;
  struct NodoArbol *derecha;
}tNodos;

void datosPersonas(char nombre[], int *edad, float *altura);
tNodos *nuevoNodo(char nombre[], int edad, float altura);
tNodos *insertar(tNodos *nodo, char nombre[], int edad, float altura);
void enOrden(tNodos *nodo);

int main(){
  tNodos *raiz = NULL;
  int edad,opcion;
  char nombre[50];
  float altura;

  do
  {
    printf("1. Ingresar persona\n");
    printf("2. Mostrar persona en orden\n");
    printf("3. Salir del programa\n");
    printf("Ingrese una de las opciones predeterminadas: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case  1:
      datosPersonas(nombre,&edad,&altura);
      raiz=insertar(raiz,nombre,edad,altura);
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

void datosPersonas(char nombre[], int *edad, float *altura){
  printf("Ingrese su nombre: ");
  scanf("%s",nombre);
  printf("Ingrese su edad: ");
  scanf("%d",edad);
  printf("Ingrese su altura: ");
  scanf("%f",altura);
}


tNodos *nuevoNodo(char nombre[], int edad, float altura){
  tNodos *nodo = (tNodos*)malloc(sizeof(tNodos));
  strcpy(nodo->nombre,nombre);
  nodo->edad=edad;
  nodo->altura=altura;
  nodo->izquierda=NULL;
  nodo->derecha=NULL;

  return nodo;
}


tNodos *insertar(tNodos *nodo, char nombre[], int edad, float altura){
  if(nodo==NULL){
    return nuevoNodo(nombre,edad,altura);
  }
  if(strcmp(nombre,nodo->nombre) < 0){
    nodo->izquierda=insertar(nodo->izquierda,nombre,edad,altura);
  }
  else if(strcmp(nombre,nodo->nombre) > 0){
    nodo->derecha=insertar(nodo->derecha,nombre,edad,altura);
  }

  return nodo;
}


void enOrden(tNodos *nodo){
  if(nodo!=NULL){
    enOrden(nodo->izquierda);
    printf("Nombre: %s, Edad: %d, Altura: %.2f\n",nodo->nombre,nodo->edad,nodo->altura);
    enOrden(nodo->derecha);
  }
}