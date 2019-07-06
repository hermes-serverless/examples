#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>

long long iterations;
long long n_threads;
unsigned int* seeds;

inline double drand(unsigned int &seed) {
  return (double)rand_r(&seed) / (double)RAND_MAX;
}

void *calc(void* tid) {
  int id = (intptr_t) id;
  double* in_cnt = (double*) malloc(sizeof(double));
  long long iter = iterations/n_threads;
  if(id == 0) iter += iterations % n_threads;
  unsigned int seed = seeds[id];

  double x,y,d;
  for(long long i=0;i<iter;i++) {
    x = drand(seed);
    y = drand(seed);
    d = x*x + y*y;
    if(d <= 1.0) *in_cnt += 1;
  }

  pthread_exit((void *)in_cnt); 
}

int main() {

  srand(time(NULL));
  scanf("%lld %lld", &iterations, &n_threads);

  pthread_t* threads = (pthread_t *) malloc(n_threads * sizeof(pthread_t));
  seeds = (unsigned int *) malloc(n_threads * sizeof(unsigned int));

  srand(time(NULL));
  for(int i=0;i<n_threads;i++) {
    seeds[i] = rand();
  }

  struct timespec start, finish;
  double elapsed;

  clock_gettime(CLOCK_MONOTONIC, &start);

  int rc;
  for(int i=0;i<n_threads;i++) {
    rc = pthread_create(&threads[i], NULL, calc, (void *)(intptr_t) i);
    if(rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  void *status;
  double tot_in = 0;
  for(int i=0;i<n_threads;i++) {
    pthread_join(threads[i], &status);
    tot_in += *((double*) status);
  }

  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;  

  printf("Elapsed time: %.12lf ms\n", elapsed*1000.0);
  printf("PI: %.12lf\n", 4*(tot_in/(double)iterations));

  return 0;
}