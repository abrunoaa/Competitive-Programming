typedef long long ll;

#define gcd __gcd   // gnu c++
int gcd(int a, int b) { return (!b ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

// extended Euclid
int extGcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int g = extGcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}

// resolve ax + by = c, todos inteiros
// para a n-ésima solução: xn = x0 + b / d * n, yn = y0 - a / d * n
bool diophantine(int a, int b, int c, int &x, int &y) {
  int d = extGcd(a, b, x, y);
  if (c % d) { return 0; }        // não tem solução inteira
  x *= c / d;
  y *= c / d;
  return 1;
}

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
int mpow(int b, int e, int m) {
  int x = 1;
  while (e) {
    if (e % 2) { x = (ll)x * b % m; }       // *** se estourar usar mul! ***
    b = (ll)b * b % m;
    e /= 2;
  }
  return x;
}

// retorna x^-1 % m ==> gcd(x, m) == 1
int modInv(int x, int m) { return mpow(x, m - 2, m); }
