#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t&x,const u&...y){cerr<<' '<<x,debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T,class C> DEF1(set<T,C>) template<class T,class C> DEF1(multiset<T,C>) template<class K,class T,class C> DEF1(map<K,T,C>) template<class K,class T,class C> DEF1(multimap<K,T,C>)
template<class T> DEF2(front,pop,queue<T>) template<class T> DEF2(top,pop,stack<T>) template<class T,class V,class C> DEF2(top,pop,priority_queue<T,V,C>)

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 40003
#define maxm 100003
#define maxl 16

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

struct Qry{ int i, j, w, id; };

bool used[maxn];
int n, m, w[maxn];
int cur, freq[maxn], ans[maxm];
int cnt, in[maxn], out[maxn], order[2 * maxn], depth[maxn], par[maxl][maxn];
Qry q[maxm];
vector<int> g[maxn];

void dfs(int u = 1, int p = 0){
  in[u] = cnt;
  order[cnt] = u;
  ++cnt;
  par[0][u] = p;
  for(int v : g[u]) if(v != p){
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  out[u] = cnt;
  order[cnt] = u;
  ++cnt;
}

void buildLca(){
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = par[i - 1][u];
      par[i][u] = par[i - 1][v];
    }
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for(int i = maxl - 1; i >= 0; --i)
    if((dif >> i) & 1)
      u = par[i][u];
  if(u == v) return u;
  for(int i = maxl - 1; i >= 0; --i) if(par[i][u] != par[i][v]){
    u = par[i][u];
    v = par[i][v];
  }
  return par[0][u];
}

void update(int u){
  u = order[u];
  used[u] ^= 1;
  if(used[u]) cur += ++freq[w[u]] == 1;
  else cur -= --freq[w[u]] == 0;
}

void mo(){
  int bs = (int)sqrt(2 * n);
  sort(q, q + m, [bs](const Qry& x, const Qry& y){
    int bx = x.i / bs, by = y.i / bs;
    if(bx != by) return bx < by;
    return (bx % 2 == 0 ? x.j < y.j : x.j > y.j);
  });

  int l = 0, r = -1;
  for(int k = 0; k < m; ++k){
    int i = q[k].i;
    int j = q[k].j;
    int w = q[k].w;
    int id = q[k].id;

    while(r < j) update(++r);
    while(r > j) update(r--);
    while(l < i) update(l++);
    while(l > i) update(--l);

    if(w != -1) update(w);
    ans[id] = cur;
    if(w != -1) update(w);
  }
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;

  map<int,int> mp;
  for(int i = 1; i <= n; ++i){
    cin >> w[i];
    mp[w[i]];
  }

  int k = 0;
  for(auto &x : mp) x.nd = k++;
  for(int i = 1; i <= n; ++i) w[i] = mp[w[i]];

  for(int i = 1; i < n; ++i){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs();
  buildLca();

  for(int i = 0; i < m; ++i){
    int u, v;
    cin >> u >> v;
    int w = lca(u, v);
    if(in[u] > in[v]) swap(u, v);
    if(w == u) q[i] = { in[u], in[v], -1, i };
    else q[i] = { out[u], in[v], in[w], i };
  }

  mo();
  for(int i = 0; i < m; ++i) cout << ans[i] << '\n';

  return 0;
}
