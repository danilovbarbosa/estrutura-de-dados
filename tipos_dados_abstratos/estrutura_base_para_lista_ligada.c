#include <stdio.h>
#include <stdlib.h>


//Lista é uma estrutura de dados abstrata (TDA) que nos permite representar uma lista do mundo real, com operações de adição, inserção, remoção, etc.

struct No{
  int valor;
  int *proximo;
  int *anterior;
};


void add(int valor, struct No **lista){
  struct No *no_aux;

  if(*lista == NULL){
    *lista = (struct No*) malloc(sizeof(struct No));
  }


}


int main(){

  struct No *lista;


  return 0;
}
