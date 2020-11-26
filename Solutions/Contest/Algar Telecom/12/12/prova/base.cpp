#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);
  freopen("base.in", "r", stdin);
  freopen("out", "w", stdout);

  register unsigned long m;
  register int i, caso = 0;
  int n, len, lena;
  char msg[50], bc[120], ba[120], mbc[260], dis[500];

  scanf("%d", &n);
  while (n--) {
    scanf(" %[^ ] %[^ ] %[^ \n]", msg, bc, ba);

    for (i = 0; bc[i]; ++i) {
      mbc[(int)bc[i]] = i;
    }
    len = i;

    m = 0;
    for (i = 0; msg[i]; ++i) {
      m *= len;
      m += mbc[(int)msg[i]];
    }

    for (i = 0; ba[i]; ++i);
    lena = i;

    for (i = 0; m; ++i) {
      dis[i] = m % lena;
      m /= lena;
    }

    printf("Caso #%d: ", ++caso);
    while (i--) {
      printf("%c", ba[(int)dis[i]]);
    }
    printf("\n");
  }

  return 0;
}
