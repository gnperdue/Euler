#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(unsigned long num);

int main(int argc, const char *argv[])
{
	unsigned long the_number = 600851475143L;
	if (argc > 1) {
		the_number = strtol(argv[1], NULL, /*base*/10);
	}
	printf("The number is: %ld\n", the_number);

	unsigned long start_pt = (unsigned long)sqrt((double)the_number);
	printf(" Starting check at: %ld\n", start_pt);

	while (start_pt > 1L) {
		if (0 == the_number % start_pt) {
			if (1L == is_prime(start_pt)) {
				printf(" The largest prime factor is: %ld\n", start_pt);
				break;	
			}
		}
		start_pt--;
	}


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
