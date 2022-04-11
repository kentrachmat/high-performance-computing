/*
 * Université de Lille 
 * Programme de multiplication de matrices carrees.
 */ 

#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>

int SEUIL = 64;// 96 128

double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

#define REAL_T float 
#define NB_TIMES 10

/*** Matmul: ***/
/* C += A x B 
 * square matrices of order 'n'
 */
void matmul(int n, REAL_T *A, REAL_T *B, REAL_T *C){
  int i,j,k;

  for (i=0; i<n; i++){ 
    for (j=0; j<n; j++){
      for (k=0; k<n; k++){
	      C[i*n+j] +=  A[i*n+k] *  B[k*n+j];  
      } /* for k */
    } /* for j */
  } /* for i */
} 

void mm (int crow, int ccol,
    int arow, int acol,
    int brow, int bcol,
    int n,
    int stride,
    float *A, float *B, float *C){

      if (n <= SEUIL) {
        return matmul(n, A + (stride * arow) + acol, B + (stride * brow) + bcol, C + (stride * crow) + ccol);
      }
      else {
        int nn = n/2;

        /* 2eme bloc C1.1 */
        mm(crow, ccol, arow, acol, brow, bcol, nn, stride, A, B, C);
        mm(crow, ccol, arow, acol + nn, brow + nn, bcol, nn, stride, A, B, C);

        /* 2eme bloc C1.2 */
        mm(crow, ccol + nn, arow, acol, brow, bcol + nn, nn, stride, A, B, C);
        mm(crow, ccol + nn, arow, acol + nn, brow + nn, bcol + nn, nn, stride, A, B, C);

        /* 3eme bloc C2.1 */
        mm(crow + nn, ccol, arow + nn, acol, brow, bcol, nn, stride, A, B, C);
        mm(crow + nn, ccol, arow + nn, acol + nn, brow + nn, bcol, nn, stride, A, B, C);

        /* 4eme bloc C2.2 */
        mm(crow + nn, ccol + nn, arow + nn, acol, brow, bcol + nn, nn, stride, A, B, C);
        mm(crow + nn, ccol + nn, arow + nn, acol + nn, brow + nn, bcol + nn, nn, stride, A, B, C);
      }
    }
 
int main(int argc, char **argv)
{
  int i,j;
  double debut=0.0, fin=0.0;
  REAL_T *A, *B, *C;
  int n=2; /* default value */
  int nb=0;
  
  /* Read 'n' on command line: */
  if (argc == 2){
    n = atoi(argv[1]);
  }

  /* Allocate the matrices: */
  if ((A = (REAL_T *) malloc(n*n*sizeof(REAL_T))) == NULL){
    fprintf(stderr, "Error while allocating A.\n");
  }
  if ((B = (REAL_T *) malloc(n*n*sizeof(REAL_T))) == NULL){
    fprintf(stderr, "Error while allocating B.\n");
  }
  if ((C = (REAL_T *) malloc(n*n*sizeof(REAL_T))) == NULL){
    fprintf(stderr, "Error while allocating C.\n");
  }

  /* Initialize the matrices */
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++){
      *(A+i*n+j) = 1 / ((REAL_T) (i+j+1));
      *(B+i*n+j) = 1.0;
      *(C+i*n+j) = 1.0;
    }

  /* Start timing */
  debut = my_gettimeofday();
  for (nb=0; nb<NB_TIMES; nb++){
    /* Do matrix-product C=A*B+C */
    //matmul(n, A, B, C); 
    mm(0, 0, 0, 0, 0, 0, n, n, A, B, C);
    /* End timing */
  }
  fin = my_gettimeofday();

  fprintf( stdout, "For n=%d: total computation time (with gettimeofday()) : %g s\n",
	   n, (fin - debut)/NB_TIMES);
  fprintf( stdout, "For n=%d: performance = %g Gflop/s \n",
	   n, (((double) 2)*n*n*n / ((fin - debut)/NB_TIMES) )/ ((double) 1e9) ); /* 2n^3 flops */
      
  /* Print 2x2 top-left square of C : */
  for(i=0; i<2 ; i++){
    for(j=0; j<2 ; j++)
      printf("%+e  ", C[i*n+j]);
    printf("\n");
  }
  printf("\n");
  /* Print 2x2 bottom-right square of C : */
  for(i=n-2; i<n ; i++){
    for(j=n-2; j<n ; j++)
      printf("%+e  ", C[i*n+j]);
    printf("\n");
  }


  /* Free the matrices: */
  free(A); 
  free(B); 
  free(C);

  return 0;
}
