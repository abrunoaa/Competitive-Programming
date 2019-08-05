#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

typedef long long ll;

bitset<maxn> isp;

void sieve() {
  isp.set();
  isp[0] = isp[1] = 0;
  int n = maxn;
  for (ll i = 2; i < n; ++i) {
    if (isp[i]) {
      for (ll j = i * i; j < n; j += i) {
        isp[j] = 0;
      }
    }
  }
}

bool tprime(ll n) {
  ll x = sqrt(n) + .5;
  return x * x == n && isp[x];
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  sieve();

  int t;
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    cout << (tprime(x) ? "YES" : "NO") << '\n';
  }

  return 0;
}
