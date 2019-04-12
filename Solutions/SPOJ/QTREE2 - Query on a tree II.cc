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

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 10003
#define maxl 15

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, depth[maxn], p[maxl][maxn], cost[maxl][maxn];
vector<ii> g[maxn];

void dfs(int u, int par = 0, int d = 0){
  depth[u] = d;
  p[0][u] = par;
  for(ii v : g[u]){
    if(v.st != par){
      cost[0][v.st] = v.nd;
      dfs(v.st, u, d + 1);
    }
  }
}

void build_lca(){
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
      cost[i][u] = cost[i - 1][u] + cost[i - 1][v];
    }
  }
}

ii lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);

  int d = depth[u] - depth[v];
  int c = 0;
  for(int i = maxl - 1; i >= 0; --i){
    if(d & (1 << i)){
      c += cost[i][u];
      u = p[i][u];
    }
  }

  if(u == v) return {u, c};

  for(int i = maxl - 1; i >= 0; --i){
    if(p[i][u] != p[i][v]){
      c += cost[i][u] + cost[i][v];
      u = p[i][u];
      v = p[i][v];
    }
  }

  return {p[0][u], c + cost[0][u] + cost[0][v]};
}

int kth(int u, int v, int k){
  int w = lca(u, v).st;
  if(k <= depth[u] - depth[w] + 1){
    --k;
  }
  else{
    k = depth[u] + depth[v] - k - 2 * depth[w] + 1;
    u = v;
  }

  for(int i = maxl - 1; i >= 0; --i)
    if(k & (1 << i))
      u = p[i][u];
  return u;
}

int dist(int u, int v){
  return lca(u, v).nd;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    for(auto& v : g) v.clear();

    cin >> n;
    for(int i = 1; i < n; ++i){
      int u, v, c;
      cin >> u >> v >> c;
      g[u].push_back({v, c});
      g[v].push_back({u, c});
    }

    cost[0][1] = 0;
    dfs(1);
    build_lca();

    char op[10];
    while(cin >> op, op[1] != 'O'){
      int u, v;
      cin >> u >> v;
      if(op[0] == 'K'){
        int k;
        cin >> k;
        cout << kth(u, v, k) << '\n';
      }
      else{
        cout << dist(u, v) << '\n';
      }
    }
  }

  return 0;
}
