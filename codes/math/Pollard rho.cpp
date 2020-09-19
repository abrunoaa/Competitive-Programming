typedef __uint128_t u128;

inline u128 gcd(u128 a, u128 b) {
  if (b != 0) while ((b ^= a ^= b ^= a %= b));
  return a;
}

u128 isqrt(u128 n) {
  u128 x = n, y = 1;
  while (x > y) {
    x = (x + y) >> 1;
    y = n / x;
  }
  return x;
}

inline u128 add(u128 a, u128 b, u128 m) { return (a += b) >= m ? a - m : a; }
inline u128 sub(u128 a, u128 b, u128 m) { return a < b ? a + m - b : a - b; }

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
