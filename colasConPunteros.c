#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int entero;
    float flotante;
    char cadena[100];
    struct Nodo *siguiente;
} Nodo;

typedef struct Cola {
    Nodo *frente;
    Nodo *final;
} Cola;

void inicializarCola(Cola *cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

void encolar(Cola *cola, int entero, float flotante, char cadena[]) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria\n");
        return;
    }
    nuevoNodo->entero = entero;
    nuevoNodo->flotante = flotante;
    strcpy(nuevoNodo->cadena, cadena);
    nuevoNodo->siguiente = NULL;
    
    if (cola->final == NULL) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
    printf("Elemento encolado: %d, %.2f, %s\n", entero, flotante, cadena);
}


int desencolar(Cola *cola, int *entero, float *flotante, char cadena[]) {
    if (cola->frente == NULL) {
        printf("La cola está vacía\n");
        return 0;
    }
    Nodo *temp = cola->frente;
    *entero = temp->entero;
    *flotante = temp->flotante;
    strcpy(cadena, temp->cadena);
    
    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    
    free(temp);
    return 1;
}

void verFrente(Cola *cola) {
    if (cola->frente == NULL) {
        printf("La cola está vacía\n");
        return;
    }
    printf("Frente de la cola: %d, %.2f, %s\n", cola->frente->entero, cola->frente->flotante, cola->frente->cadena);
}

int main() {
    Cola cola;
    inicializarCola(&cola);
    int opcion;
    int entero;
    float flotante;
    char cadena[100];

    while (1) {
        printf("*** MENU ***\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Ver frente\n");
        printf("4. Salir\n");
        printf("Ingrese una de las opciones: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un entero: ");
                scanf("%d", &entero);
                printf("Ingrese un flotante: ");
                scanf("%f", &flotante);
                printf("Ingrese una cadena: ");
                scanf("%s", cadena);
                encolar(&cola, entero, flotante, cadena);
                break;
            case 2:
                if (desencolar(&cola, &entero, &flotante, cadena)) {
                    printf("Elemento desencolado: %d, %.2f, %s\n", entero, flotante, cadena);
                }
                break;
            case 3:
                verFrente(&cola);
                break;
            case 4:
                printf("Saliendo...\n");
                exit(0);
            default:
                printf("Opción incorrecta. Ingrese una de las opciones ya definidas\n");
                break;
        }
    }

    return 0;
}
