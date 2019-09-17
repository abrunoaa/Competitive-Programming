vector<int> pf(int n) {
  vector<int> factors;
  for (int p : primes) {
    if ((ll)p * p > n) break;
    if (n % p == 0) {
      factors.pb(p);
      while (n % p == 0) n /= p;
    }
  }
  if (n > 1) factors.pb(n);
  return factors;
}

bool primitive(int p, int r) {
  for (int f : pf(p - 1))
    if (mpow(r, (p - 1) / f, p) == 1)
      return 0;
  return 1;
}
