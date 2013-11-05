#include <stdio.h>
#include <string.h>
#include <mpi.h>

/* MPI requires a struct datatype organized as {value,index} */
struct collatz {
	int length;
	int input;
};

int CollatzLength(int n);
struct collatz LongestCollatz(int minToTest, int maxToTest);

/* const int maxValue = 1000000; */
const int maxValue = 1000;

int main(void)
{
  int my_rank, comm_sz;

  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  struct collatz longest_local, longest_overall;

  /* local array */
	int n_sections   = comm_sz;
	int section_size = maxValue / n_sections;
	int edge_piece   = maxValue - ( maxValue / n_sections ) * n_sections;
	int local_min    = section_size * my_rank;
	int local_max    = local_min + section_size;
	if (maxValue == local_max + edge_piece) local_max += edge_piece;

  /* calculate the longest Collatz length in the local array */
	longest_local = LongestCollatz(local_min,local_max);

  int count = 1;
  int destination = 0; /* Process 0 is the collector. */
  MPI_Reduce( &longest_local, &longest_overall, count, MPI_2INT,
     MPI_MAXLOC, destination, MPI_COMM_WORLD);

  if (0 == my_rank) {
    printf("The longest Collatz chain is for %d and is %d values long.\n", 
        longest_overall.input, longest_overall.length);
  }

  MPI_Finalize();
  return 0;
}

int CollatzLength(int n)
{
	if (0 >= n) return n;
	int counter = 1;
	while (1 != n) {
		if (0 == n % 2) {
			n /= 2;
		}	
		else {
			n = 3 * n + 1;
		}
		counter++;
	}
	return counter;
}

struct collatz LongestCollatz(int minToTest, int maxToTest)
{
	struct collatz answer;
	answer.input = minToTest;
	answer.length = 0;
	int longestC = 0, tempC = 0;
	for (int i = minToTest; i <= maxToTest; ++i) {
		tempC = CollatzLength(i);
		if (tempC > longestC) {
			longestC      = tempC;
			answer.input  = i;
			answer.length = longestC;
		}
	}
	return answer;
}


