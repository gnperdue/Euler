#include <stdio.h>
#include <string.h>
#include <mpi.h>

int GetDigitSum(int n);
int GetNumberTerminatingAt89(int min_search_point, int max_search_point);

int main(void)
{
  int my_rank, comm_sz;

  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  int n89         = 0;   /* total number of number chains terminating with 89 */
  int search_min  = 0;
  int search_max  = 1e7;
  /* int n_searchers = comm_sz; */
  /* int search_bin  = search_max / n_searchers; */

  /* local */

  /* calculate the number of chains ending in 89 for the array */

  /* tags must match when using MPI_Send and MPI_Receive */
  int tag = 0;
  if (0 != my_rank) {
    int destination = 0;
    int number = 1370 + my_rank;
    int digsum = GetDigitSum(number);
    int count  = 1;
    MPI_Send(&digsum, count, MPI_INT, destination, tag, MPI_COMM_WORLD);
  }
  else {
    for (int source = 1; source < comm_sz; ++source) {
      int answer = 0;
      int count  = 1;
      MPI_Recv(&answer, count, MPI_INT, source, tag, 
          MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("The digit sum for process %d is %d\n",
          source, answer);
    }
  }

  if (0 == my_rank) {
    printf("The number of numbers terminating at 89 between %d and %d is %d.\n", 
        search_min, search_max, n89);
  }

  MPI_Finalize();
  return 0;
}

int GetDigitSum(int n)
{
  int sum       = 0;
  int digit     = n % 10;
  int newdigit  = n / 10;
  sum          += digit;
  while (0 != newdigit) {
    digit     = newdigit % 10;
    newdigit  = newdigit / 10;
    sum      += digit;
  }
  return sum;
}

int GetNumberTerminatingAt89(int min_search_point, int max_search_point)
{
  return max_search_point - min_search_point;
}

