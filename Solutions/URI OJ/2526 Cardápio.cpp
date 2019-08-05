#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

typedef long long ll;

int n, f[maxn];
ll ft[2][maxn];

ll qry(int p, int i) {
  ll s = 0;
  for (; i; i -= i & -i) { s += ft[p][i]; }
  return s;
}

void upd(int p, int i, ll x) {
  for (; i <= n; i += i & -i) { ft[p][i] += x; }
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n) {
    memset(ft, 0, sizeof ft);

    for (int i = 0; i < n; ++i) { cin >> f[i]; }

    // contar: i < j < k && f[i] > f[j] > f[k]
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      ans += qry(1, f[i]);            // conta qtos sao menores que os menores que f[i]
      upd(0, f[i] + 1, 1);            // +1 menor para todos f[j] > f[i]
      upd(1, f[i] + 1, qry(0, f[i])); // atualiza com qtos sao menores
    }

    cout << ans << '\n';
  }

  return 0;
}
