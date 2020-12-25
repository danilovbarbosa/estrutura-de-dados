#include <stdio.h>
#include <stdlib.h>

// Estrutura do no/arvore
typedef struct no{
  int informacao;
  struct no * esquerda;
  struct no * direita;
} node, *arvore;

// função para inserir valores na árvore
void inserir(arvore * p, int valor){
  if(*p == NULL){ // verificando se o valor do no é nulo
    *p = (arvore) malloc(sizeof(node)); //usando a função malloc para gerenciar a memória
    (*p)->informacao = valor;
    (*p)->direita = NULL;
    (*p)->esquerda = NULL;
  } else if ((*p)->informacao < valor){
    inserir(&(*p)->direita, valor); //acessando os valores da direita
  } else {
    inserir(&(*p)->esquerda, valor); //acessando os valores da esquerda
  }
}

void imprimir(arvore raiz, int nivel){
  if (raiz != NULL){//verificando se é nulo

    imprimir(raiz->esquerda, nivel+1);//acessando os valores da esquerda

    for (int i = 0; i<nivel; i++){
      printf(" ");
    }

    int valor = raiz->informacao;
    printf("%d\n", valor);//imprimindo o valor
    imprimir(raiz->direita, nivel+1);//acessando os valores da direita
  }
}

void del(arvore *l, arvore *r){
  if((*r)->direita != NULL){//verificando se é nulero
    del(l, &((*r)->direita));
  } else{// rotacionando os nós da árvore
    (*l)->informacao = (*r)->informacao;
    (*l) = *r;
    *r = (*r)->esquerda;
  }
}


void excluir(arvore *p, int chave){
  arvore q;

  if(*p == NULL){//verificando se é nulo
    printf("Erro - nó nulo!\n");
  } else if (chave < (*p)->informacao){
    excluir(&(*p)->esquerda, chave);
  } else if (chave > (*p)->informacao){
    excluir(&(*p)->direita, chave);
  } else {
    q = *p;

    if(q->direita == NULL){
      *p = q->esquerda;// rotacionando os nós da árvore
    } else if (q->esquerda == NULL){
      *p = q->direita;// rotacionando os nós da árvore
    } else {
      del(&q, &(q->esquerda));
    }

    free(q);// liberando memória
  }
}


int main(void) {
  arvore raiz = NULL;

  inserir(&raiz, 16);
  inserir(&raiz, 2);
  inserir(&raiz, 30);
  inserir(&raiz, 4);
  inserir(&raiz, 56);
  inserir(&raiz, 6);

  imprimir(raiz, 0);

  excluir(&raiz, 30);
  printf("-----------\n");
  imprimir(raiz, 0);


  return 0;
}
