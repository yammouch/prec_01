#include <stdio.h>
#include <string.h>

int main() {
  char str[128];
  int i, len;

  scanf("%s", str);
  len = strlen(str);

  for (i = 0; i < len; i += 2) {
    printf("%c", str[i]);
  }
  printf("\n");

  return 0;
}
