#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    char nombre[50];
    int edad;
    float altura;
    struct Nodo *siguiente;
}tNodos;

typedef struct Cola{
    tNodos *frente;
    tNodos *final;
}tColas;

void inicializar(tColas *cola);
void datosPersona(int *edad, float *altura, char nombre[]);
void agregarEncolar(tColas *cola, int edad, float altura, char nombre[]);
int desencolar(tColas *cola, int *edad, float *altura, char nombre[]);
void verCola();

int main(){
    tColas cola;
    int opcion,edad;
    float altura;
    char nombre[50];
    inicializar(&cola);

    while(1)
    {
        printf("*** MENU *** \n");
        printf("1. Agregar persona\n");
        printf("2. Eliminar ultima persona\n");
        printf("3. Ver cola\n");
        printf("4. Salir del programa\n");
        printf("Ingrese una de las opciones predeterminadas: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            datosPersona(&edad,&altura,nombre);
            agregarEncolar(&cola,edad,altura,nombre);
            break;
        case 2:
            desencolar(&cola,&edad,&altura,nombre);
            break;
        case 3:
            verCola(&cola);
            break;
        case 4:
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

void datosPersona(int *edad, float *altura, char nombre[]){
    printf("Ingrese su edad: ");
    scanf("%d",edad);
    printf("Ingrese su altura: ");
    scanf("%f",altura);
    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
}

void agregarEncolar(tColas *cola, int edad, float altura, char nombre[]){
    tNodos *nuevoNodo = (tNodos*)malloc(sizeof(tNodos));
    if(nuevoNodo==NULL){
        printf("Error al asignar memoria\n");
        return;
    }
    nuevoNodo->edad=edad;
    nuevoNodo->altura=altura;
    strcpy(nuevoNodo->nombre,nombre);
    nuevoNodo->siguiente=NULL;
    if(cola->final==NULL){
        cola->frente=nuevoNodo;
        cola->final=nuevoNodo;
    }
    else{
        cola->final->siguiente=nuevoNodo;
        cola->final=nuevoNodo;
    }
    printf("Persona agregada. Nombre: %s\n",nombre);
}

int desencolar(tColas *cola, int *edad, float *altura, char nombre[]){
    if(cola->frente==NULL){
        printf("La cola esta vacia\n");
        return 0;
    }
    tNodos *temp = cola->frente;
    *edad=temp->edad;
    *altura=temp->altura;
    strcpy(nombre,temp->nombre);
    cola->frente=cola->frente->siguiente;
    if(cola->frente==NULL){
        cola->final=NULL;
    }
    free(temp);
    return 1;
}

void verCola(tColas *cola){
    tNodos *actual = cola->frente;
    if(actual==NULL){
        printf("La cola esta vacia\n");
        return;
    }
    printf("***Contenido de la cola***\n");
    while(actual!=NULL)
    {
        printf("Edad: %d, Altura: %.2f, Nombre: %s\n",actual->edad,actual->altura,actual->nombre);
        actual=actual->siguiente;
    }
}
