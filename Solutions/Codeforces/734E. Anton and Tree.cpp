#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

int n, ans;
bool color[maxn];
vector<int> g[maxn];

int dfs(int u, int p) {
  int r1 = 0, r2 = 0;
  for (int v : g[u]) {
    if (v != p) {
      int d = dfs(v, u) + (color[u] ^ color[v]);
      if (d > r1) {
        r2 = r1;
        r1 = d;
      } else if (d > r2) {
        r2 = d;
      }
    }
  }
  ans = max(ans, r1 + r2);
  return r1;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int u = 1; u <= n; ++u) {
    cin >> color[u];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << (ans + 1) / 2 << '\n';
  return 0;
}
