#include <stdio.h>
#include <string.h>

char str[16384];
int n;

void data_read() {
  scanf("%d", &n);
  return;
}

int search_common(int len) {
  int j, k, kmax, l;
  char str_tmp[128];
  scanf("%s", str_tmp);
  kmax = strlen(str_tmp);
  k = 0;
  j = len - kmax;
  if (j < 0) {
    j = 0;
  }
  for (; j < len; j++) {
    if (str[j] == str_tmp[k]) {
      k++;
    } else {
      k = 0; l = j+1;
    }
  }
  strcpy(str + l, str_tmp);
  return l + kmax;
}

void main_loop() {
  int i, len;
  len = 0;
  for (i = 0; i < n; i++) {
    len = search_common(len);
  }
  return;
}

void print_out() {
  printf("%s\n", str);
  return;
}

int main() {
  data_read();
  main_loop();
  print_out();

  return 0;
}
