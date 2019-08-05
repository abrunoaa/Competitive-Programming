#include <bits/stdc++.h>
using namespace std;

#define reg register
#define MAXP 31700      // sqrt(1e9) ≃ 31622.776601684

typedef long long ll;

bitset<MAXP> epr;
vector<int> pr;

void init (reg ll n = MAXP) {
  epr.set();
  epr[0] = epr[1] = 0;
  pr.reserve((int)(n / log(n)) << 1);

  reg ll i, j;
  for (i = 2; i < n; ++i)
    if (epr[i]) {
      pr.push_back(i);
      for (j = i * i; j < n; j += i) {
        epr[j] = 0;
      }
    }
}

int totient (int k) {
  int i = 0, pf, n = k;
  while (pf = pr[i++], pf * pf <= k) {
    if (k % pf == 0) { n -= n / pf; }
    while (k % pf == 0) { k /= pf; }
  }

  if (k > 1) { return n - n / k; }
  return n;
}

int main() {
  init();

  int n;
  while (scanf("%d", &n) == 1 && n) { printf("%d\n", totient(n)); }

  return 0;
}
