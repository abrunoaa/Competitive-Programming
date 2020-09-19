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
const int maxn = 705;

int vis[maxn];
vector<int> g[maxn];
ii memo[maxn][maxn][3];

ii operator+(ii a, ii b) {
  return ii(a.st + b.st, a.nd + b.nd);
}

ii operator-(ii a, ii b) {
  return ii(a.st - b.st, a.nd - b.nd);
}

int cmp(ii a, ii b) {
  const lf lg3 = log2(3.0);
  return (a.st - b.st) * lg3 < b.nd - a.nd;
}

ii dfs(int u, int p, int k) {
  auto &dp = memo[u][p][k];
  if (dp.st != -1) return dp;

  vis[u] = 1;
  ii all(0, 0);
  fore(v, g[u]) if (v != p) {
    all = all + dfs(v, u, 0);
  }

  dp = all + ii(k == 2, k == 1);

  if (k != 2) {
    fore(v, g[u]) if (v != p) {
      ii tmp = all - dfs(v, u, 0) + dfs(v, u, k + 1);
      if (cmp(dp, tmp)) {
        dp = tmp;
      }
    }
  }
  if (k == 0) {
    fore(v, g[u]) if (v != p) {
      fore(w, g[u]) if (w != p && w != v) {
        ii tmp = all - dfs(v, u, 0) - dfs(w, u, 0) + dfs(v, u, 2) + dfs(w, u, 2) - ii(1, 0);
        if (cmp(dp, tmp)) {
          dp = tmp;
        }
      }
    }
  }

  return dp;
}

int main() {
  //assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  forr(i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  memset(memo, -1, sizeof(memo));
  ii p(0, 0);
  forr(u, 1, n + 1) {
    if (!vis[u]) {
      p = p + dfs(u, u, 0);
    }
  }
  debug(p);

  ll ans = 1;
  forn(i, p.st) ans *= 3;
  forn(i, p.nd) ans *= 2;
  cout << ans << '\n';
  return 0;
}

