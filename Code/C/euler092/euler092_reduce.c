#include <stdio.h>
#include <string.h>
#include <mpi.h>

int GetDigitSqSum(int n);
int GetNumberTerminatingAt89(int min_search_point, int max_search_point);
void GetSearchMax(int rank, int comm_size, int* search_max);

int main(void)
{
  int my_rank, comm_sz;

  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  int n89         = 0;   /* total number of number chains terminating with 89 */
  int search_min  = 0;
  int search_max  = 0;
  GetSearchMax(my_rank, comm_sz, &search_max);
  int n_searchers = comm_sz;
  int search_bin  = search_max / n_searchers;

  /* local */
  int local_min = search_min + search_bin * my_rank + 1;
  int local_max = search_min + search_bin * (my_rank + 1);
  int local89   = GetNumberTerminatingAt89(local_min, local_max); 
#if DEBUG
  printf("proc %d: %d to %d -> %d\n", my_rank, local_min, local_max, local89);
#endif

	int count = 1;  /* We are passing one number at a time. */
	int destination = 0;  /* Proc 0 is the _collector_. */
	/* perform a tree-structured collective reduction */
	MPI_Reduce(&local89, &n89, count, MPI_INT, MPI_SUM, 
			destination, MPI_COMM_WORLD);
  
  if (0 == my_rank) {
    printf("The number of numbers terminating at 89 between %d and %d is %d.\n", 
        search_min, search_max, n89);
  }

  MPI_Finalize();
  return 0;
}

void GetSearchMax(int rank, int comm_size, int* search_max)
{
  int sourceproc = 0;
  int count = 1;
  if (0 == rank) {
    printf("Enter the upper search bound (int, not error checked):\n");
    scanf("%d", search_max);
  }
  MPI_Bcast(search_max, count, MPI_INT, sourceproc, MPI_COMM_WORLD);
}

int GetDigitSqSum(int n)
{
  int sum       = 0;
  int digit     = n % 10;
  int newdigit  = n / 10;
  sum          += digit*digit;
  while (0 != newdigit) {
    digit     = newdigit % 10;
    newdigit  = newdigit / 10;
    sum      += digit*digit;
  }
  return sum;
}

/* we will take on faith that every reductive iteration ends in 1 or 89 and
   not look for repeated numbers in the iteration chain and check that the
   repeated number is 89 */
int GetNumberTerminatingAt89(int min_search_point, int max_search_point)
{
  int n89 = 0;
  for (int num = min_search_point; num <= max_search_point; ++num) {
    int digsqsum = num;
    for (;;) {
      digsqsum = GetDigitSqSum(digsqsum);
      if ( 0 == digsqsum) break; /* just in case */
      if ( 1 == digsqsum) break;
      if (89 == digsqsum) { n89++; break; }
    } 
  }
  return n89;
}

