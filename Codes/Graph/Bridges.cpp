/// Encontra pontes no grafo não direcionado

#define maxn 100010

int cnt, low[maxn], num[maxn];
vector<int> g[maxn];            // grafo não direcionado

void bridges(int u, int p) {
  low[u] = num[u] = ++cnt;
  for (int v : g[u]) if (v != p) {
      if (num[v] == -1) {
        bridges(v, u);
        if (low[v] > num[u]) { cout << " >> bridge " << u << " -> " << v << '\n'; }
      }
      low[u] = min(low[u], low[v]);
    }
}

/// main
memset(num, -1, sizeof num);
for (int u = 1; u <= n; ++u)
  if (num[u] == -1) {
    bridges(u, -1);
  }
