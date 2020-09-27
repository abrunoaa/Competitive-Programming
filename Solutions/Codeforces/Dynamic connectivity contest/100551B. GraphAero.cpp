#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t &x, const u &...y){cerr<<' '<<x, debug(y...);}
#define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
#define assert(x) void(0)
#define debug(...) void(0)
// #define freopen(...) void(0)
#define sleep(x) void(0)
#endif

template<class T>inline int lb(const vector<T>&v,const T&x,int l=0,int r=-1){return(int)(lower_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int ub(const vector<T>&v,const T&x,int l=0,int r=-1){return(int)(upper_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int lb(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(lower_bound(v+l,v+(r==-1?n:r),x)-v);}
template<class T>inline int ub(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(upper_bound(v+l,v+(r==-1?n:r),x)-v);}

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T>DEF1(vector<T>) template<class T,class C>DEF1(set<T,C>) template<class T,class C>DEF1(multiset<T,C>) template<class K,class T,class C>DEF1(map<K,T,C>) template<class K,class T,class C>DEF1(multimap<K,T,C>)
template<class T>DEF2(front,queue<T>) template<class T>DEF2(top,stack<T>) template<class T,class V,class C>DEF2(top,priority_queue<T,V,C>)

#define st first
#define nd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define fore(i, v) for (auto &i : v)

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<int,ii> tri;

const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;
const lf eps = 1e-9;
const int mod = 1000000007;
const int maxn = (int)1e5 + 3;

int bridges;
int dsu[maxn], dsu2[maxn];
int p[maxn];                  // the parent of the 2e tree
int sz[maxn];
int mit, vis[maxn];
vector<int> pu, pv;

void init(int n) {
  bridges = 0;
  mit = 0;
  for (int v = 0; v < n; ++v) {
    vis[v] = 0;
    sz[v] = 1;
    p[v] = -1;
    dsu[v] = dsu2[v] = v;
  }
}

int find2(int v) {            // only the leader of the 2e has correct values
  if (v == -1) return -1;
  return dsu2[v] == v ? v : dsu2[v] = find2(dsu2[v]);
}

int find(int v) {             // the leader of the cc
  v = find2(v);
  return dsu[v] == v ? v : dsu[v] = find(dsu[v]);
}

void makeRoot(int v) {        // revert pointers from root to v
  int child = -1, root = v = find2(v);
  while (v != -1) {
    int u = find2(p[v]);
    p[v] = child;
    dsu[v] = root;            // the root of the component now is v
    child = v;
    v = u;
  }
  sz[root] = sz[child];
}

void merge(int u, int v) {    // merge cycle u -> lca(u, v) -> v -> u into lca(u, v)
  ++mit;                      // avoid clearing vis every call
  pu.clear();
  pv.clear();

  // ------------ find lca(u, v) ------------
  int lca = -1;
  auto proc = [&lca](int &w, vector<int> &path) {
    if (w != -1) {
      w = find2(w);
      path.push_back(w);
      if (vis[w] == mit) lca = w;
      vis[w] = mit;
      w = p[w];
    }
  };
  while (lca == -1) { proc(u, pu); proc(v, pv); }

  // ------------ merge ------------
  for (auto &path : {pu, pv}) for (int w : path) {
    dsu2[w] = lca;
    if (w == lca) break;
    --bridges;
  }
}

void add(int u, int v) {      // add edge (u, v)
  u = find2(u);
  v = find2(v);
  if (u == v) return;         // already in the same 2e component

  int x = find(u);
  int y = find(v);
  if (x == y) {               // creates a new cycle
    merge(u, v);
  } else {                    // two distinct trees
    ++bridges;
    if (sz[x] > sz[y]) { swap(u, v); swap(x, y); }
    makeRoot(u);
    p[u] = dsu[u] = v;
    sz[y] += sz[u];
  }
}

int main() {
  freopen("bridges.in", "r", stdin);
  freopen("bridges.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  init(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    add(u, v);
  }
  int k;
  cin >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    cout << bridges << '\n';
  }
  return 0;
}
