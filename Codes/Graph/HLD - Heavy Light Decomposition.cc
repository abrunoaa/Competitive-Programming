/// HLD - Heavy Light Decomposition

#define maxn 100003
int cnt, size[maxn], depth[maxn], p[maxn], head[maxn], pos[maxn];
vector<int> g[maxn];

void dfs(int u = 1, int par = 0){
  p[u] = par;
  depth[u] = depth[par] + 1;
  size[u] = 1;
  for(int v : g[u]) if(v != par){
    dfs(v, u);
    size[u] += size[v];
  }
}

void hld(int h = 1, int u = 1, int par = 0){
  head[u] = h;
  pos[u] = cnt++;
  int pref = 0;
  for(int v : g[u])
    if(v != par && size[v] > size[u])
      pref = v;
  if(pref) hld(h, pref, u);
  for(int v : g[u])
    if(v != par && v != pref)
      hld(v, v, u);
}

int lca(int u, int v){
  while(head[u] != head[v]){
    if(depth[head[u]] < depth[head[v]]) swap(u, v);
    u = p[head[u]];
  }
  return (depth[u] < depth[v] ? u : v);
}

void update(int u, int v, int x){
  int w = lca(u, v);
  auto helper = [w, x](int u){
    while(head[u] != head[w]){
      int h = head[u];
      upd(pos[h], pos[u], x);     // seg-tree ou algo parecido para atualizar o
      u = p[h];                   //  intervalo
    }
    upd(pos[w], pos[u], x);
  };
  helper(u);
  helper(v);
}

int query(int u, int v){
  int w = lca(u, v);
  auto helper = [w](int u){
    int ans = 0;
    while(head[u] != head[w]){
      int h = head[u];
      ans += qry(pos[h], pos[u]);
      u = p[h];
    }
    ans += qry(pos[w], pos[u]);
    return ans;
  };
  return helper(u) + helper(v);
}
