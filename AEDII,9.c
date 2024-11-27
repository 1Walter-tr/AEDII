#include <stdio.h>

void cuentaRegresiva(int n){
  if(n==0){
    printf("El tiempo ha terminado\n");
  }
  else{
    printf("%d\n",n);
    cuentaRegresiva(n-1);
  }
}

int main(){
  int inicio;
  
  printf("Ingrese el numero por donde empezar la cuenta regresiva: ");
  scanf("%d",&inicio);
  cuentaRegresiva(inicio);
  
  return 0;
}