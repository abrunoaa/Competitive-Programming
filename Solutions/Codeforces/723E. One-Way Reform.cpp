#include <bits/stdc++.h>
using namespace std;

const int maxn = 203;

set<int> g[maxn];

vector<int> eulerCycle(int source) {
  vector<int> cycle;
  stack<int,vector<int>> s;
  s.push(source);
  while (!s.empty()) {
    int u = s.top();
    if (g[u].empty()) {
      cycle.push_back(u);
      s.pop();
    } else {
      int v = *g[u].begin();
      g[u].erase(v);
      g[v].erase(u);
      s.push(v);
    }
  }
  return cycle;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int u = 1; u <= n; ++u) {
      g[u].clear();
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].insert(v);
      g[v].insert(u);
    }
    int ans = n;
    for (int u = 1; u <= n; ++u) {
      if (g[u].size() % 2) {
        g[0].insert(u);
        g[u].insert(0);
        --ans;
      }
    }
    cout << ans << '\n';
    for (int s = 1; s <= n; ++s) {
      int u = 0;
      for (int v : eulerCycle(s)) {
        if (u && v) {
          cout << u << ' ' << v << '\n';
        }
        u = v;
      }
    }
  }
  return 0;
}
