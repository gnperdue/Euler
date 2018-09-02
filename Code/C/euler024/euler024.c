#include <stdio.h>
#include <string.h>

void swap(char *s, int a, int b) {
  char temp = s[a];
  s[a] = s[b];
  s[b] = temp;
}

int permute(char *str, int len) {
  /* SEPA algorithm, from Project Euler forums by WR */
  int key = len - 1;
  while ((key > 0) && (str[key] <= str[key - 1])) key--;
  key--;
  if (key < 0) return 0;
  int newkey = len - 1;
  while ((newkey > key) && (str[newkey] <= str[key])) newkey--;
  swap(str, key, newkey);
  len--;
  key++;
  while (len > key) {
    swap(str, len, key);
    key++;
    len--;
  }
  return 1;
}

int main(int argc, const char *argv[]) {
  long count = 0;
  char st[] = {"0123456789"};
  int len = strlen(st);
  do {
    count++;
    if (count == 1000000) break;
  } while (permute(st, len));
  printf("Answer is %s\n", st);
	return 0;
}
