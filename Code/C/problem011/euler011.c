#include <stdio.h>
#include <string.h>

const int mat_size = 20;

int chars_to_num( char *buf, int len ) {
  int pow = 1;
  int result = 0;
  for (int i = len-1; i >= 0; --i) {
    result += (buf[i] - '0') * pow;
    pow *= 10;
  }
  return result;
}

int main(int argc, char *argv[]) 
{
  FILE *fp;
  int numbers[mat_size][mat_size];

  if (NULL == (fp = fopen("grid.txt", "r"))) return 1;

  char buffer[100];
  int row = 0;

  int temp[20] = {0};
  char holder[20] = {0};
  int i = 0, j = 0, k = 0;

  while (NULL != fgets(buffer, 100, fp)) {

    while (buffer[i] != '\n') {
      if (buffer[i] != ' ') {
        holder[j] = buffer[i];
        j++;
      } 
      else {
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
      numbers[row][cols] = temp[cols];
    }
    row++;
    i = 0;
    j = 0;
    k = 0;
    memset(holder, 0, 20);
    memset(temp, 0, 20);
  }

  printf("----\n");
  for (int a = 0; a < mat_size; ++a) {
    for (int b = 0; b < mat_size; ++b) {
      printf("%02d ", numbers[a][b]);
    }
    printf("\n");
  }
  printf("----\n");

  fclose(fp);
  return 0;
}

