// $ gcc [this_file.c]
// $ echo 'abc   def ghi' | ./a.out

#include <stdio.h>

int main () {
  char a[8], b[8], c[8];

  scanf("%s%s%s", a, b, c);
  printf("%s %s %s", a, b, c);

  return 0;
}
