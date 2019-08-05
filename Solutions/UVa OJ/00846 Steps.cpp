#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);

  register int n, st, dif, q;
  int N, x, y;

  scanf("%d", &N);
  n = N + 1;
  while (--n) {
    scanf("%d%d", &x, &y);
    dif = y - x;

    if (dif <= 3) {
      q = dif;
    } else {
      q = 0;
      for (st = 2; dif >= st; st += 2) {
        dif -= st;
        q += 2;
      }
      if (dif >= (st >>= 1)) {
        dif -= st;
        ++q;
      }
      if (dif) {
        ++q;
      }
    }

    printf("%d\n", q);
  }

  return 0;
}





