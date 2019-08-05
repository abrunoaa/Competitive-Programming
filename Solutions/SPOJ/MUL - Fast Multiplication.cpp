#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define zero(x) (abs(x) < 1)
#define maxn ((1 << 15) + 10)
#define digits 5
#define base (int)(pow(10, digits) + 1e-9)

typedef long long ll;
typedef long double lf;

struct cp {
  lf a, b;

  cp(lf a = 0.0, lf b = 0.0) : a(a), b(b) {}

  cp operator + (cp &x) { return {a + x.a, b + x.b}; }
  cp operator - (cp &x) { return {a - x.a, b - x.b}; }
  cp operator * (cp &x) { return {a* x.a - b * x.b, a* x.b + b * x.a}; }
  cp operator / (lf d) { return {a / d, b / d}; }
};

void fft(cp* a, int n, int s) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) { swap(a[i], a[j]); }
    for (int k = n / 2; (j ^= k) < k; k >>= 1);
  }

  for (int i = 1; (1 << i) <= n; ++i) {
    int p = 1 << i;
    int q = p >> 1;

    cp wn = cp(cos(2 * s * pi / p), sin(2 * s * pi / p));
    for (int j = 0; j < n; j += p) {
      cp w = cp(1, 0);
      for (int k = j; k < q + j; ++k) {
        cp t = w * a[k + q];
        a[k + q] = a[k] - t;
        a[k] = a[k] + t;
        w = wn * w;
      }
    }
  }
}

void multiply(cp* a, cp* b, int n) {
  assert((n & (n - 1)) == 0);
  fft(a, n, 1);
  fft(b, n, 1);
  for (int i = 0; i < n; i++) { a[i] = a[i] * b[i]; }
  fft(a, n, -1);
  for (int i = 0; i < n; i++) { a[i] = a[i] / n; }
}

int ans[maxn];
char xs[maxn], ys[maxn];
cp x[maxn], y[maxn];

int toComplex(cp* x, const char* s, int n) {
  int k = 0;
  for (int i = n - 1; i >= 0; i -= digits) {
    int v = 0;
    for (int j = max(0, i - digits + 1); j <= i; ++j) {
      v = v * 10 + s[j] - '0';
    }
    x[k] = { (lf)v, 0 };
    ++k;
  }
  return k;
}

void fix(cp* x, int n, int m) {
  for (int i = n; i < m; ++i) {
    x[i] = {0, 0};
  }
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> xs >> ys;

    int nx = toComplex(x, xs, strlen(xs));
    int ny = toComplex(y, ys, strlen(ys));
    int power = nx + ny;
    while (power & (power - 1)) {
      power += power & -power;
    }

    fix(x, nx, power);
    fix(y, ny, power);

    multiply(x, y, power);
    ll carry = 0;
    for (int i = 0; i < power; ++i) {
      ll t = round(x[i].a);
      carry += t;
      ans[i] = carry % base;
      carry /= base;
    }

    bool flag = 0;
    for (int i = power - 1; i >= 0; --i) {
      if (flag) {
        printf("%0*d", digits, ans[i]);
      } else if (ans[i]) {
        printf("%d", ans[i]);
        flag = 1;
      }
    }
    if (!flag) {
      printf("0");
    }
    printf("\n");
  }

  return 0;
}
