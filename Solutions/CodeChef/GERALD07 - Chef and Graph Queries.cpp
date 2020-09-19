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
#define freopen(...) void(0)
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
const int maxn = (int)2e5 + 3;

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

struct Qry {
  int l, r, id;
  Qry() {}
  Qry(int _l, int _r, int _id): l(_l), r(_r), id(_id) {}
};

const int bs = (int)sqrt(maxn);
int u[maxn], v[maxn];
int ans[maxn];
vector<Qry> blk[maxn / bs + 1];

int main() {
  //assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  forn(t, T) {
    int n, m, q;
    cin >> n >> m >> q;
    forn(i, m) {
      cin >> u[i] >> v[i], --u[i], --v[i];
    }
    forn(i, m / bs + 1) {
      blk[i].clear();
    }
    forn(i, q) {
      int l, r;
      cin >> l >> r, --l, --r;
      blk[l / bs].emplace_back(l, r, i);
    }
    forn(i, m / bs + 1) {
      auto& b = blk[i];
      sort(b.begin(), b.end(), [](const Qry& lhs, const Qry& rhs) {
        return lhs.r < rhs.r;
      });
      Dsu dsu(n);
      int j = min(m, (i + 1) * bs);
      fore(qry, b) {
        for (; j <= qry.r; ++j) {
          dsu.unite(u[j], v[j]);
        }
        int cnt = 0;
        forr(k, qry.l, min((i + 1) * bs, qry.r + 1)) {
          cnt += dsu.unite(u[k], v[k]);
        }
        ans[qry.id] = dsu.comps;
        forn(k, cnt) dsu.rollback();
      }
    }
    forn(i, q) {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}
