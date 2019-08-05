#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define putc(c) putc((c), stdout)

struct IO {
  char cur, buf[100];
  IO() : cur(' ') {}

  inline operator bool() { return cur; }

  inline char readc() { return cur = (char)getc(stdin); }
  inline static bool isblank(char c) { return c <= ' '; }
  inline static bool isdigit(char c) { return c <= '9' && c >= '0'; }
  inline void skipBlanks() { while (isblank(cur)) readc(); }

  inline IO &operator >> (char &c) { skipBlanks(); c = cur; readc(); return *this; }

  inline IO &operator >> (char* s) {
    skipBlanks();
    while (*s++ = cur, !isblank(readc()));
    *s = 0;
    return *this;
  }

  inline IO &operator >> (string &s) {
    s.clear();
    skipBlanks();
    while (s.push_back(cur), !isblank(readc()));
    return *this;
  }

  inline IO &operator >> (double &d) { *this >> buf; sscanf(buf, "%lf", &d); return *this; }
  inline IO &operator >> (long double &d) { *this >> buf; sscanf(buf, "%Lf", &d); return *this; }

  template<class intType>
  inline IO &operator >> (intType &n) {
    skipBlanks();
    int sign = +1;
    if (cur == '-') { sign = -1, readc(); }
    else if (cur == '+') { readc(); }
    n = cur - '0';
    while (isdigit(readc())) { n += n + (n << 3) + cur - '0'; }
    n *= sign;
    return *this;
  }

  inline IO &operator << (bool x) { putc((x ? '1' : '0')); return *this; }
  inline IO &operator << (char c) { putc(c); return *this; }
  inline IO &operator << (char* s) { while (*s) putc(*s++); return *this; }
  inline IO &operator << (const char* s) { while (*s) putc(*s++); return *this; }
  inline IO &operator << (const string &s) { return *this << s.data(); }

  inline char* toString(double d) { sprintf(buf, "%.9lf%c", d, '\0'); return buf; }
  inline char* toString(long double d) { sprintf(buf, "%.9Lf%c", d, '\0'); return buf; }

  template<class intType>
  inline char* toString(intType n) {
    char* p = buf + sizeof(buf) - 1;
    *p = 0;
    if (!n) { *--p = '0'; }
    else {
      bool neg;
      if ((neg = n < 0)) { n = -n; }
      while (n) { *--p = (char)(n % 10 + '0'), n /= 10; }
      if (neg) { *--p = '-'; }
    }
    return p;
  }

  template<class T> inline IO &operator << (T x) { return *this << toString(x); }

  inline void sync_with_stdio(bool) {}
  inline void tie(void*) {}
};

static IO __io__;

#define endl '\n'
#define cout __io__
#define cin __io__

template<class A, class B>ostream &operator<<(ostream &f, const pair<A, B> &x) {return f << '(' << x.first << ", " << x.second << ')';}

#define PRINT int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';
template<class T>ostream &operator<<(ostream &f, const vector<T> &x) {PRINT;}
template<class T, class C>ostream &operator<<(ostream &f, const set<T, C> &x) {PRINT;}
template<class T, class C>ostream &operator<<(ostream &f, const multiset<T, C> &x) {PRINT;}
template<class K, class T, class C>ostream &operator<<(ostream &f, const map<K, T, C> &x) {PRINT;}
template<class K, class T, class C>ostream &operator<<(ostream &f, const multimap<K, T, C> &x) {PRINT;}

#define PRINT2(funcGet,funcPop) int b=0;f<<'[';while(!x.empty()){if(b++)f<<", ";f<<x.funcGet();x.funcPop();}return f<<']';
template<class T>ostream &operator<<(ostream &f, queue<T>x) {PRINT2(front, pop)}
template<class T>ostream &operator<<(ostream &f, stack<T>x) {PRINT2(top, pop)}
template<class T, class V, class C>ostream &operator<<(ostream &f, priority_queue<T, V, C>x) {PRINT2(top, pop)}

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

bool white[maxn];
int n, ans[maxn];
vector<ii> g[maxn];
multiset<int, greater<int>> maxAns, maxSt[maxn];
unordered_map<int, multiset<int, greater<int>>> st[maxn];

/// centroid
bool isc[maxn];
int centroid[maxn], size[maxn];

void dfsCentroid(int u, int p = 0) {
  size[u] = 1;
  for (auto v : g[u]) if (v.st != p && !isc[v.st]) {
      dfsCentroid(v.st, u);
      size[u] += size[v.st];
    }
}

