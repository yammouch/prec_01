#include <stdio.h>

int main() {
  int a, d;
  scanf("%d", &a);

  for (d = 10; d < 100000000; d *= 10) {
    if (d / 2 <= a % d) {
      a = (a / d)*d + d;
    }
  }

  printf("%d\n", a);

  return 0;
}
