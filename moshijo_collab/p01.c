#include <stdio.h>

int main() {
  int p[4], e[4], f[2], winner[2];
  int i;

  for (i = 0; i < 4; i++) { scanf("%d", p+i), p[i]--; }
  for (i = 0; i < 4; i++) scanf("%d", e+i);
  for (i = 0; i < 2; i++) scanf("%d", f+i);

  if (e[p[0]] < e[p[1]]) winner[0] = p[0];
  else                   winner[0] = p[1];
  if (e[p[2]] < e[p[3]]) winner[1] = p[2];
  else                   winner[1] = p[3];
  //for (i = 0; i < 4; i++) { printf(" %d", p[i]); } printf("\n");
  //for (i = 0; i < 4; i++) { printf(" %d", e[i]); } printf("\n");
  //for (i = 0; i < 2; i++) { printf(" %d", f[i]); } printf("\n");
  //for (i = 0; i < 2; i++) { printf(" %d", winner[i]); } printf("\n");
  if (winner[1] < winner[0]) {
    i         = winner[1];
    winner[1] = winner[0];
    winner[0] = i;
  }
  if (f[0] < f[1]) printf("%d\n%d\n", winner[0]+1, winner[1]+1);
  else             printf("%d\n%d\n", winner[1]+1, winner[0]+1);

  return 0;
}
