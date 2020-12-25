#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

// Struct de uma árvore B
struct BTreeNode{
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

//Variável para operações na árvore B
struct BTreeNode *root;

// Função para criar uma árvore B
struct BTreeNode *criarNo(int val, struct BTreeNode * filho){
  struct BTreeNode *novoNo;
  filho = (struct BTreeNode *) malloc(sizeof(struct BTreeNode));
  filho->val[1] = val;
  filho->count = 1;
  filho->link[0] = root;
  filho->link[1] = novoNo; 
  return filho;
}

//Inserir valores na árvore B
void inserirNo(int val, int pos, struct BTreeNode *no, struct BTreeNode *filho){
  int j = no->count;
  while( j >= pos){
    no->val[j+1] = no->val[j];

    no->link[j+1] = no->link[j+1];
    j--;
  }

  no->val[j+1] = val;
  no->link[j+1] = filho;
  no->count++;
}

int main(void) {
  struct BTreeNode *arvoreB;
  root = criarNo(2, root);
  inserirNo(9, 0, root, arvoreB);


  printf("Hello World\n");
  return 0;
}
