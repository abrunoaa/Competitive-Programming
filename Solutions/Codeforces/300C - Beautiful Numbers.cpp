#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010
#define mod 1000000007

typedef long long ll;

int n, a, b;
int fat[maxn];

void build() {
  fat[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fat[i] = (ll)i * fat[i - 1] % mod;
  }
}

bool good(ll x) {
  while (x && (x % 10 == a || x % 10 == b)) {
    x /= 10;
  }
  return x == 0;
}

int mul(int x, int y, int m) { return ll(x) * y % m; }

ll mpow(int b, int e, int m) {
  int x = 1;
  while (e) {
    if (e % 2) { x = mul(x, b, m); }
    b = mul(b, b, m);
    e /= 2;
  }
  return x;
}

ll C(int n, int k) {
  return fat[n] * mpow((ll)fat[n - k] * fat[k] % mod, mod - 2, mod) % mod;
}

int main() {
  build();
  cin >> a >> b >> n;
  // a = 2, b = 3, n = 10;

  int ans = 0;
  for (int k = 0; k <= n; ++k)
    if (good(k * a + (n - k) * b)) {
      ans = (ans + C(n, k)) % mod;
    }
  cout << ans << '\n';

  return 0;
}
