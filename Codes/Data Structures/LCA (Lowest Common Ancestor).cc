/// LCA - Lowest Common Ancestor

#define maxn 100010
#define maxlog ((int)log2(maxn) + 1)

int n;
int h[maxn];          // h[i] = altura do vértice i
int p[maxn][maxlog];  // p[i][j] = pai de i subindo 2^j níveis
vector<int> g[maxn];

// calcula a altura de todos os nós e pai 2^0 níveis acima
void dfs(int u, int k){
  p[u][0] = k;          // pai de u
  h[u] = h[k] + 1;      // nível de u
  for(int v : g[u])     // filhos de u
    if(v != k)
      dfs(v, u);
}

// constrói a árvore do LCA
void build(int r){
  h[r] = 0;
  dfs(r, r);
  for(int k = 1; k < maxlog; ++k)
    for(int u = 1; u <= n; ++u){
      int v = p[u][k - 1];
      p[u][k] = p[v][k - 1];
    }
}

// calcula LCA dos vértices u e v
int lca(int u, int v){
  if(h[u] < h[v]) swap(u, v);

  int d = h[u] - h[v];
  for(int k = maxlog - 1; k >= 0; --k)
    if(d & (1 << k))
      u = p[u][k];

  if(u == v) return u;

  for(int k = maxlog - 1; k >= 0; --k)
    if(p[u][k] != p[v][k]){
      u = p[u][k];
      v = p[v][k];
    }

  assert(p[u][0] == p[v][0]);
  return p[u][0];
}
