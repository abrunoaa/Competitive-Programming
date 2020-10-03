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
const int maxn = 1003;

bool cnt[maxn];
bool done[maxn];
int n, k;
int g[maxn];
int vis[maxn];
vector<int> h[maxn];
vector<int> cand;
int memo[maxn][maxn];

int count(int u) {
  cnt[u] = 1;
  int r = 1;
  fore(v, h[u]) if (!cnt[v]) {
    r += count(v);
  }
  return r;
}

ii find(int u, int t) {
  int v = g[u];
  vis[u] = t;

  ii res(0, 0);
  int pass = t - vis[v] + 1;
  if (u == v) {
    res = ii(pass, count(v) - pass);
  } else if (done[v]) {
  } else if (!vis[v]) {
    res = find(v, t + 1);
  } else if (t - vis[v] + 1 > k) {
  } else {
    res = ii(pass, count(v) - pass);
  }

  debug(u, v, done[v], "---", vis[u], vis[v], t, res);
  done[u] = 1;
  return res;
}

int sum(int i, int s) {
  if (s > k) return 0;
  if (i < 0) return s;

  int &dp = memo[i][s];
  if (dp != -1) return dp;

  return dp = max(sum(i - 1, s), sum(i - 1, s + cand[i]));
}

int main() {
  assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  forr(u, 1, n + 1) {
    int v;
    cin >> v;
    g[u] = v;
    h[v].push_back(u);
  }
  int add = 0;
  forr(u, 1, n + 1) if (!done[u]) {
    ii r = find(u, 1);
    debug(u, r);
    if (r.st > 0) {
      add += r.nd;
      cand.push_back(r.st);
    }
  }
  debug(cand);
  memset(memo, -1, sizeof(memo));
  cout << min(k, sum((int)cand.size() - 1, 0) + add) << '\n';
  return 0;
}
