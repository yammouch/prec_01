#include <stdio.h>

int main() {
  char s[127];
  int i, n, e;
  scanf("%d", &n);
  //printf("%d\n", n);
  for(i = 0; i < n; i++) {
    scanf("%s%d", s, &e);
    //printf("%s %d\n", s, e);
    if (e == 3) {
      printf("%s\n", s);
    }
  }
  return 0;
}
