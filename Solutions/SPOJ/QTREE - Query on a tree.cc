#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){ cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n"; }

void debug(){}
template<class t,class... u> void debug(const t& x,const u& ...y){ cerr<<' '<<x,debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define maxn 10003
#define maxl 14
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

struct Neig{ int v, c, k; };

int n, chainNum, pt, edge[maxn];
int p[maxl][maxn], depth[maxn];  // LCA
int size[maxn], head[maxn], chain[maxn], pos[maxn]; // HLD
int val[maxn], st[4 * maxn];  // segtree
vector<Neig> g[maxn];

void clear(){
  chainNum = 0;
  pt = 0;
  memset(head, 0, sizeof head);
  for(auto& v : g) v.clear();
}

void dfs(int u, int par = 0, int d = 0){
  p[0][u] = par;
  depth[u] = d;
  size[u] = 1;                          // size of subtree rooted at u
  for(auto& v : g[u]) if(v.v != par){
    edge[v.k] = v.v;                    // edge k is between u -> v
    dfs(v.v, u, d + 1);
    size[u] += size[v.v];
  }
}

void hld(int u, int cost = 0, int par = 0){
  if(!head[chainNum]) head[chainNum] = u;   // new chain
  chain[u] = chainNum;
  pos[u] = pt;                              // pos in segtree
  val[pt] = cost;                           // cost of root is outside segtree
  ++pt;                                     //   since it have no parent

  Neig pref{0,0,0};                         // preferred child (0 for none)
  if(g[u].size() > 1){
    for(auto& v : g[u])
      if(v.v != par && size[v.v] > size[pref.v])
        pref = v;
    hld(pref.v, pref.c, u);
  }
  for(auto& v : g[u]){
    if(v.v != pref.v && v.v != par){
      ++chainNum;
      hld(v.v, v.c, u);
    }
  }
}

void build_lca(){
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
    }
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for(int i = maxl - 1; i >= 0; --i)
    if(dif & (1 << i))
      u = p[i][u];
  if(u == v) return u;
  for(int i = maxl - 1; i >= 0; --i){
    if(p[i][u] != p[i][v]){
      u = p[i][u];
      v = p[i][v];
    }
  }
  return p[0][u];
}

int build_segt(int t = 1, int l = 1, int r = n - 1){  // cost from node to it's parent
  if(l == r) return st[t] = val[l];
  return st[t] = max(build_segt(L, l, M), build_segt(R, M+1, r));
}

int upd(int i, int x, int t = 1, int l = 1, int r = n - 1){
  if(r < i || i < l) return st[t];
  if(l == r) return st[t] = x;
  if(i <= M) return st[t] = max(upd(i, x, L, l, M), st[R]);
  return st[t] = max(st[L], upd(i, x, R, M+1, r));
}

int qry(int i, int j, int t = 1, int l = 1, int r = n - 1){
  if(r < i || j < l) return -1;
  if(i <= l && r <= j) return st[t];
  return max(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

void change(int v, int c){ upd(pos[edge[v]], c); }

int queryUp(int u, int v){
  if(u == v) return -1;
  int ans = -1;
  while(chain[u] != chain[v]){
    int h = head[chain[u]];
    ans = max(ans, qry(pos[h], pos[u]));
    u = p[0][h];
  }
  return max(ans, qry(pos[v] + 1, pos[u]));
}

int query(int u, int v){
  int w = lca(u, v);
  return max(queryUp(u, w), queryUp(v, w));
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    clear();
    cin >> n;
    for(int i = 1; i < n; ++i){
      int u, v, c;
      cin >> u >> v >> c;
      g[u].push_back({v, c, i});
      g[v].push_back({u, c, i});
    }

    dfs(1);
    hld(1);
    build_lca();
    build_segt();

    char op[10];
    while(cin >> op, op[0] != 'D'){
      int a, b;
      cin >> a >> b;
      if(op[0] == 'C') change(a, b);
      else cout << query(a, b) << '\n';
    }
  }

  return 0;
}