#include <bits/stdc++.h>
using namespace std;

#define MAX 10100

bitset<MAX> epr;
vector<int> pr;

void sieve (int n = MAX) {
  epr.set();
  epr[0] = epr[1] = 0;

  pr.reserve((int)(n / log(n)) << 1);
  for (int i = 2; i < n; ++i)
    if (epr[i]) {
      pr.push_back(i);
      for (int j = i * i; j < n; j += i) { epr[j] = 0; }
    }
}

int main() {
  sieve();

  int tc, n, i, x, p, lim, tmp, maior, ans;

  scanf("%d", &tc);
  while (tc--) {
    maior = -1;

    scanf("%d", &n);
    for (i = 0, x = pr[0]; x <= n; x = pr[++i])
      for (p = (int)ceil(n / x - 1), lim = n / x; p <= lim; ++p) {
        tmp = n - p * x;
        if (tmp > maior) {
          maior = tmp;
          ans = x;
        }
      }

    printf("%d\n", ans);
  }

  return 0;
}
