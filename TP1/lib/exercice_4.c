

double float calcul_p(unsigned long long int n) {
  double float s = 0;
  unsigned long long int i;
  for (i = 0;i < n;i++) {
    s += (4/(1+((i/n)*(i/n))))
  }
  return ((1/n)*s)
}

/*
 * clause reduction / for
 *
 * */
