#include <stdio.h>

int a;
int f(int x) { int e = x+1; return e*e;}

int main() {
  int b,c;

  #pragma omp parallel private(c)
  {
    int d; printf("%d\n",f(a+b+c+d));
  }
  return 0;
}
