#include <bits/stdc++.h>
using namespace std;

int main() {
  register int i, n, r, q, f;
  int N, a[100005];

  scanf("%d", &N);
  n = N;

  scanf("%d", a);
  q = 1;
  f = 0;

  for (i = 1; i < n; ++i) {
    scanf("%d", a + i);
    if (f && a[i] != a[i - 1] + r) {
      f = 0, ++q;
    } else {
      f = 1, r = a[i] - a[i - 1];
    }
  }

  printf("%d\n", q);

  return 0;
}





