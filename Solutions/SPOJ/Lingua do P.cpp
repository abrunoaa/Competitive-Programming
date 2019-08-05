#include <cstdio>

int main() {
  register int i, j;
  char p[2000], p2[2000];
  scanf("%[^\n]s", p);
  for (i = 1, j = 0; p[i] != 0 && p[i - 1] != 0; i += 2, j++) {
    if (p[i - 1] == ' ') {
      i--;
    }
    p2[j] = p[i];
  }

  for (i = 0; p2[i] != 0; i++) {
    printf("%c", p2[i]);
  }
}
