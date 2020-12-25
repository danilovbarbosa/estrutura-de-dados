#include <stdio.h>


void swap(int *valor1, int *valor2){
  int aux = *valor1;
  *valor1 = *valor2;
  *valor2 = aux;
}

void selection_sort(int vetor[], int tamanho){
  int menor_indice;
  for (int i = 0; i < tamanho - 1; i++){
    menor_indice = i;

    for(int j = i + 1; j < tamanho; j++){
      if (vetor[j] < vetor[menor_indice]){
        menor_indice = j;
      }
    }
    swap(&vetor[menor_indice], &vetor[i]);

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
  selection_sort(vetor, tamanho);
  printf("Vetor ordenado\n");
  imprimir_valores(vetor, tamanho);


  return 0;
}
