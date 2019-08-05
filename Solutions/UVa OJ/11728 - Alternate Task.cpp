#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 1000 // nos testes, a maior resposta é 997

vector<int> sumDiv(maxn, 1), ans(1010, -1);

void sieve() {
  int n = maxn;
  for (ll i = 2; i < n; ++i) {
    if (sumDiv[i] == 1) {
      sumDiv[i] += i;
      for (ll j = 2 * i; j < n; j += i) {
        int e = 0;
        for (ll k = j; k % i == 0; k /= i) {
          ++e;
        }
        sumDiv[j] *= (int(pow(i, e + 1) + 1e-12) - 1) / (i - 1);
      }
    }
  }
}

void solve() {
  for (int i = 0; i < maxn; ++i) {
    if (sumDiv[i] <= 1000) {
      ans[ sumDiv[i] ] = i;
    }
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  sieve();
  solve();

  int n, cs = 0;
  while (cin >> n && n) {
    cout << "Case " << ++cs << ": " << ans[n] << '\n';
  }

  return 0;
}
