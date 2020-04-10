#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;

int f(int i, int s) {
  return (i + s + n) % n == 0 ? n : (i + s + n) % n;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> x >> y;
  for (int j = y; j >= 1; --j) {
    cout << x << ' ' << j << '\n';
  }
  for (int j = 1; j <= m; ++j) {
    int s = (j % 2 ? 1 : -1);
    for (int i = f(x, s); i != x; i = f(i, s)) {
      cout << i << ' ' << j << '\n';
    }
  }
  for (int j = m; j >= y; --j) {
    cout << x << ' ' << j << '\n';
  }
  return 0;
}
