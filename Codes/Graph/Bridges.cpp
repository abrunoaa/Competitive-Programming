int timer, low[maxn], tin[maxn];
vector<int> g[maxn];            // grafo não direcionado

void dfs(int u, int p) {
  low[u] = tin[u] = ++timer;
  for (int v : g[u]) if (v != p) {
    if (!tin[v]) {
      dfs(v, u);
      if (low[v] > tin[u]) cout << " >> bridge " << u << " -> " << v << '\n';
    }
    low[u] = min(low[u], low[v]);
  }
}

void findBridges() {
  timer = 0;
  memset(tin, 0, sizeof tin);
  for (int u = 1; u <= n; ++u)
    if (!tin[u])
      dfs(u, -1);
}
