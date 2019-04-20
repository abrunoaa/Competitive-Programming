#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t&x,const u&...y){cerr<<' '<<x,debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
#endif

#define st first
#define nd second
#define inf 0x3f3f3f3f
#define maxn 100003
#define maxlog 17
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

typedef pair<int,int> ii;

struct No{ int ans, maxl, maxr, t, lz; };

No merge(const No& x, const No& y){
  return { max(max(x.ans, y.ans), x.maxr + y.maxl),
    max(x.maxl, x.t + y.maxl),
    max(y.maxr, y.t + x.maxr),
    x.t + y.t,
    inf };
}

int n, x[maxn], val[maxn];
int depth[maxn], p[maxlog][maxn];
int chainNum, pt, chain[maxn], head[maxn], pos[maxn], size[maxn];
No st[4 * maxn];
vector<int> g[maxn];

void dfs(int u, int par = 0, int d = 0){
  depth[u] = d;
  p[0][u] = par;
  size[u] = 1;
  for(int v : g[u]) if(v != par){
    dfs(v, u, d + 1);
    size[u] += size[v];
  }
}

void buildLca(){
  for(int i = 1; i < maxlog; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
    }
  }
}

ii lca(int u, int v){
  bool swapped = depth[u] < depth[v];
  if(swapped) swap(u, v);
  int w = u;
  int d = depth[u] - depth[v];
  for(int i = maxlog - 1; i >= 0; --i)
    if((d >> i) & 1)
      u = p[i][u];
  if(u == v){
    if(!swapped) return { u, -1 };
    --d;
    for(int i = maxlog - 1; i >= 0; --i)
      if((d >> i) & 1)
        w = p[i][w];
    return { u, w };
  }
  for(int i = maxlog - 1; i >= 0; --i) if(p[i][u] != p[i][v]){
    u = p[i][u];
    v = p[i][v];
  }
  return { p[0][u], (swapped ? u : v) };
}

void hld(int u, int par = 0){
  if(!head[chainNum]) head[chainNum] = u;
  chain[u] = chainNum;
  pos[u] = pt;
  val[pt] = x[u];
  ++pt;
  int pref = 0;
  for(int v : g[u])
    if(v != par && size[v] > size[pref])
      pref = v;
  if(pref) hld(pref, u);
  for(int v : g[u]) if(v != par && v != pref){
    ++chainNum;
    hld(v, u);
  }
}

No& buildSegtree(int t = 1, int l = 0, int r = n - 1){
  if(l == r) return st[t] = { max(0, val[l]), max(0, val[l]), max(0, val[l]), val[l], inf };
  return st[t] = merge(buildSegtree(L, l, M), buildSegtree(R, M+1, r));
}

void prop(int t, int n){
  int &x = st[t].lz;
  if(x != inf){
    st[t].ans = st[t].maxl = st[t].maxr = max(0, n * x);
    st[t].t = n * x;
    if(n > 1) st[L].lz = st[R].lz = x;
    x = inf;
  }
}

No& upd(int i, int j, int x, int t = 1, int l = 0, int r = n - 1){
  if(i <= l && r <= j){
    st[t].lz = x;
    prop(t, r - l + 1);
    return st[t];
  }
  prop(t, r - l + 1);
  if(r < i || j < l) return st[t];
  return st[t] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M+1, r));
}

No qry(int i, int j, int t = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return { 0, -inf, -inf, 0, inf };
  prop(t, r - l + 1);
  if(i <= l && r <= j) return st[t];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

void change(int u, int v, int x){
  const auto helper = [x](int u, int v){
    while(chain[u] != chain[v]){
      int h = head[chain[u]];
      upd(pos[h], pos[u], x);
      u = p[0][h];
    }
    upd(pos[v], pos[u], x);
  };
  ii w = lca(u, v);
  helper(u, w.st);
  if(w.nd != -1) helper(v, w.nd);
}

int query(int u, int v){
  const auto helper = [](int u, int v){
    No ans = { 0, -inf, -inf, 0, inf};
    while(chain[u] != chain[v]){
      int h = head[chain[u]];
      ans = merge(qry(pos[h], pos[u]), ans);
      u = p[0][h];
    }
    return merge(qry(pos[v], pos[u]), ans);
  };
  ii w = lca(u, v);
  No x = helper(u, w.st);
  if(w.nd == -1) return x.ans;
  No y = helper(v, w.nd);
  return max(max(x.ans, y.ans), x.maxl + y.maxl);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> x[i];
  for(int i = 1; i < n; ++i){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1);
  buildLca();
  hld(1);
  buildSegtree();

  int q;
  cin >> q;
  while(q--){
    int op, a, b, c;
    cin >> op >> a >> b;
    if(op == 1){
      cout << query(a, b) << '\n';
    }
    else{
      cin >> c;
      change(a, b, c);
    }
  }

  return 0;
}
