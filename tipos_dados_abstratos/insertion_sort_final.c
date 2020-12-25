#include <stdio.h>
#include <stdlib.h>

void swap(int *valor1, int *valor2){
  int temp = *valor1;
  *valor1 = *valor2;
  *valor2 = temp;
}

void bubble_sort(int *valores, int tamanho){

  if (tamanho < 1) return;

  for(int i = 0; i < tamanho; i++){
    if (valores[i] > valores[i + 1]){
      swap(&valores[i], &valores[i + 1]);
    }
  }

  bubble_sort(valores, tamanho - 1); 
}

void insertionSort(int valores[], int tamanho) 
{ 
	int chave, j; 
	for (int i = 1; i < tamanho; i++) { 
		chave = valores[i]; 
		j = i - 1; 

		while (j >= 0 && valores[j] > chave) { 
			valores[j + 1] = valores[j]; 
			j = j - 1; 
		} 
		valores[j + 1] = chave; 
	} 
} 


int main(void) {
  int teste [] = {100, 33, 48, 96, 2, 5, 67, 99, 10};
  int tamanho = 9;
  int *valores;
  valores = (int * ) malloc(tamanho * sizeof(int));
  for (int i = 0; i < tamanho ;i++){
    valores[i] = teste[i];
  }

  int tamanho_array = sizeof(valores) / sizeof(int);

  bubble_sort(valores, tamanho);
  for (int i = 1; i < tamanho + 1;i++){
    printf("Valor: %d\n", valores[i]);
  }

  printf("======================================\n");

  insertionSort(teste, tamanho);
  for (int i = 0; i < tamanho;i++){
    printf("Valor: %d\n", teste[i]);
  }
  return 0;
}
