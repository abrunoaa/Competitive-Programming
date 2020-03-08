#include <bits/stdc++.h>
using namespace std;

int closest(int a, int b) {
  int x = a / b * b;
  int y = x + b;
  return (abs(x - a) < abs(y - a) ? x : y);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = (int)1e9;
    vector v = {-1, -1, -1};
    for (int x = 1; x < 2 * c; ++x) {
      for (int y = x; y < 2 * c; y += x) {
        int z = closest(c, y);
        int tmp = abs(a - x) + abs(b - y) + abs(c - z);
        if (tmp < ans) {
          ans = tmp;
          v = {x, y, z};
        }
      }
    }
    assert(v[1] % v[0] == 0);
    assert(v[2] % v[1] == 0);
    cout << ans << '\n';
    cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
  }
  return 0;
}
