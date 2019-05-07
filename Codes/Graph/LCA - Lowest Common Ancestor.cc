/// LCA - Lowest Common Ancestor

#define maxn 100003
#define maxl ((int)log2(maxn) + 1)

int n;
int depth[maxn];
int p[maxn][maxl];
vector<int> g[maxn];

void dfs(int u = 1, int par = 0){
  p[u][0] = par;
  depth[u] = depth[par] + 1;
  for(int v : g[u])
    if(v != par)
      dfs(v, u);
}

void build(){                           // >>>>>> chama o dfs antes!!!
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[u][i - 1];
      p[u][i] = p[v][i - 1];
    }
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for(int i = maxl - 1; i >= 0; --i)
    if((dif >> i) & 1)
      u = p[u][i];
  if(u == v) return u;
  for(int i = maxl - 1; i >= 0; --i) if(p[u][i] != p[v][i]){
    u = p[u][i];
    v = p[v][i];
  }
  return p[u][0];
}
