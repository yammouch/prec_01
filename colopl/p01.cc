#include <stdio.h>

int main() {
  static long x[120], c[120];
  long i, j, n, max;

  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", x+i);
  }

  //printf("%d\n", n);
  //for (i = 0; i < n; i++) {
  //  printf(" %d", x[i]);
  //}
  //printf("\n");

  for (i = 0; i < n; i++) {
    //printf("%ld\n", i);
    max = 0;
    for (j = 1; j <= 3; j++) {
      //printf(" %ld %ld", j, c[i]);
      if (0 <= i-j && x[i-j] < x[i] && max <= c[i-j] + 1) {
        //printf(" %ld %ld\n", i, j);
        max = c[i-j] + 1;
      }
    }
    c[i] = max;
    //printf("\n%ld\n", c[i]);
  }

  max = 0;
  for (i = 0; i < n; i++) {
    if (max < c[i]) {
      max = c[i];
    }
  }

  printf("%ld\n", max + 1);

  return 0;
}
