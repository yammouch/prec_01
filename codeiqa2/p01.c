#include <stdio.h>

int main (){
  long i, n, c;

  while (scanf("%ld", &n) != EOF) {
    c = 0;
    for (i = 1; i < 1000000; i++) {
      if ((i + i + 1) % n == 0) c++;
    }
    printf("%ld\n", c);
  }
}
