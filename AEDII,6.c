#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo{
    int dni;
    char nombre[50];
    char apellido[50];
    char email[100];
    int codigoArea;
    float montoAbonar;
    int estudiantes;
    int profesionales;
    struct Nodo *siguiente;
}tPilasInscriptos;

tPilasInscriptos *cima = NULL;

void datosInscriptos(int *dni, char nombre[], char apellido[], char email[], int *codigo, float *monto, int *estudiantes, int *profesionales);
void agregarInscriptos(int dni, char nombre[], char apellido[], char email[], int codigo, float monto, int estudiantes, int profesionales);
int desencolar();
void verCima();
float calcularTotal();

int main(){
    int dni, codigo, opcion, estudiantes, profesionales;
    char nombre[50], apellido[50], email[100];
    float monto;

    while(1){
        printf("*** MENU ***\n");
        printf("1. Agregar inscriptos\n");
        printf("2. Eliminar ultimo inscripto\n");
        printf("3. Revisar ultimo inscripto\n");
        printf("4. Mostrar total recaudado\n");
        printf("5. Salir del programa\n");
        printf("Ingrese una de las opciones predeterminadas: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            datosInscriptos(&dni,nombre,apellido,email,&codigo,&monto,&estudiantes,&profesionales);
            agregarInscriptos(dni,nombre,apellido,email,codigo,monto,estudiantes,profesionales);
            break;
        case 2:
            desencolar();
            break;
        case 3:
            verCima();
            break;
        case 4:
            calcularTotal();
            printf("El total recaudado es: %.2f\n",calcularTotal());
            break;
        case 5:
            printf("Incorrecto., Ingrese una de las opciones predeterminadas\n");
            break;
        default:
            printf("Incorrecto. Ingrese una de las opciones ya definidas\n");
            break;
        }
    }
    return 0;
}

void datosInscriptos(int *dni, char nombre[], char apellido[], char email[], int *codigo, float *monto, int *estudiantes, int *profesionales){
    printf("*** Complete los siguientes campos ***\n");
    printf("D.N.I: ");
    scanf("%d",dni);
    printf("Nombre: ");
    scanf("%s",nombre);
    printf("Apellido: ");
    scanf("%s",apellido);
    printf("Email :");
    scanf("%s",email);
    printf("Codigo de Categoria (1-Estudiantes, 2-Profesionales, 3-Publico General): ");
    scanf("%d",codigo);
    if(*codigo == 1){
        *monto=200;
        printf("EL monto a pagar es: %.2f\n",*monto);
        (*estudiantes)++;
    }
    else if(*codigo == 2 || *codigo == 3){
        *monto=350;
        printf("El monto a pagar es: %.2f\n",*monto);
        (*profesionales)++;       
    }
}


void agregarInscriptos(int dni, char nombre[], char apellido[], char email[], int codigo, float monto, int estudiantes, int profesionales){
    tPilasInscriptos *nuevoNodo = (tPilasInscriptos*)malloc(sizeof(tPilasInscriptos));
    if(nuevoNodo == NULL){
        printf("Error al asignar memoria\n");
    }
    nuevoNodo->dni=dni;
    strcpy(nuevoNodo->nombre,nombre);
    strcpy(nuevoNodo->apellido,apellido);
    strcpy(nuevoNodo->email,email);
    nuevoNodo->codigoArea=codigo;
    nuevoNodo->montoAbonar=monto;
    nuevoNodo->estudiantes=estudiantes;
    nuevoNodo->profesionales=profesionales;
    nuevoNodo->siguiente=cima;
    cima=nuevoNodo;
    printf("Inscripto %d añadido en la pila\n",codigo);
}

int desencolar(){
    if(cima == NULL){
        printf("La pila esta vacia\n");
        return -1;
    }
    int codigoProducto = cima->codigoArea;
    tPilasInscriptos *temp = cima;
    cima=cima->siguiente;
    free(temp);
    printf("Inscripto %d eliminado de la pila\n",codigoProducto);
    return codigoProducto;
}

void verCima(){
    if(cima == NULL){
        printf("La pila esta vacia\n");
    }
    else{
        printf("D.N.I: %d\n",cima->codigoArea);
        printf("Nombre: %s\n",cima->nombre);
        printf("Apellido: %s\n",cima->apellido);
        printf("Email: %s\n",cima->email);
        printf("Codigo de Categoria: %d\n",cima->codigoArea);
        printf("Monto a pagar: %.2f\n",cima->montoAbonar);
    }
}

float calcularTotal(){
    tPilasInscriptos *actual = cima;
    float total = 0;
    while (actual != NULL)
    {
        total+=actual->montoAbonar;
        actual=actual->siguiente;
    }
    
    return total;
}