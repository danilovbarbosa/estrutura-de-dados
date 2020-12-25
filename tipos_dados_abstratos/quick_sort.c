#include <stdio.h>

void swap(int *valor1, int *valor2){
  int aux = *valor1;
  *valor1 = *valor2;
  *valor2 = aux;
}

int particionar(int vetor[], int inicio, int fim){
  int pivo = vetor[fim];
  int i = inicio - 1;

  for(int j = inicio; j <= fim - 1; j++){
    if(vetor[j] < pivo){
      i++;
      swap(&vetor[i], &vetor[j]);
    }
  }
  swap(&vetor[i + 1], &vetor[fim]);
  return i + 1;

}

void quick_sort(int vetor[], int inicio, int fim){
  if(inicio < fim){
    int fator_particionamento = particionar(vetor, inicio, fim);
    quick_sort(vetor, inicio, fator_particionamento - 1);
    quick_sort(vetor, fator_particionamento + 1, fim);
  }
}

void imprimir_valores(int vetor[], int tamanho){
  for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");
}


int main(void) {
  int vetor [] = {64, 22, 10, 9, 88};
  int tamanho = sizeof(vetor)/sizeof(int);
  quick_sort(vetor, 0, tamanho - 1);
  printf("Vetor ordenado\n");
  imprimir_valores(vetor, tamanho);


  return 0;
}
