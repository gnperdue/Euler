#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int GetDigitSqSum(int n);
void* GetNumberTerminatingAt89(void* win);

int thread_count;
struct window {
  int min;
  int max;
  int n89;
};

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s nthreads\n", argv[0]);
    return 0;
  }

  int n89         = 0;   /* total number of number chains terminating with 89 */
  int search_min  = 0;
  int search_max  = 1e7;

  long thread;
  pthread_t* thread_handles;
  struct window* windows;

  thread_count = strtol(argv[1], NULL, /*base*/10);
  thread_handles = malloc(thread_count*sizeof(pthread_t));
  windows = malloc(thread_count*sizeof(struct window));

  int n_searchers = thread_count;
  int search_bin  = search_max / n_searchers;
#if DEBUG
  printf("initialized main variables\n");
#endif

  for (thread = 0; thread < thread_count ; ++thread) {
    int local_min = search_min + search_bin * thread + 1;
    int local_max = search_min + search_bin * (thread + 1);
    windows[thread].min = local_min;
    windows[thread].max = local_max;
    windows[thread].n89 = 0;
#if DEBUG
    printf("proc %ld: %d to %d -> %d\n", 
        thread, windows[thread].min, windows[thread].max, windows[thread].n89);
#endif
    pthread_create(
        &thread_handles[thread], 
        NULL, 
        GetNumberTerminatingAt89, 
        &windows[thread]
        );
  }

  for (thread = 0; thread < thread_count ; ++thread) {
#if DEBUG
    printf("joining proc %ld\n", thread);
#endif
    pthread_join(thread_handles[thread], NULL);
  }

  for (thread = 0; thread < thread_count ; ++thread) {
    n89 += windows[thread].n89;
  }

  free(thread_handles);
  free(windows);

  printf("The number of numbers terminating at 89 between %d and %d is %d.\n", 
      search_min, search_max, n89);
  return 0;
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
void* GetNumberTerminatingAt89(void* win)
{
  struct window *w = (struct window *)win;
  w->n89 = 0;
  for (int num = w->min; num <= w->max; ++num) {
    int digsqsum = num;
    for (;;) {
      digsqsum = GetDigitSqSum(digsqsum);
      if ( 0 == digsqsum) break; /* just in case */
      if ( 1 == digsqsum) break;
      if (89 == digsqsum) { w->n89++; break; }
    } 
  }
  return NULL;
}

