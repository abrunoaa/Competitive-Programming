#include <bits/stdc++.h>
using namespace std;

int main() {
  int q, t1, t2, t;
  while (scanf(" %d", &q), q--) {
    t = 10;
    scanf(" %d", &t1);
    while (q--) {
      scanf(" %d", &t2);
      if (t2 - t1 > 10) {
        t += 10;
      } else {
        t += t2 - t1;
      }
      t1 = t2;
    }
    printf("%d\n", t);
  }
  return 0;
}
