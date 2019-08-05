#include <bits/stdc++.h>
using namespace std;

#define maxn 400010
#define pb push_back
#define E (2 * no)
#define D (E + 1)
#define M ((e + d) / 2)

typedef long long ll;

int cnt = -1, c[maxn], in[maxn], out[maxn], tree[maxn];
ll st[4 * maxn], lazy[4 * maxn] = {};
vector<int> g[maxn];

void buildg(int u, int p) {
  in[u] = ++cnt;
  tree[cnt] = u;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i];
    if (v != p) { buildg(v, u); }
  }
  out[u] = cnt;
}

ll buildst(int no, int e, int d) {
  if (e == d) { return st[no] = (1LL << c[tree[e]]); }
  return st[no] = buildst(E, e, M) | buildst(D, M + 1, d);
}

void prop(int no) {
  if (lazy[no]) {
    st[E] = st[D] = lazy[E] = lazy[D] = lazy[no];
    lazy[no] = 0;
  }
}

ll upd(int v, int i, int j, int no, int e, int d) {
  if (d < i || j < e) { return st[no]; }
  if (e >= i && j >= d) { return st[no] = lazy[no] = (1LL << v); }
  prop(no);
  return st[no] = upd(v, i, j, E, e, M) | upd(v, i, j, D, M + 1, d);
}

ll qry(int i, int j, int no, int e, int d) {
  if (d < i || j < e) { return 0LL; }
  if (e >= i && j >= d) { return st[no]; }
  prop(no);
  return qry(i, j, E, e, M) | qry(i, j, D, M + 1, d);
}

int main() {
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) { cin >> c[i], --c[i]; }

  for (int i = 0, u, v; i < n - 1; ++i) {
    cin >> u >> v, --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }

  buildg(0, -1);
  buildst(1, 0, n - 1);

  for (int i = 0, t, v, c; i < m; ++i) {
    cin >> t >> v, --v;
    if (t == 1) {
      cin >> c, --c;
      upd(c, in[v], out[v], 1, 0, n - 1);
    } else {
      cout << __builtin_popcountll(qry(in[v], out[v], 1, 0, n - 1)) << '\n';
    }
  }

  return 0;
}
