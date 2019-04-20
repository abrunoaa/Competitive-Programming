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

#define inf 0x3f3f3f3f
#define maxn 100003
#define maxl 17

int n;
bool white[maxn];
int depth[maxn], p[maxl][maxn];
int size[maxn], centroid[maxn];
multiset<int> st[maxn];
set<int> g[maxn];

void dfsLca(int u, int par = 0, int d = 0){
  depth[u] = d;
  p[0][u] = par;
  for(int v : g[u]) if(v != par){
    dfsLca(v, u, d + 1);
  }
}

void buildLca(){
  dfsLca(1);
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
    }
  }
}

int dist(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int d = depth[u] - depth[v];
  for(int i = maxl - 1; i >= 0; --i)
    if(d & (1 << i))
      u = p[i][u];
  if(u == v) return d;
  for(int i = maxl - 1; i >= 0; --i) if(p[i][u] != p[i][v]){
    d += 2 << i;
    u = p[i][u];
    v = p[i][v];
  }
  return d + 2;
}

void dfsCentroid(int u, int p = 0){
  size[u] = 1;
  for(int v : g[u]) if(v != p){
    dfsCentroid(v, u);
    size[u] += size[v];
  }
}

int findCentroid(int u, int p, int n){
  for(int v : g[u])
    if(v != p && size[v] > n / 2)
      return findCentroid(v, u, n);
  return u;
}

void buildCentroid(int u = 1, int p = 0){
  dfsCentroid(u);
  u = findCentroid(u, 0, size[u]);
  centroid[u] = p;
  for(int v : g[u]){
    g[v].erase(u);
    buildCentroid(v, u);
  }
}

void change(int v){
  white[v] ^= 1;
  for(int u = v; u; u = centroid[u]){
    int d = dist(u, v);
    if(white[v]) st[u].insert(d);
    else st[u].erase(st[u].find(d));
  }
}

int ask(int v){
  int ans = inf;
  for(int u = v; u; u = centroid[u])
    if(!st[u].empty())
      ans = min(ans, dist(u, v) + *st[u].begin());
  return (ans == inf ? -1 : ans);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for(int i = 1; i < n; ++i){
    int a, b;
    cin >> a >> b;
    g[a].insert(b);
    g[b].insert(a);
  }

  buildLca();
  buildCentroid();

  int q;
  cin >> q;
  while(q--){
    int op, v;
    cin >> op >> v;
    if(op == 0) change(v);
    else cout << ask(v) << '\n';
  }

  return 0;
}
