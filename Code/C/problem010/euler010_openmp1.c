#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#ifdef _OPENMP
#include <omp.h>
#endif

void usage(const char* prog_name);
int is_prime(unsigned long num);
void prime_sum(unsigned long max_num, unsigned long *global_sum);

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
	printf("The number number of threads is: %d\n", thread_count);

	struct timeval start_time, stop_time;
	gettimeofday(&start_time, NULL);

	unsigned long sum = 0L;

#pragma omp parallel num_threads(thread_count)
	prime_sum(the_number, &sum);

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

void prime_sum(unsigned long max_num, unsigned long *global_sum)
{
#ifdef _OPENMP
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
#else
	int my_rank = 0;
	int thread_count = 1;
#endif

  unsigned long section_size = max_num / thread_count;
  unsigned long edge_piece = max_num - section_size*thread_count;
	if (0 != edge_piece) {
		fprintf(stderr, "The max number must be evenly divisible by the number of threads.\n");
		exit(0);
	}

	unsigned long local_min = section_size * my_rank;
	unsigned long local_max = local_min + section_size;

	unsigned long counter = local_min;
	unsigned long sum = 0L;
	if (counter <= 2) {
		sum = 2L;
		counter = 3L;
	}
	else {
		if (0 == counter % 2) counter++;
	}

  while (counter <= local_max) {
		if (1L == is_prime(counter)) {
			sum += counter;
		}
		counter = counter + 2L;
	}
	printf("The local sum in thread %d of %d is = %ld.\n", 
			my_rank, thread_count, sum);

#pragma omp critical
	*global_sum += sum;	
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

