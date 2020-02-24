#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans = x * b;
    ans = max(ans, (a - x - 1) * b);
    ans = max(ans, y * a);
    ans = max(ans, (b - y - 1) * a);
    cout << ans << '\n';
  }
  return 0;
}
