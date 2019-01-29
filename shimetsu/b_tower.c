#include <stdio.h>
#include <string.h>

char strs[128][128];
int n;

void data_read() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", strs[i]);
  }
  return;
}

void search_common(int i) {
  int j, k, jmax, l;
  jmax = strlen(strs[i]);
  k = 0;
  for (j = 0; j < jmax; j++) {
    if (strs[i][j] == strs[i+1][k]) {
      k++;
    } else {
      k = 0; l = j+1;
    }
  }
  strs[i][l] = '\0';
  return;
}

void main_loop() {
  int i;
  for (i = 0; i < n-1; i++) {
    search_common(i);
  }
  return;
}

void print_out() {
  int i;
  for (i = 0; i < n; i++) {
    printf("%s", strs[i]);
  }
  printf("\n");
  return;
}

int main() {
  data_read();
  main_loop();
  print_out();

  return 0;
}
