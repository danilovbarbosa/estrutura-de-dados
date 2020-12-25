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
int buscaBinariaR(int valores[], int inicio, int fim, int chave){
  if (inicio <= fim) {                    
    int metade = (inicio + fim) / 2;
    if (chave == valores[metade]) {
        return metade;
    } else {
      if (chave > valores[metade]) {
        inicio = metade + 1;
        return buscaBinariaR(valores, inicio, fim, chave);
      } else {
        fim = metade - 1;
        return buscaBinariaR(valores, inicio, fim, chave);
      }
    }
  } else {
    return -1;
  }
}



int main(void) {
  int teste [] = {1, 3, 4, 9, 20, 55, 67, 99, 100};
  int tamanho = sizeof(teste)/sizeof(int);
  
  printf("Valor recuperado I: %d\n", buscaBinariaI(teste, tamanho, 99));
  printf("Valor recuperado R: %d\n", buscaBinariaR(teste, 0, tamanho - 1, 3));

  return 0;
}
