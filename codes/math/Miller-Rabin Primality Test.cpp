bool millerRabin(ll n) {
  if (n < 2) { return 0; }
  if (n % 2 == 0) return (n == 2);
  static const int bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  ll d = n - 1;
  int r = __builtin_ctzll(d);
  d >>= r;
  for (int a : bases) if ((a %= n)) {
    a = mpow(a, d, n);                  // a ** d % n
    if (a == 1 || a == n - 1) continue;
    for (int i = 1; i < r && 1 < a && a < n - 1; ++i) a = mpow(a, 2, n);// a * a % n
    if (a != n - 1) return 0;
  }
  return 1;
}
