#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

bool vis[maxn];
vector<int> g[maxn];

int dfs(int u) {
  vis[u] = 1;
  int s = 1;
  for (int v : g[u]) {
    if (!vis[v]) {
      s += dfs(v);
    }
  }
  return s;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n % 2 != 0) {
    cout << "Junior\n";
    return 0;
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int u = 1; u <= n; ++u) {
    if (!vis[u] && dfs(u) % 2 != 0) {
      cout << "Junior\n";
      return 0;
    }
  }
  cout << "Thiago\n";
  return 0;
}
