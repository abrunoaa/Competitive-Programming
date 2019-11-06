#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 33;

pair<int,int> ans[maxn];
vector<int> g[maxn];

void dfs(int u, int p, int dir, int x, int y, int len) {
  ans[u] = {x, y};
  int used = 1 << (dir ^ 1);
  for (int v : g[u]) {
    if (v != p) {
      static int X[] = {-1,1,0,0};
      static int Y[] = {0,0,-1,1};
      for (int k = 0; k < 4; ++k) {
        if (!(used & (1 << k))) {
          used |= 1 << k;
          dfs(v, u, k, x + X[k] * (len / 2), y + Y[k] * (len / 2), len / 2);
          break;
        }
      }
    }
  }
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int u = 1; u <= n; ++u) {
    if (g[u].size() > 4) {
      cout << "NO\n";
      return 0;
    }
  }
  dfs(1, 0, 7, 0, 0, (1ll << 50));
  cout << "YES\n";
  for (int u = 1; u <= n; ++u) {
    auto [x, y] = ans[u];
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
