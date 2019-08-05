#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int n, ans = 0;
  map<int, int> f, g;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    ans += f[x + y] + g[x - y];
    ++f[x + y];
    ++g[x - y];
  }
  cout << ans << '\n';

  return 0;
}
