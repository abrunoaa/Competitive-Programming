#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nbits(ll n, int i) {
  ll x = ((n >> i) << i) & ~(1ll << i);
  return x / 2 + max(0ll, n - x + 1 - (1ll << i));
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  ll ans = 0;
  while (n--) {
    ll x, m;
    cin >> x >> m;

    for (int i = 0; i < 60; ++i) {
      ans ^= ll((nbits(x + m - 1, i) - nbits(x - 1, i)) % 2) << i;
    }
  }
  cout << (ans != 0 ? "tolik" : "bolik") << '\n';

  return 0;
}
