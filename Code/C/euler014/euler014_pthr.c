#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct collatz {
	int length;
	int input;
} global_collatz;

struct test_range {
  int min;
  int max;
};

int CollatzLength(int n);
void* LongestCollatz(void* range);

const int maxValue = 1000000;
/* const int maxValue = 1000; */

/* threading globals */
int thread_count;
pthread_mutex_t the_mutex;

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s nthreads\n", argv[0]);
    return 0;
  }

  long thread;
  thread_count = strtol(argv[1], NULL, /*base*/10);
#if DEBUG
  printf("Running with %d threads.\n", thread_count);
#endif

  pthread_t* thread_handles;
  thread_handles = malloc(thread_count*sizeof(pthread_t));

  struct test_range* ranges;
  ranges = malloc(thread_count*sizeof(struct test_range));

  pthread_mutex_init(&the_mutex, NULL);

  global_collatz.length = 0;
  global_collatz.input  = 0;

  /* local array */
  int section_size = maxValue / thread_count;
  int edge_piece   = maxValue - ( maxValue / thread_count ) * thread_count;

#if DEBUG
  printf("Starting the loop for thread creation...\n");
#endif
  for (thread = 0; thread < thread_count ; ++thread) {
    int local_min    = section_size * thread;
    int local_max    = local_min + section_size;
    if (maxValue == local_max + edge_piece) local_max += edge_piece;
    ranges[thread].min = local_min;
    ranges[thread].max = local_max;
#if DEBUG
    printf("proc %ld: %d to %d\n", 
        thread, ranges[thread].min, ranges[thread].max);
#endif
    pthread_create(
        &thread_handles[thread], 
        NULL, 
        LongestCollatz, 
        &ranges[thread]
        );
  }

  for (thread = 0; thread < thread_count ; ++thread) {
#if DEBUG
    printf("joining proc %ld\n", thread);
#endif
    pthread_join(thread_handles[thread], NULL);
  }

  printf("The longest Collatz chain is for %d and is %d values long.\n", 
      global_collatz.input, global_collatz.length);

  free(thread_handles);
  pthread_mutex_destroy(&the_mutex);

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

void* LongestCollatz(void* range)
{
  struct test_range *tr = (struct test_range *)range;
  int longestC = 0, tempC = 0, input = 0;
  for (int i = tr->min; i <= tr->max; ++i) {
    tempC = CollatzLength(i);
    if (tempC > longestC) {
      longestC = tempC;
      input    = i;
    }
  }

  /* LOCK - check to see if this is the longest segment */
  pthread_mutex_lock(&the_mutex);
  if (longestC > global_collatz.length) {
    global_collatz.length = longestC;
    global_collatz.input  = input;
  }
  pthread_mutex_unlock(&the_mutex);

  return NULL;
}


