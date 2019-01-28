#include <stdio.h>

int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  if (n < w) {
    printf("error\n");
  } else {
    printf("%d\n", n-w);
  }
  return 0;
}
