int centroid[maxn], size[maxn];
set<int> g[maxn];

void dfs(int u, int par = 0) {
  size[u] = 1;
  for (int v : g[u]) if (v != par) {
    dfs(v, u);
    size[u] += size[v];
  }
}

int findCentroid(int u, int p, int n) {
  for (int v : g[u])
    if (v != p && size[v] > n / 2)
      return findCentroid(v, u, n);
  return u;
}

void buildCentroid(int u = 1, int par = 0) {
  dfs(u);
  u = findCentroid(u, 0, size[u]);
  centroid[u] = par;                    // armazena apenas o pai no centroid
  for (int v : g[u]) {
    g[v].erase(u);
    buildCentroid(v, u);
  }
}

void update(int v) {
  for (int u = v; u; u = centroid[u]) {
    // atualiza o caminho de v -> u, e salva o valor em u
  }
}

/// query faz a mesma coisa que o update (ou não ;))
