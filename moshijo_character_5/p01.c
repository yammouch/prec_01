#include <stdio.h>
#include <string.h>

int main()
{
  int encrypt_table[10], decrypt_table[10];
  char direction[10];
  char text[20];
  int i, len;

  for (i = 0; i < 10; i++) {
    scanf("%d", encrypt_table + i);
  }
  scanf("%s", direction);
  scanf("%s", text);

  len = strlen(text);
  if (direction[0] == 'e') {
    for (i = 0; i < len; i++) {
      printf("%d", encrypt_table[text[i] - '0']);
    }
  } else {
    for (i = 0; i < 10; i++) {
      decrypt_table[encrypt_table[i]] = i;
    }
    for (i = 0; i < len; i++) {
      printf("%d", decrypt_table[text[i] - '0']);
    }
  }
  printf("\n");

  return 0;
}
