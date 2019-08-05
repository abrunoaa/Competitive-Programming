#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() {cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";}

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) {cerr << ' ' << x, debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
#endif

template<class A, class B>ostream &operator<<(ostream &f, const pair<A, B> &x) {return f << '(' << x.first << ", " << x.second << ')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T, class C> DEF1(set<T, C>) template<class T, class C> DEF1(multiset<T, C>) template<class K, class T, class C> DEF1(map<K, T, C>) template<class K, class T, class C> DEF1(multimap<K, T, C>)
template<class T> DEF2(front, pop, queue<T>) template<class T> DEF2(top, pop, stack<T>) template<class T, class V, class C> DEF2(top, pop, priority_queue<T, V, C>)

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100003
#define maxl 17

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, ans;
int depth[maxn], p[maxl][maxn];
int size[maxn], centroid[maxn];
set<int> g[maxn];
multiset<int, greater<int>> maxDis[maxn];
map<int, int> mp[maxn];

void clear() {
  ans = 0;
  for (auto &x : g) { x.clear(); }
  for (auto &x : maxDis) { x.clear(); }
  for (auto &x : mp) { x.clear(); }
}

void dfs(int u, int par = 0, int d = 0) {
  depth[u] = d;
  p[0][u] = par;
  for (int v : g[u])
    if (v != par) {
      dfs(v, u, d + 1);
    }
}

void buildLca() {
  for (int i = 1; i < maxl; ++i) {
    for (int u = 1; u <= n; ++u) {
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
    }
  }
}

ii dist(int u, int v) {
  int par = p[0][u];
  int w = 0;
  if (depth[u] < depth[v]) {
    w = v;
    swap(u, v);
  }
  int dif = depth[u] - depth[v];
  int d = dif;
  for (int i = maxl - 1; i >= 0; --i)
    if ((dif >> i) & 1) {
      u = p[i][u];
    }
  if (u == v) {
    if (!w) return { d, par };
    --dif;
    for (int i = maxl - 1; i >= 0; --i)
      if ((dif >> i) & 1) {
        w = p[i][w];
      }
    return { d, w };
  }
  for (int i = maxl - 1; i >= 0; --i) if (p[i][u] != p[i][v]) {
      d += 2 << i;
      u = p[i][u];
      v = p[i][v];
    }
  return { d + 2, par };
}

void dfsCentroid(int u, int par = 0) {
  size[u] = 1;
  for (int v : g[u]) if (v != par) {
      dfsCentroid(v, u);
      size[u] += size[v];
    }
}

int findCentroid(int n, int u, int par = 0) {
  for (int v : g[u])
    if (v != par && size[v] > n / 2) {
      return findCentroid(n, v, u);
    }
  return u;
}

void buildCentroid(int u, int par = 0) {
  dfsCentroid(u);
  u = findCentroid(size[u], u);
  centroid[u] = par;
  for (int v : g[u]) {
    g[v].erase(u);
    buildCentroid(v, u);
  }
}

void add(int v) {
  for (int u = v; u; u = centroid[u]) {
    ii d = dist(u, v);
    bool flag = !mp[u].count(d.nd);
    int &x = (u != v ? mp[u][d.nd] : mp[u][0] = -1);
    if (flag) { x = -1; }
    if (d.st > x) {
      if (maxDis[u].count(x)) {
        maxDis[u].erase(maxDis[u].find(x));
      }
      x = d.st;
      maxDis[u].insert(x);
    }
    // debug(u, v, x, d, maxDis[u]);
    if (maxDis[u].size() > 2) {
      auto it = maxDis[u].end();
      maxDis[u].erase(--it);
    }
    assert(maxDis[u].size() <= 2);
    if (u <= v && maxDis[u].size() >= 2) {
      auto it = maxDis[u].begin();
      int r = *it;
      r += *++it;
      ans = max(ans, r);
    }
  }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    clear();

    cin >> n;
    for (int i = 2; i <= n; ++i) {
      int p;
      cin >> p;
      g[i].insert(p);
      g[p].insert(i);
    }

    dfs(1);
    buildLca();
    buildCentroid(1);

    add(1);
    for (int v = 2; v <= n; ++v) {
      add(v);
      cout << ans << '\n';
    }
    debug();
  }

  return 0;
}
