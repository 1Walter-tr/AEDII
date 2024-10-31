#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Nodo{
  char codigoSexo;
  int rangoEdad;
  float peso;
  float altura;
  float imc;
  int personasSobrePeso;
  char clasificacionIMC[50];
  struct Nodo *siguiente;
}tListaIMC;

tListaIMC *crearNodo(char sexo,int edad,float peso,float altura);
float calcularIMC(tListaIMC *cabeza);
void clasificacionIMC(tListaIMC *cabeza);
void ingresoDatos(tListaIMC **cabeza);
void salidaDatosPaciente(tListaIMC *cabeza);
float promedioBajoPeso(tListaIMC *cabeza);
void salidaDatosFinal(tListaIMC *cabeza,int totalEncuestados);

int main(){
  tListaIMC *cabeza = NULL;
  int opcion;
  int totalEncuestados = 1;

  do
  {
    printf("*** MENU ***\n");
    printf("1. Ingresar paciente\n");
    printf("2. Mostrar datos del paciente\n");
    printf("3. Mostrar informe final\n");
    printf("4. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
      ingresoDatos(&cabeza);
      totalEncuestados++;
      break;
    case 2:
      salidaDatosPaciente(cabeza);
      break;
    case 3:
      salidaDatosFinal(cabeza,totalEncuestados);
      break;
    case 4:
      printf("Saliendo...\n");
      break;
    default:
      printf("Ingrese una de las opciones predeterminadas\n");
      break;
    }
  } while (opcion != 4);
  
  return 0;
}

tListaIMC *crearNodo(char sexo,int edad,float peso,float altura){
  tListaIMC *nuevoNodo = (tListaIMC*)malloc(sizeof(tListaIMC));
  nuevoNodo->codigoSexo=sexo;
  nuevoNodo->rangoEdad=edad;
  nuevoNodo->peso=peso;
  nuevoNodo->altura=altura;
  nuevoNodo->siguiente=NULL;

  return nuevoNodo;
}


float calcularIMC(tListaIMC *cabeza){
  tListaIMC *actual = cabeza;
  if(actual != NULL){
    actual->imc = actual->peso / (actual->altura * actual->altura);
    return actual->imc;
  }
  else{
    return 0.0;
  }
}

void clasificacionIMC(tListaIMC *cabeza){
  if(cabeza->codigoSexo == 'F'){
    if(cabeza->imc < 20){
      strcpy(cabeza->clasificacionIMC, "Peso bajo");
    }
    else if(cabeza->imc >= 20 && cabeza->peso <= 25){
        strcpy(cabeza->clasificacionIMC, "Peso normal");
      }
    else if(cabeza->imc > 25){
      strcpy(cabeza->clasificacionIMC, "Sobrepeso");
    }
  }

  if(cabeza->codigoSexo == 'M'){
    if(cabeza->imc < 19){
      strcpy(cabeza->clasificacionIMC, "Peso bajo");
    }
    else if(cabeza->imc >= 19 && cabeza->peso <= 24){
      strcpy(cabeza->clasificacionIMC, "Peso normal");
    }
    else if(cabeza->imc  > 24){
      strcpy(cabeza->clasificacionIMC, "Sobrepeso");
    }
  }
}

void ingresoDatos(tListaIMC **cabeza){
  char codigoSexo;
  int edad;
  float peso;
  float altura;

  printf("Ingrese el sexo del paciente: ");
  scanf(" %c",&codigoSexo);
  printf("Ingrese la edad del paciente: ");
  scanf("%d",&edad);
  printf("Ingrese el peso del paciente: ");
  scanf("%f",&peso);
  printf("Ingrese la altura del paciente: ");
  scanf("%f",&altura);

  tListaIMC *nuevoNodo = crearNodo(codigoSexo,edad,peso,altura);
  nuevoNodo->siguiente=*cabeza;
  *cabeza=nuevoNodo;
}

void salidaDatosPaciente(tListaIMC *cabeza){
  tListaIMC *actual = cabeza;
  int contador = 1;
  if(actual == NULL){
    printf("La lista esta vacia\n");
    return;
  }

  while(actual != NULL){
    printf("*** Datos del paciente %d***\n",contador);
    printf("Sexo: %c\n",actual->codigoSexo);
    printf("Edad: %d\n",actual->rangoEdad);
    printf("Peso: %.2f\n",actual->peso);
    printf("Altura: %.2f\n",actual->altura);
    calcularIMC(cabeza);
    clasificacionIMC(cabeza);
    printf("IMC: %.2f\n",actual->imc);
    printf("Clasificacion IMC: %s\n",actual->clasificacionIMC);
    contador++;
    actual=actual->siguiente;
  }
}

float promedioBajoPeso(tListaIMC *cabeza){
  int sumaBajoPeso=0;
  int totalBajoPeso=0;

  tListaIMC *actual = cabeza;
  while (actual != NULL){
    if(cabeza->imc <= 20 && actual->rangoEdad <= 15){
      sumaBajoPeso=sumaBajoPeso+actual->imc;
      totalBajoPeso++;
      }
      actual=actual->siguiente;
    }
    if(totalBajoPeso > 0){
      return (float)sumaBajoPeso/totalBajoPeso;
    }
    else{
      return 0.0;
    }  
}

void salidaDatosFinal(tListaIMC *cabeza,int totalEncuestados){
  if(cabeza == NULL){
    printf("La lista esta vacia\n");
    return;
  }

  float promedioGeneral = promedioBajoPeso(cabeza);
  int totalSobrepeso=0;
  tListaIMC *actual = cabeza;

  while(actual != NULL)
  {
    if(actual != NULL){
      if(actual->peso > 25 || (actual->codigoSexo == 'M' && actual->peso > 24)){
        totalSobrepeso++;
      }
    }
    actual=actual->siguiente;
  }

  printf("Total de encuestados: %d\n",totalEncuestados);
  printf("Promedio de personas con bajo peso menores de 15 años: %.2f\n",promedioGeneral);
  printf("Total de personas con sobrepeso: %d\n",totalSobrepeso);
  
}