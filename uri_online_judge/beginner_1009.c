#include <stdio.h>
#include <stdlib.h>


int main(void) {

  char nome[25];
  double salario_fixo, total_vendas_mes;
  double comissao = 0.15;

  scanf("%s", nome);
  scanf("%lf", &salario_fixo);
  scanf("%lf", &total_vendas_mes);

  double salario_final = salario_fixo + (total_vendas_mes * comissao);

  printf("TOTAL = R$ %.2lf\n", salario_final);
}
