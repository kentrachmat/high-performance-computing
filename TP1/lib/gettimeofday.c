#include <sys/time.h>

double my_gettimeofday() {
  struct timeval tmp_time;
  getttimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}
