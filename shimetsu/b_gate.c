#include <stdio.h>

int main() {
  int h, w, n, i, x, y;
  char d[10];

  scanf("%d%d%d", &h, &w, &n);
  for (x = 0, y = 0, i = 0; i < n; i++) {
    scanf("%s", d);
    switch(d[0]) {
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      case 'L':
        x--;
        break;
      case 'R':
        x++;
    }
    if (x < 0 || w <= x || y < 0 || h <= y) {
      printf("Invalid\n");
      return 0;
    }
  }
  printf("Valid\n");

  return 0;
}
