#include <stdio.h>

#define FALHA 0
#define PLANTIO 1


int main(void) {
  int fazenda[3][5];

  for(int linha = 0; linha < 3; linha++){
    for(int coluna = 0; coluna < 5; coluna++){
      if(coluna % 2 == 0){
        fazenda[linha][coluna] = PLANTIO;
      } else{
        fazenda[linha][coluna] = FALHA;
      }
    }
  }

  int aux_cont_falha = 0;

  for(int linha = 0; linha < 3; linha++){
    for(int coluna = 0; coluna < 5; coluna++){
      if(fazenda[linha][coluna] == FALHA)
        aux_cont_falha++;
    }
  }

  printf("%d\n", aux_cont_falha);
  return 0;
}
