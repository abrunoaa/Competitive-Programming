#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;

struct u256 {
  u128 hi, lo;
  static u256 mult(u128 x, u128 y) {
    u128 a = x >> 64, b = (u64)x;
    u128 c = y >> 64, d = (u64)y;
    u128 ac = a * c;
    u128 ad = a * d;
    u128 bc = b * c;
    u128 bd = b * d;
    u128 carry = (u128)(u64)ad + (u64)bc + (bd >> 64u);
    u128 h = ac + (ad >> 64u) + (bc >> 64u) + (carry >> 64u);
    u128 l = (ad << 64u) + (bc << 64u) + bd;
    return {h, l};
  }
};

struct Montgomery {
  u128 n, inv, r2;
  explicit Montgomery(u128 _n) : n(_n), inv(1), r2(-n % n) {
    assert(n & 1);
    for (int i = 0; i < 7; ++i) inv *= 2 - n * inv;
    for (int i = 0; i < 4; ++i) if ((r2 <<= 1) >= n) r2 -= n;
    for (int i = 0; i < 5; ++i) r2 = mult(r2, r2);
  }
  u128 init(u128 x) { return mult(x, r2); }
  u128 mult(u128 a, u128 b) { return reduce(u256::mult(a, b)); }
  u128 reduce(u256 x) {
    i128 a = x.hi - u256::mult(x.lo * inv, n).hi;
    return (a < 0) ? a + n : a;
  }
};

istream& operator>>(istream& in, u128 &x) {
  static char s[40];
  in >> s;
  x = 0;
  for (char* p = s; *p; ++p) x = 10 * x + *p - '0';
  return in;
}

ostream& operator<<(ostream& out, u128 x) {
  static char s[40] = {};
  char* p = s + (sizeof(s) - 1);
  while (*--p = (char)(x % 10 + '0'), x /= 10, x);
  return out << p;
}

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());

inline u128 gcd(u128 a, u128 b) {
  if (b != 0) while ((b ^= a ^= b ^= a %= b));
  return a;
}

inline u128 add(u128 a, u128 b, u128 m) { return (a += b) >= m ? a - m : a; }
inline u128 sub(u128 a, u128 b, u128 m) { return a < b ? a + m - b : a - b; }

u128 mult(u128 a, u128 b, u128 m) {
  u128 x = 0;
  while (b) {
    if (b & 1) x = add(x, a, m);
    b >>= 1;
    a = add(a, a, m);
  }
  return x;
}

u128 mpow(u128 a, u128 b, u128 mod) {
  u128 x = 1;
  while (b) {
    if (b & 1) x = mult(x, a, mod);
    b >>= 1;
    a = mult(a, a, mod);
  }
  return x;
}

u128 isqrt(u128 n) {
  u128 x = n, y = 1;
  while (x > y) {
    x = (x + y) >> 1;
    y = n / x;
  }
  return x;
}

bool isPrime(u128 n) {
  if (n < 2) return 0;
  if ((n & 1) == 0) return n == 2;
  u128 d = n - 1;
  int r = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    ++r;
  }
  for (u128 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) if ((a %= n)) {
    a = mpow(a, d, n);
    if (a == 1 || a == n - 1) continue;
    for (int i = 1; i < r && 1 < a && a != n - 1; ++i) a = mult(a, a, n);
    if (a != n - 1) return 0;
  }
  return 1;
}

u128 rho(u128 n) {
  if (isPrime(n)) return 1;
  if ((n & 1) == 0) return 2;
  u128 r = isqrt(n);
  if (r * r == n) return r;
  Montgomery mont(n);
  const int m = n < (1ull << 60) ? 32 : 512;
  const auto one = mont.init(1);
  const auto c = mont.init((rand() & 1023) + 1);
  auto f = [&](u128 x){ return add(mont.mult(x, x), c, n); };
  u128 x = 0, y = one;
  for (int l = 1; ; l <<= 1) {
    if (x == y) y = mont.init(rand());
    x = y;
    for (int i = 0; i < l; ++i) y = f(y);
    u128 ys = y, q = one, g = 1;
    for (int k = 0; k < l && g == 1; k += m) {
      ys = y;
      for (int i = min(m, l - k); i; --i) {
        y = f(y);
        q = mont.mult(q, sub(y, x, n));
      }
      g = gcd(n, q);
    }
    if (g == n) {
      y = ys;
      for (g = 1; g == 1; g = gcd(n, sub(y, x, n))) y = f(y);
    }
    if (g != 1 && g != n) return g;
  }
}

map<u128,int> findFactors(u128 n) {
  assert(n > 1);
  u128 x = rho(n);
  if (x == 1) return {{n, 1}};
  auto a = findFactors(x);
  auto b = findFactors(n / x);
  if (a.size() < b.size()) swap(a, b);
  for (auto [p, k] : b) a[p] += k;
  return a;
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  u128 n;
  while (cin >> n && n) {
    bool flag = 0;
    for (auto [p, k] : findFactors(n)) {
      if (flag) cout << ' ';
      flag = 1;
      cout << p << '^' << k;
    }
    cout << '\n';
  }
  cerr << (double)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
