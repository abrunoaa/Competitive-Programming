#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e4 + 3;

vector<int> g[maxn];
bool vis[maxn];
int cnt, par[maxn], disc[maxn], low[maxn];
map<int,set<int>> bridges;

void findBridges(int u) {
  vis[u] = 1;
  disc[u] = low[u] = ++cnt;
  for (int v : g[u]) {
    if (!vis[v]) {
      par[v] = u;
      findBridges(v);
      low[u] = min(low[u], low[v]);
      if (disc[u] < low[v]) {
        bridges[u].insert(v);
        bridges[v].insert(u);
      }
    } else if (v != par[u]) {
      low[u] = min(low[u], disc[v]);
    }
  }
}

int dfs(int u) {
  vis[u] = 1;
  int ans = 1;
  for (int v : g[u]) {
    if (!vis[v] && !bridges[u].count(v)) {
      ans += dfs(v);
    }
  }
  return ans;
}

int main() {
  assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  findBridges(0);
  memset(vis, 0, sizeof(vis));
  cout << dfs(0) << '\n';
  return 0;
}
