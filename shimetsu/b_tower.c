#include <stdio.h>
#include <string.h>

char str[16384];
int n;

void data_read() {
  scanf("%d", &n);
  return;
}

int search_common(int len) {
  int j, k, kmax;
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
      k = 0;
    }
  }
  strcpy(str + len, str_tmp+k);
  return len + kmax - k;
}

void main_loop() {
  int i, len;
  len = 0;
  for (i = 0; i < n; i++) {
    len = search_common(len);
  }
  //for (i = 0; i < len+1; i++) {
  //  printf("%02X ", (int)(str[i]));
  //}
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
