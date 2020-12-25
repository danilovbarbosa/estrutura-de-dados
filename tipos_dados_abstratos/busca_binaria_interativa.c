#include <stdio.h>

int buscaBinariaI(int valores[], int tamanho, int chave){
  int inicio = 0;
  int fim = tamanho - 1;
  while(inicio <= fim){
    int metade = (inicio + fim) / 2;
    
    if (chave == valores[metade]){
      return metade;
    } else {
      if (chave > valores[metade]){
        inicio = metade + 1;
      } else {
        fim = metade -1;
      }
    }
  }

  return -1;
}

//Recursivo
int buscaBinariaR(int valores[], int tamanho, int chave){
}



int main(void) {
  int teste [] = {1, 3, 4, 9, 20, 55, 67, 99, 100};
  int tamanho = sizeof(teste)/sizeof(int);
  
  printf("Valor recuperado: %d", buscaBinariaI(teste, tamanho, 101));

  return 0;
}
