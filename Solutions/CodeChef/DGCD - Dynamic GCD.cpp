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

#define maxn 50003
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)
#define gcd __gcd

struct Node { int first, last, dif, lazy; };

int n, q, v[maxn];
int pt, size[maxn], head[maxn], pos[maxn], val[maxn], depth[maxn], p[maxn];
vector<int> g[maxn];
Node st[4 * maxn];

void dfs(int u = 0, int par = -1) {
  p[u] = par;
  size[u] = 1;
  for (int v : g[u]) if (v != par) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
      size[u] += size[v];
    }
}

void hld(int u = 0, int h = 0, int par = -1) {
  head[u] = h;
  pos[u] = pt;
  val[pt] = v[u];
  ++pt;
  int pref = -1;
  for (int v : g[u])
    if ((pref == -1 || size[v] > size[pref]) && v != par) {
      pref = v;
    }
  if (pref != -1) { hld(pref, h, u); }
  for (int v : g[u])
    if (v != par && v != pref) {
      hld(v, v, u);
    }
}

Node merge(const Node &x, const Node &y) {
  return { x.first, y.last, gcd(abs(y.first - x.last), gcd(x.dif, y.dif)), 0 };
}

Node &buildSt(int t = 1, int l = 0, int r = n - 1) {
  if (l == r) return st[t] = { val[l], val[l], 0, 0 };
  return st[t] = merge(buildSt(L, l, M), buildSt(R, M + 1, r));
}

void apply(int t, int x) {
  st[t].first += x;
  st[t].last += x;
  st[t].lazy += x;
}

void prop(int t, int n) {
  int &x = st[t].lazy;
  if (x) {
    if (n > 1) {
      apply(L, x);
      apply(R, x);
    }
    x = 0;
  }
}

Node &upd(int i, int j, int x, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return st[t]; }
  if (i <= l && r <= j) {
    apply(t, x);
    return st[t];
  }
  prop(t, r - l + 1);
  return st[t] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M + 1, r));
}

int qry(int i, int j, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) { return gcd(st[t].first, st[t].dif); }
  prop(t, r - l + 1);
  return gcd(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

void change(int u, int v, int d) {
  while (head[u] != head[v]) {
    if (depth[head[u]] < depth[head[v]]) { swap(u, v); }
    int h = head[u];
    upd(pos[h], pos[u], d);
    u = p[h];
  }
  if (pos[u] < pos[v]) { swap(u, v); }
  upd(pos[v], pos[u], d);
}

int find(int u, int v) {
  int ans = 0;
  while (head[u] != head[v]) {
    if (depth[head[u]] < depth[head[v]]) { swap(u, v); }
    int h = head[u];
    ans = gcd(ans, qry(pos[h], pos[u]));
    u = p[h];
  }
  if (pos[u] < pos[v]) { swap(u, v); }
  ans = gcd(ans, qry(pos[v], pos[u]));
  return ans;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) { cin >> v[i]; }

  dfs();
  hld();
  buildSt();

  cin >> q;
  while (q--) {
    char op;
    int u, v, d;
    cin >> op >> u >> v;
    if (op == 'C') {
      cin >> d;
      change(u, v, d);
    } else {
      cout << find(u, v) << '\n';
    }
  }

  return 0;
}
