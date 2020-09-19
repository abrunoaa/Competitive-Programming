int isqrt(int n) {
  if (n < 2) { return n; }
  int r = 1 + 2 * isqrt(n / 4);
  if (r * r <= n) { return r; }
  return r - 1;
}

int isqrt(int n) {
  int x = n, y = 1;
  while (x > y) {
    x = (x + y) / 2;
    y = n / x;
  }
  return x;
}
