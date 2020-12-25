#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
  int info;
  struct NO *esquerda, *direita;
} node, *arvore;


void inserir(arvore *p, int chave) {
  if( *p == NULL ) {
    *p = (arvore) malloc(sizeof(node));
    (*p)->info = chave;
    (*p)->esquerda = NULL;
    (*p)->direita = NULL;
  }
  else if((*p)->info < chave) {
    inserir(&((*p)->direita), chave);
  } else {
    inserir(&((*p)->esquerda), chave);
  }
  return;
}

void imprimir(arvore v, int nivel) {
  if( v != NULL ) {
    imprimir(v->esquerda, nivel+1);

    for(int i=0; i<nivel; i++) {
      printf(" ");
    }

    printf("%d\n", v->info);
    imprimir(v->direita, nivel+1);
  }
  return;
}

void del(arvore *q, arvore *r)
{
  if((*r)->direita != NULL){
    del(q, &((*r)->direita));
  } else {
    (*q)->info = (*r)->info;
    (*q) = *r;
    *r = (*r)->esquerda;
  }
  return;
}

void excluir(arvore *p, int chave) {
  arvore q;
  if(*p == NULL) {
    printf("\n Elemento nao existe!");
  } else if( chave < (*p)->info ) {
    excluir(&((*p)->esquerda), chave);
  } else if( chave > (*p)->info ) {
    excluir(&((*p)->direita), chave);
  } else {
    q = *p;
    if(q->direita == NULL) {
      *p = q->esquerda;
    } else if( q->esquerda == NULL) {
      *p = q->direita;
    } else {
      del(&q, &(q->esquerda));
    }
    free(q);
  }
  return;
}

void percorre_preordem(node * arvore) {
  if( arvore == NULL ) {
    return;
  }

  printf(" %d", arvore->info);
  percorre_preordem(arvore->esquerda);
  percorre_preordem(arvore->direita);
  printf("\n");
  return;
}


void percorre_posordem(node * arvore) {
  if( arvore == NULL ) {
    return;
  }

  percorre_posordem(arvore->esquerda);
  percorre_posordem(arvore->direita);
  printf(" %d", arvore->info);
  return;
}

void percorre_emordem(node * arvore) {
  if( arvore == NULL ) {
    return;
  }

  percorre_emordem(arvore->esquerda);
  printf(" %d", arvore->info);
  percorre_emordem(arvore->direita);
  return;
}

int main(void) {
  arvore root = NULL;
  
  inserir(&root, 2);
  // imprimir(root, 2);

  inserir(&root, 1);
  // imprimir(root, 2);

  inserir(&root, 3);
  imprimir(root, 2);

  excluir(&root, 1);
  percorre_preordem(root);

  return 0;
}
