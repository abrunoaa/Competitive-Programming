#include <bits/stdc++.h>
using namespace std;

int main() {
  register int i, j, k, l, v;
  int n, t;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    l = n;
    for (i = 1; i <= l; i += 2) {
      for (j = 1, k = 0; j; j <<= 1, ++k) {
        if ((v = i * j) > l) {
          j = 0;
          break;
        }
        if (n == v) {
          break;
        }
      }
      if (j) {
        break;
      }
    }
    printf("%d %d\n", i, k);
  }
  return 0;
}
