#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define maxn 5010

typedef long long ll;

int a, b, c, fat[maxn], finv[maxn];

int mpow(int b, int e, int m) {
  int x = 1;
  while (e) {
    if (e % 2) { x = (ll)x * b % m; }
    b = (ll)b * b % m;
    e /= 2;
  }
  return x;
}

void build() {
  fat[0] = finv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fat[i] = (ll)i * fat[i - 1] % mod;
    finv[i] = (ll)mpow(i, mod - 2, mod) * finv[i - 1] % mod;
  }
}

int C(int n, int k) {
  return (ll)fat[n] * finv[k] % mod * finv[n - k] % mod;
}

int f(int x, int y) {
  int ans = 0;
  int up = min(x, y);
  for (int k = 0; k <= up; ++k) {
    ans = (ans + (ll)C(x, k) * C(y, k) % mod * fat[k]) % mod;
  }
  // cerr << " >> " << x<< ' '<<y << ' ' << ans << endl;
  return ans;
}

int main() {
  build();
  while (cin >> a >> b >> c) {
    cout << (ll)f(a, b) * f(a, c) % mod* f(b, c) % mod << '\n';
  }

  return 0;
}
