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
#define maxn 100003
#define maxl 17
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m, number[maxn];
int depth[maxn], p[maxl][maxn];
int chainNum, pt, size[maxn], chain[maxn], head[maxn], pos[maxn], val[maxn];
vector<int> g[maxn], st[4 * maxn];

void clear(){
  chainNum = 0;
  pt = 0;
  memset(head, 0, sizeof head);
  for(auto& x : g) x.clear();
}

void dfs(int u, int par = 0, int d = 0){
  size[u] = 1;
  depth[u] = d;
  p[0][u] = par;
  for(int v : g[u]) if(v != par){
    dfs(v, u, d + 1);
    size[u] += size[v];
  }
}

void hld(int u, int par = 0){
  if(!head[chainNum]) head[chainNum] = u;
  chain[u] = chainNum;
  pos[u] = pt;
  val[pt] = number[u];
  ++pt;
  int pref = 0;
  for(int v : g[u]){
    if(v != par && size[v] > size[pref]){
      pref = v;
    }
  }
  if(pref) hld(pref, u);
  for(int v : g[u]) if(v != par && v != pref){
    ++chainNum;
    hld(v, u);
  }
}

void buildLca(){
  for(int i = 1; i < maxl; ++i){
    for(int u = 1; u <= n; ++u){
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
    }
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int d = depth[u] - depth[v];
  for(int i = maxl - 1; i >= 0; --i)
    if((d >> i) & 1)
      u = p[i][u];
  if(u == v) return u;
  for(int i = maxl - 1; i >= 0; --i) if(p[i][u] != p[i][v]){
    u = p[i][u];
    v = p[i][v];
  }
  return p[0][u];
}

void buildms(int t = 1, int l = 0, int r = n - 1){
  st[t].resize(r - l + 1);
  if(l == r) st[t][0] = val[l];
  else{
    buildms(L, l, M);
    buildms(R, M+1, r);
    merge(st[L].begin(), st[L].end(), st[R].begin(), st[R].end(), st[t].begin());
  }
}

bool find(int i, int j, int x, int t = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return 0;
  if(i <= l && r <= j){
    int k = (int)(lower_bound(st[t].begin(), st[t].end(), x) - st[t].begin());
    return k < (int)st[t].size() && st[t][k] == x;
  }
  return find(i, j, x, L, l, M) || find(i, j, x, R, M+1, r);
}

bool query(int a, int b, int c){
  int w = lca(a, b);
  auto helper = [w, c](int u){
    while(chain[u] != chain[w]){
      int h = head[chain[u]];
      if(find(pos[h], pos[u], c)) return true;
      u = p[0][h];
    }
    return find(pos[w], pos[u], c);
  };
  return helper(a) || helper(b);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n >> m){
    clear();
    for(int i = 1; i <= n; ++i) cin >> number[i];
    for(int i = 1; i < n; ++i){
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    dfs(1);
    buildLca();
    hld(1);
    buildms();
    while(m--){
      int a, b, c;
      cin >> a >> b >> c;
      cout << (query(a, b, c) ? "Find" : "NotFind") << '\n';
    }

    cout << '\n';
  }

  return 0;
}
