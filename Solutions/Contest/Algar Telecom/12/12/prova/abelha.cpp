#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("in", "r", stdin);

  register uint p;
  uint n, a[1000] = {0, 1};

  while (scanf("%d", &n), ++n) {
    p = n;
    if (!a[p]) {
      while (!a[--p]);
      while (++p <= n) {
        a[p] = a[p - 1] + a[p - 2] + 1;
      }
    }
    printf("%u %u\n", a[n - 1], a[n]);
  }
  return 0;
}
