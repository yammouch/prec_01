#include <stdio.h>

int main (){
  long n;

  while (scanf("%ld", &n) != EOF) {
    if (n % 2 == 0) {
      printf("0\n");
    } else {
      printf("%ld\n", (1999999/n + 1)/2);
    }
  }
}
