#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define st first
#define nd second

typedef long long ll;

// x * y % m (evitando overflow)
ll mul(ll x, ll y, ll m) {
  // return (__int128)x * y % m;        // gnu c++ em máquina 64bit

  ll k = 0;
  while (y) {
    if (y % 2) { k = (k + x) % m; }
    y /= 2;
    x = 2 * x % m;
  }
  return k;
}

// retorna b ** e % m
ll mpow(ll b, ll e, ll m) {
  ll x = 1;
  while (e) {
    if (e % 2) { x = mul(x, b, m); }
    b = mul(b, b, m);
    e /= 2;
  }
  return x;
}

// checa se n é primo
// O(k * log²(n)) ou se usar modMul O(k * log³(n)), k = qtd de primos testados
bool millerRabin(ll n) {
  // n <  4e9: bases[] = {2, 7, 61}
  // n < 3e23: bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
  const char bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};  // se n < 3e18

  for (int p : bases)                   // para não falhar para as bases tentadas
    if (n % p == 0) {
      return n == p;
    }

  ll d = n - 1;
  int r = __builtin_ctzll(d);
  d >>= r;

  for (int b : bases) {
    ll x = mpow(b, d, n);               // b ** d % n
    if (x == 1 || x == n - 1) {
      continue;
    }
    for (int i = 1; i < r && x > 1 && x < n - 1; ++i) {
      x = mpow(x, 2, n);  // x * x % n -- pode precisar de modMul
    }
    if (x != n - 1) {
      return 0;
    }
  }
  return 1;
}

// retorna um fator não trivial (1 e n) de n, 0 se não existir
ll floyd_pollard_rho(ll n) {
  if (n <= 3 || millerRabin(n)) { return 0; }
  if (n % 2 == 0) { return 2; }

  ll rt = sqrt(n) + 1e-9;
  if (rt * rt == n) { return rt; }

  while (1) {
    ll x = rand(), y = x, d = 1;
    while (d == 1) {
      x = (mul(x, x, n) + 1) % n;
      y = (mul(y, y, n) + 1) % n;
      y = (mul(y, y, n) + 1) % n;
      d = gcd(n, abs(x - y));
    }
    if (d != n) {
      return d;
    }
  }
}

ll brent_pollard_rho1(ll n) {
  if (n <= 3 || millerRabin(n)) { return 0; }
  if (n % 2 == 0) { return 2; }

  ll rt = sqrt(n) + 1e-9;
  if (rt * rt == n) { return rt; }

  while (1) {
    ll x = rand(), y = x, d = 1;
    for (int i = 1; d == 1; ++i) {
      x = (mul(x, x, n) + 1) % n;
      d = gcd(n, abs(x - y));
      if ((i & (i - 1)) == 0) {                // se i é uma potência de 2 (i = 2^k)
        y = x;
      }
    }
    if (d != n && d != 1) {
      return d;
    }
  }
}

ll brent_pollard_rho2(ll n) {
  if (n <= 3 || millerRabin(n)) { return 0; }
  if (n % 2 == 0) { return 2; }

  ll rt = sqrt(n) + 1e-9;
  if (rt * rt == n) { return rt; }

  int m;
  ll x, y, ys, q, g;
  do {
    m = rand() % 963 + 1;
    y = rand() % (n - 1) + 1;
    q = g = 1;
    for (int r = 1; g == 1; r *= 2) {
      x = y;
      for (int i = 0; i < r; ++i) {
        y = (mul(y, y, n) + 1) % n;
      }
      for (int k = 0; k < r && g == 1; k += m) {
        ys = y;
        for (int i = min(m, r - k); i; --i) {
          y = (mul(y, y, n) + 1) % n;
          q = mul(q, abs(x - y), n);
        }
        g = gcd(q, n);
      }
    }
    if (g == n) do {
        ys = (mul(ys, ys, n) + 1) % n;
        g = gcd(n, abs(x - ys));
      } while (g == 1);
  } while (g == n);
  return g;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  srand(time(0));

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    map<ll, int> ans;

    queue<ll> q;
    q.push(n);
    while (!q.empty()) {
      ll n = q.front();
      q.pop();

      // ll d = floyd_pollard_rho(n);
      // ll d = brent_pollard_rho1(n);
      ll d = brent_pollard_rho2(n);
      if (!d) {
        ++ans[n];
      } else {
        q.push(d);
        q.push(n / d);
      }
    }

    cout << n << " =";

    bool flag = 0;
    for (auto p : ans) {
      if (flag) {
        cout << " *";
      }
      flag = 1;
      if (p.nd == 1) {
        cout << ' ' << p.st;
      } else {
        cout << ' ' << p.st << '^' << p.nd;
      }
    }
    cout << '\n';
  }

  return 0;
}
