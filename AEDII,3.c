/*El departamento de alumnado necesita trabajar con los datos de los alumnos de la materia AEDII, para
ello implementa una lista simplemente enlazada, donde cada nodo guarda el número de libreta
universitaria y el nombre del alumno. Se pide crear las funciones necesarias para:
a) Generar la lista.
b) Insertar el primer alumno (nodo) de la lista.
c) Insertar alumnos al principio de la lista.
d) Eliminar el primer alumno de la lista.
e) Insertar un alumno en una determinada posición dentro de la lista.
f) Eliminar un alumno de una determinada posición de la lista.
g) Visualizar todos los datos de los alumnos que están en la lista.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo{
    int nroLibreta;
    char nombreAlumno[50];
    struct Nodo *siguiente;
}tListaAED;

int conteoAlumnos(tListaAED *cabeza);
tListaAED *crearNodo(int nroLibretaT,char nombreAlumnoT[]);
void ingresoDatos(tListaAED **cabeza);
void salidaDatos(tListaAED *cabeza);
tListaAED *eliminarPrimerAlumno(tListaAED *cabeza);
tListaAED *eliminarEnPosicion(tListaAED *cabeza, int posicion);
tListaAED *insertarEnPosicion(tListaAED *cabeza, int posicion);

int main(){
    tListaAED *cabeza = NULL;
    int posicion;
    int opcion;

    do{
        printf("**** MENU ****\n");
        printf("1. Insertar alumno\n");
        printf("2. Mostrar alumnos\n");
        printf("3. Eliminar primer alumno de la lista\n");
        printf("4. Insertar alumno en posicion\n");
        printf("5. Eliminar alumno en posicion\n");
        printf("6. Salir\n");

        switch (opcion)
        {
        case 1:
            ingresoDatos(&cabeza);
            break;
        case 2:
            salidaDatos(cabeza);
            break;
        case 3:
            cabeza=eliminarPrimerAlumno(cabeza);
            break;
        case 4:
            printf("Ingrese en que posicion quiere insertar al alumno: ");
            scanf("%d",&posicion);
            cabeza=insertarEnPosicion(cabeza,posicion);
            break;
        case 5:
            printf("Ingrese en que posicion quiere eliminar al alumno\n");
            scanf("%d",&posicion);
            cabeza=eliminarEnPosicion(cabeza,posicion);
            break;
        case 6:
            printf("Saliendo...\n");
            break;
        default:
            printf("Ingrese la opcion correcta\n");
            break;
        }
    }while(opcion != 6);

    return 0;
}

int conteoAlumnos(tListaAED *cabeza){
    int conteo = 0;
    tListaAED *actual = cabeza;
    while(actual != NULL){
        conteo++;
        actual = actual->siguiente;
    }

    return conteo;
}

tListaAED *crearNodo(int nroLibretaT, char nombreAlumnoT[]){
    tListaAED *nuevoNodo = (tListaAED*)malloc(sizeof(tListaAED));
    nuevoNodo->nroLibreta=nroLibretaT;
    strcpy(nuevoNodo->nombreAlumno,nombreAlumnoT);
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}

void ingresoDatos(tListaAED **cabeza){
    int nroLibreta;
    char nombreAlumno[50];

    printf("Ingrese el numero de libreta del alumno: ");
    scanf("%d",&nroLibreta);
    printf("Ingrese el nombre del alumno: ");
    scanf("%s",nombreAlumno);

    tListaAED *nuevoNodo = crearNodo(nroLibreta,nombreAlumno);
    nuevoNodo->siguiente=*cabeza;
    *cabeza=nuevoNodo;
}

void salidaDatos(tListaAED *cabeza){
    tListaAED *actual = cabeza;
    if(actual == NULL){
        printf("La lista esta vacia\n");
        return NULL;
    }

    while(actual != NULL){
        printf("Nro de libreta: %d\n",actual->nroLibreta);
        printf("Nombre del alumno: %s\n",actual->nombreAlumno);
        actual=actual->siguiente;
    }
}

tListaAED *eliminarPrimerAlumno(tListaAED *cabeza){
    if(cabeza == NULL){
        printf("La lista esta vacia\n");
        return NULL;
    }

    tListaAED *temp = cabeza;
    cabeza=cabeza->siguiente;
    free(temp);

    return cabeza;
}

tListaAED *eliminarEnPosicion(tListaAED *cabeza, int posicion){
    if(cabeza == NULL){
        printf("La lista esta vacia\n");
        return NULL;
    }

    if(posicion == 1){
        return eliminarPrimerAlumno(cabeza);
    }

    tListaAED *actual = cabeza;
    for(int i = 0; actual != NULL && i < posicion - 1; i++){
        actual=actual->siguiente;
    }

    if(actual == NULL){
        printf("La posicion esta fuera de rango\n");
        return cabeza;
    }

    tListaAED *temp = actual;
    actual->siguiente=temp->siguiente;
    free(temp);

    return cabeza;
}

tListaAED *insertarEnPosicion(tListaAED *cabeza, int posicion){
    int nroLibreta;
    char nombreAlumno[50];

    printf("Ingrese el nro de la libreta del alumno: ");
    scanf("%d",&nroLibreta);
    printf("Ingrese el nombre del alumno: ");
    scanf("%s",nombreAlumno);

    if(cabeza == 1){
        tListaAED *nuevoNodo = crearNodo(nroLibreta,nombreAlumno);
        nuevoNodo->siguiente=cabeza;
        return nuevoNodo;
    }

    tListaAED *actual = cabeza;
    for(int i = 0; actual != NULL && i < posicion - 1; i++){
        actual=actual->siguiente;
    }

    if(actual == NULL){
        printf("La posicion esta fuera de rango\n");
        return cabeza;
    }

    tListaAED *nuevoNodo = crearNodo(nroLibreta,nombreAlumno);
    nuevoNodo->siguiente=actual->siguiente;
    actual->siguiente=nuevoNodo;

    return cabeza;
}