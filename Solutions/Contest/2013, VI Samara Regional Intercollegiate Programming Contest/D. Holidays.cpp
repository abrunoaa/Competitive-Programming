#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = (int)2e5 + 3;
const int mod = (int)1e9 + 9;

int fat[maxn], finv[maxn];

int mpow(ll b, int e, int m) {
  b %= m;
  ll x = 1;
  while (e) {
    if (e % 2) x = x * b % m;
    b = b * b % m;
    e /= 2;
  }
  return (int)x;
}

void build() {
  fat[0]  = finv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fat[i] = (ll)i * fat[i - 1] % mod;
    finv[i] = mpow(fat[i], mod - 2, mod);
  }
}

int nCr(int n, int r) {
  return (ll)fat[n] * finv[r] % mod * finv[n - r] % mod;
}

int main() {
  build();
  int n;
  cin >> n;
  int p = 2;
  int ans = 0;
  for (int k = n - 1; k; --k) {
    ans = (ans + (ll)nCr(n, k) * (p - 1 + mod)) % mod;
    p = 2 * p % mod;
  }
  cout << ans << '\n';
  return 0;
}
