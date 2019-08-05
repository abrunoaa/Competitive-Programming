// g++ -std=c++11 -o "%e" "%f" -fsanitize=address -fno-omit-frame-pointer -DBALLOONFIELD -Wall -Wextra -Wfloat-equal -Wconversion -Winline -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference

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

#define maxn 100003
#define maxs (600 * maxn)

typedef long long ll;

#define M ((l + r) / 2)

int n, m, cur;
int nroot, root[maxn], numst, lc[maxs], rc[maxs], lz_b[maxs];
ll st[maxs], lz_a[maxs];
int cnt, pos[maxn], head[maxn], size[maxn], depth[maxn], p[maxn];
ll lastans;
vector<int> g[maxn];

void dfs(int u = 1, int par = 0) {
  p[u] = par;
  depth[u] = depth[par] + 1;
  size[u] = 1;
  for (int v : g[u]) if (v != par) {
      dfs(v, u);
      size[u] += size[v];
    }
}

void hld(int h = 1, int u = 1, int par = 0) {
  head[u] = h;
  pos[u] = cnt;
  ++cnt;
  int pref = 0;
  for (int v : g[u])
    if (size[v] > size[pref] && v != par) {
      pref = v;
    }
  if (pref) { hld(h, pref, u); }
  for (int v : g[u])
    if (v != pref && v != par) {
      hld(v, v, u);
    }
}

int dist(int x, int y) {
  int d = 0;
  while (head[x] != head[y]) {
    if (depth[head[x]] < depth[head[y]]) { swap(x, y); }
    d += depth[x] - depth[head[x]] + 1;
    x = p[head[x]];
  }
  d += abs(depth[x] - depth[y]);
  return d;
}

void build(int &t, int l = 0, int r = n - 1) {
  t = numst++;
  st[t] = 0;
  lz_a[t] = 0;
  lz_b[t] = 0;
  if (l < r) {
    build(lc[t], l, M);
    build(rc[t], M + 1, r);
  }
}

int &copy(int &t) {
  int u = numst++;
  lc[u] = lc[t];
  rc[u] = rc[t];
  st[u] = st[t];
  lz_a[u] = lz_a[t];
  lz_b[u] = lz_b[t];
  return t = u;
}

void prop(int &t, int l, int r) {
  int n = r - l + 1;
  st[t] += (ll)lz_a[t] * n + (ll)lz_b[t] * (n - 1) * n / 2;
  if (l != r) {
    copy(lc[t]);
    lz_a[lc[t]] += lz_a[t];
    lz_b[lc[t]] += lz_b[t];
    copy(rc[t]);
    lz_a[rc[t]] += lz_a[t] + (ll)(M - l + 1) * lz_b[t];
    lz_b[rc[t]] += lz_b[t];
  }
  lz_a[t] = 0;
  lz_b[t] = 0;
}

ll upd(int i, int j, ll a, int b, int &t, int l = 0, int r = n - 1) {
  copy(t);
  if (i <= l && r <= j) {
    lz_a[t] += a;
    lz_b[t] += b;
    prop(t, l, r);
    return st[t];
  }
  if (lz_a[t] || lz_b[t]) { prop(t, l, r); }
  if (r < i || j < l) { return st[t]; }
  return st[t] = upd(i, j, a, b, lc[t], l, M) + upd(i, j, a + (ll)max(0, M - max(i, l) + 1) * b, b, rc[t], M + 1, r);
}

ll qry(int i, int j, int &t, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return 0; }
  if (lz_a[t] || lz_b[t]) { prop(copy(t), l, r); }
  if (i <= l && r <= j) { return st[t]; }
  return qry(i, j, lc[t], l, M) + qry(i, j, rc[t], M + 1, r);
}

void change(int x, int y, int a, int b) {
  ++nroot;
  root[nroot] = root[cur];
  cur = nroot;
  int k = 0;
  while (head[x] != head[y]) {
    if (depth[head[x]] > depth[head[y]]) {
      k += depth[x] - depth[head[x]] + 1;
      upd(pos[head[x]], pos[x], a + (ll)b * (k - 1), -b, root[cur]);
      x = p[head[x]];
    } else {
      upd(pos[head[y]], pos[y], a + (ll)b * (k + dist(head[y], x)), b, root[cur]);
      y = p[head[y]];
    }
  }
  if (depth[x] > depth[y]) {
    k += depth[x] - depth[y];
    upd(pos[y], pos[x], a + (ll)b * k, -b, root[cur]);
  } else {
    upd(pos[x], pos[y], a + (ll)b * k, b, root[cur]);
  }
}

ll query(int x, int y) {
  ll ans = 0;
  while (head[x] != head[y]) {
    if (depth[head[x]] < depth[head[y]]) { swap(x, y); }
    ans += qry(pos[head[x]], pos[x], root[cur]);
    x = p[head[x]];
  }
  if (pos[x] > pos[y]) { swap(x, y); }
  ans += qry(pos[x], pos[y], root[cur]);
  return ans;
}

int main() {
  freopen("in", "r", stdin);
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs();
  hld();
  build(root[0]);

  while (m--) {
    char type;
    int x;
    cin >> type >> x;

    if (type == 'l') {
      x = (int)((x + lastans) % (nroot + 1));
      cur = x;
    } else {
      int y;
      cin >> y;
      x = (int)((x + lastans) % n) + 1;
      y = (int)((y + lastans) % n) + 1;
      if (type == 'q') {
        lastans = query(x, y);
        cout << lastans << '\n';
      } else {
        int a, b;
        cin >> a >> b;
        change(x, y, a, b);
      }
    }
  }

  return 0;
}
