#include <bits/stdc++.h>
using namespace std;

const int maxn = 203;

int n, m;
multiset<int> g[maxn], h[maxn];
bool vis[maxn];
vector<int> cc;

void dfs(int u) {
  cc.push_back(u);
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v])
      dfs(v);
}

vector<int> eulerCycle(int s) {
  vector<int> cycle;
  stack<int,vector<int>> st;
  st.push(s);
  while (!st.empty()) {
    int u = st.top();
    if (g[u].empty()) {
      cycle.push_back(u);
      st.pop();
    } else {
      int v = *g[u].begin();
      g[u].erase(g[u].find(v));
      g[v].erase(g[v].find(u));
      st.push(v);
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
    cin >> n >> m;
    for (int u = 1; u <= n; ++u) {
      g[u].clear();
      vis[u] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].insert(v);
      g[v].insert(u);
    }
    for (int u = 1; u <= n; ++u) {
      h[u] = g[u];
    }
    int ans = 0;
    for (int u = 1; u <= n; ++u) {
      ans += g[u].size() % 2 == 0;
    }
    cout << ans << '\n';
    for (int u = 1; u <= n; ++u) {
      if (!vis[u]) {
        cc.clear();
        dfs(u);
        int w = 0;
        for (int v : cc) {
          if (g[v].size() % 2 == 1) {
            if (w == 0) {
              w = v;
            } else {
              g[w].insert(v);
              g[v].insert(w);
              w = 0;
            }
          }
        }
        w = 0;
        for (int v : eulerCycle(u)) {
          if (h[w].count(v)) {
            h[w].erase(v);
            h[v].erase(w);
            cout << w << ' ' << v << '\n';
          }
          w = v;
        }
      }
    }
  }
  return 0;
}
