#include <stdio.h>

int main() {
  int n, a, b;
  char str[128];
  scanf("%d%d%d", &n, &a, &b);
  sprintf(str, "%%0%dd\n", n);
  for (; a <= b; a++) {
    printf(str, a);
  }
  return 0;
}
