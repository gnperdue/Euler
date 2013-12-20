#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

int is_prime(unsigned long num);

int main(int argc, const char *argv[])
{
	unsigned long the_number = 2000000L;
	if (argc > 1) {
		the_number = strtol(argv[1], NULL, /*base*/10);
	}
	printf("The number is: %ld\n", the_number);

	struct timeval start_time, stop_time;
	gettimeofday(&start_time, NULL);

	unsigned long counter = 3L;
	unsigned long sum = 2L;

	while (counter < the_number) {
		if (1L == is_prime(counter)) {
			sum += counter;
		}
		counter = counter + 2L;
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
