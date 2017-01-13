#include <stdio.h>
int main(void){
  char op[200];
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%s", op);
  printf("%c", op[0]);
  if (op[0] == '+') {
    printf("%d\n", a+b);
  } else {
    printf("%d\n", a-b);
  }
  return 0;
}
