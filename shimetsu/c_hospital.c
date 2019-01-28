#include <stdio.h>
#include <string.h>

int main() {
  char t[128];
  int len, i, c_alpha, c_num;
  scanf("%s", t);
  len = strlen(t);
  if (len < 6) {
    printf("invalid\n");
    return 0;
  }
  for (i = 0; i < len-2; i++) {
    if (t[i] == t[i+1] && t[i] == t[i+2]) {
      printf("invalid\n");
      return 0;
    }
  }
  for (c_alpha = 0, c_num = 0, i = 0; i < len; i++) {
    if      ('A' <= t[i] && t[i] <= 'Z') c_alpha = 1;
    else if ('a' <= t[i] && t[i] <= 'z') c_alpha = 1;
    else if ('0' <= t[i] && t[i] <= '9') c_num = 1;
  }
  if (c_alpha && c_num) printf("valid\n");
  else                  printf("invalid\n");
  return 0;
}
