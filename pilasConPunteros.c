#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo *siguiente;
}tPilas;

tPilas *cima = NULL;

void agregar(int valor);
int desenpilar();
int verCima();

int main(){
    int opcion;
    int valor;

    while(1)
    {
        printf("*** MENU ***\n");
        printf("1. Ingresar elementos en la pila\n");
        printf("2. Eliminar elemnto de la pila\n");
        printf("3. Rvisar elemento superior\n");
        printf("4. Salir\n");

        printf("Ingrese una de las opciones en pantalla: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el valor que desea insertar en la pila: ");
            scanf("%d",&valor);
            agregar(valor);
            break;
        case 2:
            desenpilar();
            break;
        case 3: 
            valor = verCima();
            if(valor != -1){
                printf("EL valor superior de la pila es: %d\n",valor);
            }
            break;
        case 4: 
            printf("Saliendo...\n");
            exit(0);
        default:
            printf("Incorrecto. Ingrese una de las opciones predterminadas\n");
            break;
        }   
    }

    return 0;
}

void agregar(int valor){
    tPilas *nuevoNodo = (tPilas*)malloc(sizeof(tPilas));
    if(nuevoNodo == NULL){
        printf("Error al asginar memoria\n");
        return;
    }
    nuevoNodo->dato=valor;
    nuevoNodo->siguiente=cima;
    cima=nuevoNodo;
    printf("Elemento %d añadido a la pila\n",valor);
}

int desenpilar(){
    if(cima == NULL){
        printf("La pila esta vacia\n");
        return -1;
    }
    int valor = cima->dato;

    tPilas *temp = cima;
    cima=cima->siguiente;
    free(temp);
    printf("Elemento %d eliminado\n",valor);
    return valor;
}

int verCima(){
    if(cima == NULL){
        printf("La pila esta vacia\n");
        return -1;
    }
    else{
        return cima->dato;
    }
}