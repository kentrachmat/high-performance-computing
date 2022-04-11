#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>


double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}                

static long etapes = 1000000000;
double debut,fin;

void main() {
  int i;
  double pi, sum =0.0;

  debut = my_gettimeofday();
  /*#pragma omp parallel for reduction(+:sum)*/
    for (i = 0; i<= etapes;i++) {
      sum = sum + 4.0/(1.0+pow((i/etapes),2));
    }
    pi = (1.0/etapes) * sum;
    fin = my_gettimeofday();
  printf("%f",pi);
}
