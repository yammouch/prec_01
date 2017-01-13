#include <stdio.h>

int main()
{
  int n = 0;
  unsigned char str[20];
  int i, j;
  unsigned int sum, dig;

  fgets(str, 20, stdin);
  sscanf(str, "%d", &n);
  //printf("%d\n", n);
  for (i = 0; i < n; i++) {
    fgets(str, 20, stdin);
    //printf("%s\n", str);
    sum = 0;
    j = 0; while (1) {
      dig = (unsigned int)str[2*j] - '0';
      //printf("%d\n", dig);
      dig *= 2;
      if (10 <= dig) dig = dig % 10 + 1;
      sum += dig;
      //printf("%d\n", dig);
      if (7 <= j) break;
      dig = (unsigned int)str[2*j+1] - '0';
      //printf("%d\n", dig);
      sum += dig;
      j++;
    }
    printf("%d\n", (10 - (sum%10))%10);
  }
}
