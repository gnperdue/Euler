#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif

void usage(const char* prog_name);
int is_prime(unsigned long num);

int main(int argc, const char *argv[])
{
  if (argc < 2) usage(argv[0]);
	unsigned long the_number = 2000000L;
	printf("The number is: %ld\n", the_number);

  int thread_count = 1;
#ifdef _OPENMP
  thread_count = strtol(argv[1], NULL, 10);
#else
  printf("OpenMP is not available. Thread count is 1!\n");
#endif

  unsigned long counter = 3L;
  unsigned long sum = 2L;

#pragma omp parallel num_threads(thread_count)
  for (counter = 3L; counter < the_number; counter+=2) {
    if (1L == is_prime(counter)) {
#pragma omp critical
      sum += counter;
    }
    counter = counter + 2L;
  }
  printf(" The sum of the primes is: %ld\n", sum);

  return 0;
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

void usage(const char* prog_name)
{
  printf("Usage: %s nthreads \n", prog_name);
  exit(0);
}

