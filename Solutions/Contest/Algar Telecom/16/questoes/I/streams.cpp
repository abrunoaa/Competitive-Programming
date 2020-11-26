#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("streams.in", "r", stdin);
  freopen("out", "w", stdout);

  register int i, j, v, cont;
  char str[1000000], bit[10];

  while (scanf(" %[^\n]", str) > 0) {
    for (i = 8; i; bit[--i] = 0);
    i = -1;
    do {
      v = 0;
      for (++i; str[i] && str[i] != ','; ++i) {
        v = (v << 1) + (v << 3) + str[i] - 48;
      }
      v = (v + (v << 1) + 1) % 7;
      for (j = 1, cont = 0; j < 200 && !(j & v); j <<= 1, ++cont);
      if (j < 200) {
        bit[cont] = 1;
      }

    } while (str[i]);

    for (i = 8; i--; printf("%d", bit[i]));
    printf("\n");
  }
  return 0;
}
