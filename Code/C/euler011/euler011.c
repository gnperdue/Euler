#include <stdio.h>
#include <string.h>

const int mat_size = 20;
const int n_directions = 8;

int chars_to_num( char *buf, int len ) {
  int pow = 1;
  int result = 0;
  for (int i = len-1; i >= 0; --i) {
    result += (buf[i] - '0') * pow;
    pow *= 10;
  }
  return result;
}

void display_mat(int (*mat)[mat_size]) 
{
  printf("----\n");
  for (int a = 0; a < mat_size; ++a) {
    for (int b = 0; b < mat_size; ++b) {
      printf("%02d ", mat[a][b]);
    }
    printf("\n");
  }
  printf("----\n");
}

/* read the file line-by-line and convert chars into ints by accumulating
   the chars in an array until we hit a space. then, make a number and
   start over again. */
void read_mat(int (*mat)[mat_size], FILE* fp) 
{
  char buffer[100];
  int row = 0;

  int temp[20] = {0};
  char holder[20] = {0};
  int i = 0, j = 0, k = 0;

  /* read each line in the file */
  while (NULL != fgets(buffer, 100, fp)) {

    /* until we get to the EOL, look for space separated numbers */
    while (buffer[i] != '\n') {
      if (buffer[i] != ' ') {
        /* keep the numbers until we find a space in `holder` */
        holder[j] = buffer[i];
        j++;
      } 
      else {
        /* once we hit a space, conver the chars in `holder` into a number 
           and keep it in `temp` */
        temp[k] = chars_to_num( holder, j );
        k++;
        j = 0;
        memset(holder, 0, 20);
      }
      i++;
    }
    temp[k] = chars_to_num( holder, j );

    int cols = 0;
    for (cols = 0; cols < mat_size; ++cols) {
      mat[row][cols] = temp[cols];
    }
    row++;
    i = 0;
    j = 0;
    k = 0;
    memset(holder, 0, 20);
    memset(temp, 0, 20);
  }
}

void compute_products(int (*numbers)[mat_size], int a, int b, int directions[])
{
#if DEBUG
  printf("numbers[%d][%d] = %d\n", a, b, numbers[a][b]);
#endif
  /* 8 directions: n(0), ne(1), e(2), se(3), s(4), sw(5), w(6), nw(7) */
  int dirs[8] = {1,1,1,1,1,1,1,1};
  if (a < 3) { /* north directions impossible */
    dirs[0] = 0; dirs[1] = 0; dirs[7] = 0;
  }
  if (a > 16) { /* south directions impossible */
    dirs[3] = 0; dirs[4] = 0; dirs[5] = 0;
  }
  if (b < 3) { /* west directions impossible */
    dirs[5] = 0; dirs[6] = 0; dirs[7] = 0;
  }
  if (b > 16) { /* east directions impossible */
    dirs[1] = 0; dirs[2] = 0; dirs[3] = 0;
  }
#if DEBUG
  for (int i=0; i<8; ++i) {
    printf("%d", dirs[i]);
  }
  printf("\n");
#endif
  
  memset(directions, 0, 8*sizeof(int));
  if (1 == dirs[0]) {
    directions[0] = numbers[a][b] * numbers[a-1][b] * 
      numbers[a-2][b] * numbers[a-3][b];
  }
  if (1 == dirs[1]) {
    directions[1] = numbers[a][b] * numbers[a-1][b+1] * 
      numbers[a-2][b+2] * numbers[a-3][b+3];
  }
  if (1 == dirs[2]) {
    directions[2] = numbers[a][b] * numbers[a][b+1] * 
      numbers[a][b+2] * numbers[a][b+3];
  }
  if (1 == dirs[3]) {
    directions[3] = numbers[a][b] * numbers[a+1][b+1] * 
      numbers[a+2][b+2] * numbers[a+3][b+3];
  }
  if (1 == dirs[4]) {
    directions[4] = numbers[a][b] * numbers[a+1][b] * 
      numbers[a+2][b] * numbers[a+3][b];
  }
  if (1 == dirs[5]) {
    directions[5] = numbers[a][b] * numbers[a+1][b-1] * 
      numbers[a+2][b-2] * numbers[a+3][b-3];
  }
  if (1 == dirs[6]) {
    directions[6] = numbers[a][b] * numbers[a][b-1] * 
      numbers[a][b-2] * numbers[a][b-3];
  }
  if (1 == dirs[7]) {
    directions[7] = numbers[a][b] * numbers[a-1][b-1] * 
      numbers[a-2][b-2] * numbers[a-3][b-3];
  }
#if DEBUG
  for (int i=0; i<8; ++i) {
    printf("%d ", directions[i]);
  }
  printf("\n");
#endif
}


int main(int argc, char *argv[]) 
{
  FILE *fp;
  int numbers[mat_size][mat_size];

  if (NULL == (fp = fopen("grid.txt", "r"))) return 1;

  read_mat(numbers, fp);
#if DEBUG
  display_mat(numbers);
#endif

  int max_product = 0;
  int max_idxa    = 0;
  int max_idxb    = 0;
  int max_dir     = -1;
  int directions[n_directions] = {0};
  for (int a = 0; a < mat_size; ++a) {
    for (int b = 0; b < mat_size; ++b) {
      compute_products(numbers, a, b, directions);
      for (int c = 0; c<n_directions; ++c) {
        if (directions[c] > max_product) {
          max_product = directions[c];
          max_idxa    = a;
          max_idxb    = b;
          max_dir     = c;
        }
      }
    }
  }

  printf("Max Product at (%d,%d) in Direction %d = %d\n",
      max_idxa, max_idxb, max_dir, max_product);

  fclose(fp);
  return 0;
}

