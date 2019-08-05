#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, r, i, v;
  bool ret[10005], flag;

  while (scanf("%d%d", &n, &r) == 2) {
    memset(ret + 1, 0, n);

    for (i = 0; i < r; ++i) {
      scanf("%d", &v);
      ret[v] = 1;
    }

    flag = 0;
    for (i = 1; i <= n; ++i)
      if (!ret[i]) {
        printf("%d ", i);
        flag = 1;
      }
    puts(flag ? "" : "*");
  }

  return 0;
}
