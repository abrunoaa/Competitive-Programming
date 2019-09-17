#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int n, f, c[maxn];

bool start(double t) {
  const double total = t * f;
  double over = 0.0;
  for (int i = 0; i < n; ++i) {
    over = max(0.0, over + total - c[i]);
  }
  return over > 0.0;
}

bool full(double t) {
  const double total = t * f;
  double over = 0.0;
  for (int i = 0; i < n; ++i) {
    if (over + total < c[i]) {
      return 0;
    }
    over = max(0.0, over + total - c[i]);
  }
  return 1;
}

double find(auto func) {
  double l = 0.0, r = 1e9;
  for (int i = 0; i < 100; ++i) {
    double m = (l + r) / 2;
    if (func(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(9);
  while (cin >> n >> f) {
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    cout << find(start) << ' ' << find(full) << '\n';
  }
  return 0;
}
