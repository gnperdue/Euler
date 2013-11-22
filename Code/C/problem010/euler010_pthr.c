#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

const unsigned int MAX_THREADS = 10;

struct range_sum {
  unsigned long min;
  unsigned long max;
  unsigned long sum;
};

unsigned int thread_count;

/* shared memory array for intermediate sums */
unsigned long *sums;

void usage(const char* prog_name);
int is_prime(unsigned long num);
void* prime_sum(void* range);

int main(int argc, const char *argv[])
{
  if (argc < 2) usage(argv[0]);

  unsigned long the_number = 2000000L;
  unsigned int thread = 0;

  thread_count = (unsigned int)atoi(argv[1]);
  if (thread_count == 0 || thread_count > MAX_THREADS) usage(argv[0]);

  /* create space for the threads */
  pthread_t* thread_handles;
  thread_handles = (pthread_t*)malloc(thread_count*sizeof(pthread_t));

  /* create space for the sums array and init elems to 0 */
  sums = (unsigned long*)malloc(thread_count*sizeof(unsigned long));
  for (thread = 0; thread < thread_count; ++thread) {
    sums[thread] = 0L;
  }

  /* create space for the ranges for each sum */
  struct range_sum* ranges;
  ranges = malloc(thread_count*sizeof(struct range_sum));

  unsigned long section_size = the_number / thread_count;
  unsigned long edge_piece = the_number - section_size*thread_count;

  for (thread = 0; thread < thread_count; ++thread) {
    unsigned long local_min = section_size * thread;
    unsigned long local_max = local_min + section_size;
    if (the_number == local_max + edge_piece) local_max += edge_piece;
    ranges[thread].min = local_min;
    ranges[thread].max = local_max;
    ranges[thread].sum = 0L;
    pthread_create(&thread_handles[thread], NULL, prime_sum, &ranges[thread]);
  }
  for (thread = 0; thread < thread_count; ++thread) {
    pthread_join(thread_handles[thread], NULL);
  }

  unsigned long sum = 0L;
  for (thread = 0; thread < thread_count; ++thread) {
#if DEBUG
    printf("range min, max = %ld, %ld\n", ranges[thread].min, ranges[thread].max);
    printf(" range sum = %ld\n", ranges[thread].sum);
#endif
    sum += ranges[thread].sum;
  }
  printf(" The sum of the primes is: %ld\n", sum);

  free(sums);
  free(thread_handles);

  return 0;
}

void usage(const char* prog_name)
{
  printf("Usage: %s nthreads (max=%d)\n", prog_name, MAX_THREADS);
  exit(0);
}

int is_prime(unsigned long num)
{
  if (num <  2L) return 0;
  if (num == 2L) return 1;
  if (num == 3L) return 1;
  unsigned long divisor = num - 1L;
  while (divisor > 1L) {
    if (num % divisor == 0) return 0;
    divisor--;
  }	
  return 1;
}

void* prime_sum(void* range) 
{
  struct range_sum *tr = (struct range_sum *)range;

  unsigned long counter = tr->min;
  unsigned long sum = 0L;
  if (counter <= 2) {
    sum = 2L;
    counter = 3L;
  }
  else {
    if (0 == counter % 2) counter++;
  }

  while (counter <= tr->max) {
    if (1L == is_prime(counter)) {
      sum += counter;
    }
    counter = counter + 2L;
  }
  tr->sum = sum;

  return NULL;
}
