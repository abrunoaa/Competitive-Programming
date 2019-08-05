#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, v, ma, me;

  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &v);
    ma = me = v;

    while (--n) {
      scanf("%d", &v);
      if (v < me) {
        me = v;
      } else if (v > ma) {
        ma = v;
      }
    }

    printf("%d\n", (ma - me) << 1);
  }

  return 0;
}





