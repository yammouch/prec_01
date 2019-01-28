#include <stdio.h>

int main() {
  int i, n, w_a, w_b;
  char a[10], b[10];
  scanf("%d", &n);
  for (w_a = 0, w_b = 0, i = 0; i < n; i++) {
    scanf("%s%s", a, b);
    if (a[0] == 'g' && b[0] == 'c'
     || a[0] == 'c' && b[0] == 'p'
     || a[0] == 'p' && b[0] == 'g' ) {
      w_a++;
    } else if (
        a[0] == 'g' && b[0] == 'p'
     || a[0] == 'c' && b[0] == 'g'
     || a[0] == 'p' && b[0] == 'c' ) {
      w_b++;
    }
  }
  printf("%d\n%d\n", w_a, w_b);
  return 0;
}