int findCentroid(int u, int p, int n) {
  for (auto v : g[u])
    if (size[v.st] > n / 2 && !isc[v.st] && v.st != p) {
      return findCentroid(v.st, u, n);
    }
  return u;
}

int buildCentroid(int start) {
  dfsCentroid(start);
  int u = findCentroid(start, -1, size[start]);
  isc[u] = 1;
  for (auto v : g[u]) if (!isc[v.st]) {
      int w = buildCentroid(v.st);
      centroid[w] = u;
    }
  g[u].clear();
  return u;
}

/// LCA
int depth[maxn], p[maxl][maxn], dist[maxl][maxn];

void dfsLca(int u, int p = 0, int d = 0) {
  ::p[0][u] = p;
  depth[u] = d;
  for (auto v : g[u]) if (v.st != p) {
      dist[0][v.st] = v.nd;
      dfsLca(v.st, u, d + 1);
    }
}

inline void buildLca() {
  dist[0][1] = 0;
  dfsLca(1);
  for (int i = 1; i < maxl; ++i) {
    for (int u = 1; u <= n; ++u) {
      int v = p[i - 1][u];
      p[i][u] = p[i - 1][v];
      dist[i][u] = dist[i - 1][u] + dist[i - 1][v];
    }
  }
}

inline ii calcDist(int u, int v) {
  bool swaped = depth[u] < depth[v];
  if (swaped) { swap(u, v); }
  int last = u;
  int dif = depth[u] - depth[v];
  int d = 0;
  for (int i = maxl - 1; i >= 0; --i) {
    if (dif & (1 << i)) {
      d += dist[i][u];
      u = p[i][u];
    }
  }
  if (u == v) {
    if (swaped) { return ii(d, p[0][last]); }
    --dif;
    for (int i = maxl - 1; i >= 0; --i)
      if (dif & (1 << i)) {
        last = p[i][last];
      }
    return ii(d, last);
  }
  for (int i = maxl - 1; i >= 0; --i) {
    if (p[i][u] != p[i][v]) {
      d += dist[i][u];
      d += dist[i][v];
      u = p[i][u];
      v = p[i][v];
    }
  }
  d += dist[0][u];
  d += dist[0][v];
  return ii(d, swaped ? u : v);
}

inline void updateAns(int u) {
  // debug(u, ans[u], maxAns);
  // assert(maxAns.count(ans[u]));
  maxAns.erase(maxAns.find(ans[u]));
  auto &s = maxSt[u];
  // debug(u, s.size());
  if (s.empty()) {
    ans[u] = -!white[u];
  } else {
    auto it = s.begin();
    int a = *it;
    int b = s.size() == 1 ? -inf : *++it;
    ans[u] = max(-1, a + b);
    if (white[u]) {
      ans[u] = max(ans[u], a);
    }
  }
  maxAns.insert(ans[u]);
}

inline void change(int node) {
  // debug("change", node, white[node]);
  white[node] ^= 1;
  int u = node;
  while (u) {
    ii d = calcDist(node, u);
    // debug(node, u, d);
    auto &s = st[u][d.nd];
    auto &ms = maxSt[u];
    if (!s.empty()) {
      // assert(ms.count(*s.begin()));
      ms.erase(ms.find(*s.begin()));
    }
    if (white[node]) {
      s.insert(d.st);
    } else {
      // assert(s.count(d.st));
      s.erase(s.find(d.st));
    }
    if (!s.empty()) {
      ms.insert(*s.begin());
    }
    updateAns(u);
    // debug(d, ans[u], st[u]);
    u = centroid[u];
  }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  buildLca();
  buildCentroid(1);

  memset(ans, -1, sizeof ans);
  for (int u = 1; u <= n; ++u) {
    maxAns.insert(-1);
  }
  for (int u = 1; u <= n; ++u) {
    change(u);
    // debug(maxAns, vector<int>(ans + 1, ans + n + 1));
  }

  int q;
  cin >> q;
  while (q--) {
    // debug(maxAns, vector<int>(ans + 1, ans + n + 1));
    // assert((int)maxAns.size() == n);
    char op;
    cin >> op;
    if (op == 'A') {
      int x = *maxAns.begin();
      if (x == -1) {
        cout << "They have disappeared.\n";
      } else {
        cout << x << '\n';
      }
    } else {
      int a;
      cin >> a;
      change(a);
    }
  }

  return 0;
}
