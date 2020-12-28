#include <stdio.h>
#include <stdlib.h>
 
int main() {
  double n = 3.14159, raio;

  scanf("%lf", &raio);

  double area = n * (raio * raio);

  printf("A=%.4lf\n", area);
 
  return 0;
}
