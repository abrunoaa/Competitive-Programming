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
//#define freopen(...) void(0)
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
const int maxn = (int)3e5 + 3;

struct DsuOp {
  int v, rv, u, ru;
  DsuOp() {}
  DsuOp(int _v, int _rv, int _u, int _ru): v(_v), rv(_rv), u(_u), ru(_ru) {}
};

struct Dsu {
  vector<int> p, r;
  int comps;
  stack<DsuOp> op;

  Dsu() {}
  Dsu(int n): p(n), r(n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      r[i] = 0;
    }
    comps = n;
  }

  int find(int v) { return (v == p[v]) ? v : find(p[v]); }

  bool unite(int v, int u) {
    v = find(v);
    u = find(u);
    if (v == u) return false;
    --comps;
    if (r[v] > r[u]) swap(v, u);
    op.emplace(v, r[v], u, r[u]);
    p[v] = u;
    if (r[u] == r[v]) ++r[u];
    return true;
  }

  void rollback() {
    assert(!op.empty());
    DsuOp x = op.top();
    op.pop();
    ++comps;
    p[x.v] = x.v;
    r[x.v] = x.rv;
    p[x.u] = x.u;
    r[x.u] = x.ru;
  }
};

/* segtree */
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) >> 1)

struct query {
  int v, u;
  bool united;
  query(int _v, int _u) : v(_v), u(_u) {}
};

struct QueryTree {
  int T;  // number of queries
  Dsu dsu;
  vector<vector<query>> tree;

  QueryTree() {}
  QueryTree(int _T, int n): T(_T), dsu(n), tree(4 * T + 4) {}

  void add(int t, int l, int r, int ul, int ur, query& q) {
    if (ul > ur) return;
    assert(t < (int)tree.size());
    if (l == ul && r == ur) {
      tree[t].push_back(q);
      return;
    }
    add(L, l, M, ul, min(ur, M), q);
    add(R, M + 1, r, max(ul, M + 1), ur, q);
  }

  void add(query q, int l, int r) {
    add(1, 0, T - 1, l, r, q); 
  }

  void dfs(int t, int l, int r, vector<int>& ans) {
    for (query& q : tree[t]) q.united = dsu.unite(q.v, q.u);
    if (l == r) {
      ans[l] = dsu.comps;
    } else {
      dfs(L, l, M, ans);
      dfs(R, M + 1, r, ans);
    }
    for (query& q : tree[t]) if (q.united) dsu.rollback();
  }

  vector<int> solve() {
    vector<int> ans(T);
    dfs(1, 0, T - 1, ans);
    return ans;
  }
};

bool isq[maxn];
map<int, vector<int>> oper[maxn];

int main() {
  //assert(freopen("in", "r", stdin));
  //freopen("connect.in", "r", stdin);
  //freopen("connect.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  QueryTree qt(k + 1, n + 1);
  forn(i, k) {
    char op;
    cin >> op;
    if (op == '?') {
      isq[i] = true;
      qt.add(query(0, 0), i, i);
    } else {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      oper[u][v].push_back(i);
    }
  }
  forn(u, n) {
    for (auto [v, t] : oper[u]) {
      if (t.size() % 2) {
        t.push_back(k);
      }
      forn(i, t.size() / 2) {
        qt.add(query(u, v), t[2 * i], t[2 * i + 1]);
        debug(u, v, t[2 * i], t[2 * i + 1]);
      }
    }
  }
  auto ans = qt.solve();
  forn(i, k) if (isq[i]) {
    cout << ans[i] - 1 << '\n';
  }
  return 0;
}

