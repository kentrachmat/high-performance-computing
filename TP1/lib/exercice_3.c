#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

double my_gettimeofday() {
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

/*
void puissance_k(int n, int k,int t) {
  float* tab;
  int i,j;

  tab = (float *) malloc (sizeof(float) * n);
  assert(tab != NULL);

  for (i = 0; i < n;i++) {
    tab[i] = (float) i;
  }

  double time1 = my_gettimeofday();

  #pragma omp parallel
  {
  tid = omp_get_thread_num();

  for (i = tid * (n/t); i < (n/t)-1;i++) {
    float res = 1.0;
    
    for (j = 0; j < k;j++) {
      res *= tab[i];
    }
    tab[i] = res;
  }}
  double time2 = my_gettimeofday();

  printf("chrono pour (n,k) = (%d/%d) : %f\n",n,k,(time2-time1));
  for (i = 0; i < n;i++) {
    printf("%f\n",tab[i]);
  }
  free(tab);
}
*/



/*
 * 1 : section critique = critical
 * 2 : atomic
 * 3 : locks
 *
 * **/

#define NB_THREADS 6

double calcul_p(unsigned long long int n) {
  double x,sum,pi = 0.0;
  unsigned long long int i;
  double pas = 1.0/(double) n;
  omp_set_num_threads(6);
  
  #pragma omp parallel private(x,sum)
  {
  unsigned long long int id = omp_get_thread_num();
  for (i=id,sum=0.0;i < n; i+=NB_THREADS) {
    x = ((double)i+0.5)*pas;
    sum += 4.0/(1.0+x*x);
  }
  #pragma omp critical
    pi += sum;
  }
  return pi;
}

int main(int argc, char* argv[]){
  double time1 = my_gettimeofday();
  double pi = calcul_p(1000000000);
  double time2 = my_gettimeofday();
  printf("chrono : %f\npi = %f\n",(time2-time1),pi);
  return 0;
}
