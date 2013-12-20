#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#ifdef _OPENMP
#include <omp.h>
#endif

void usage(const char* prog_name);
int is_prime(long num);

int main(int argc, const char *argv[])
{
  if (argc < 2) usage(argv[0]);
	/* long the_number = 2000L; */
	long the_number = 2000000L;
	printf("The number is: %ld\n", the_number);

  int thread_count = 1;
#ifdef _OPENMP
  thread_count = strtol(argv[1], NULL, 10);
#else
  printf("OpenMP is not available. Thread count is 1!\n");
#endif
	printf("The number number of threads is: %d\n", thread_count);

	struct timeval start_time, stop_time;
	gettimeofday(&start_time, NULL);

  /* My version of OMP seems to prefer loop variables be signed
     in parallel for loops. */
	long counter = 3L;
	long sum = 2L;
#pragma omp parallel for num_threads(thread_count) \
	default(none) reduction(+: sum) shared(the_number)
	for (counter = 3L; counter < the_number; counter += 2) {
		if (1L == is_prime(counter)) {
			sum += counter;
		}
	}

	gettimeofday(&stop_time,NULL);
	printf(" The sum of the primes is: %ld\n", sum);
	unsigned long long start_us = ((unsigned long long)(start_time.tv_sec))*1000000 +
		(unsigned long long)(start_time.tv_usec);
	unsigned long long stop_us  = ((unsigned long long)(stop_time.tv_sec))*1000000 +
		(unsigned long long)(stop_time.tv_usec);
	unsigned long long tdiff_us = stop_us - start_us;
	printf("  Elapsed time = %llu usec\n", tdiff_us);


	return 0;
}

int is_prime(long num)
{
	if (num <  2L) return 0;
	if (num == 2L) return 1;
	if (num == 3L) return 1;
	long divisor = num - 1L;
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

