const int maxn = (int)1e5 + 3;  // n = número de vértices do lado esquerdo
const int maxm = (int)1e5 + 3;  // m = número de vértices do lado direito
const int inf = 0x3f3f3f3f;
const int nil = 0;              // supõe que o grafo é indexado em 1

int n, m, dist[maxn + maxm], match[maxn + maxm];
vector<int> g[maxn + maxm];     // nil + g[1 .. n] + g[n+1 .. n+m]

// Hopcroft-Karp O(E sqrt(V)): maximum cardinality matching on a bipartite graph
bool bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (match[i] == nil) {
      dist[i] = 0;
      q.push(i);
    } else {
      dist[i] = inf;
    }
  }
  dist[nil] = inf;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {                // *** g[nil] está vazio! ***
      if (dist[match[v]] == inf) {
        dist[match[v]] = dist[u] + 1;
        q.push(match[v]);
      }
    }
  }
  return dist[nil] != inf;
}

bool dfs(int u) {
  if (u == nil) return true;
  for (int v : g[u]) {
    if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  dist[u] = inf;
  return false;
}

int hopcroft_karp() {
  for (int u = 1; u <= n + m; ++u)
    match[u] = nil;
  int matching = 0;
  while (bfs())
    for (int u = 1; u <= n; ++u)
      if (match[u] == nil && dfs(u))
        ++matching;
  return matching;
}
