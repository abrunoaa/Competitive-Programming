// https://codeforces.com/blog/entry/43230

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;
const int maxq = 100003;

/** begin *********************************************************************/
struct Qry { int i, j, w, id; };

int n, m;
vector<int> g[maxn];
Qry q[maxq];
int cur, ans[maxn];
int cnt, in[maxn], out[maxn], order[2 * maxn];
bool used[maxn];

void dfs(int u = 1, int p = 0) {
  in[u] = cnt;
  order[cnt] = u;
  ++cnt;
  for (int v : g[u]) if (v != p)
    dfs(v, u);
  out[u] = cnt;
  order[cnt] = u;
  ++cnt;
}

void buildLca();    // Lowest Common Ancestor
int lca(int, int);

void update(int u) {
  u = order[u];     // get node from index
  if ((used[u] ^= 1)) {
    // insert u in the answer
  } else {
    // remove u from the answer
  }
}

void mo() {
  int bs = (int)sqrt(2 * n);
  sort(q, q + m, [bs](const Qry& x, const Qry& y) {
    int bx = x.i / bs, by = y.i / bs;
    if (bx != by) return bx < by;
    return bx % 2 == 0 ? x.j < y.j : x.j > y.j;
  });
  int l = 0, r = -1;
  for (int k = 0; k < m; ++k) {
    auto [i, j, w, id] = q[k];
    while (r < j) update(++r);
    while (r > j) update(r--);
    while (l < i) update(l++);
    while (l > i) update(--l);
    if (w != -1) update(w);
    ans[id] = cur;
    if (w != -1) update(w);
  }
}

void solve() {
  cin >> n >> m;
  // read another info*
  for(int i = 1; i < n; ++i) { // read tree
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs();
  buildLca();
  for (int i = 0; i < m; ++i) { // read queries
    int u, v;
    cin >> u >> v;
    int w = lca(u, v);
    if (in[u] > in[v]) swap(u, v);
    if (w == u) q[i] = { in[u], in[v], -1, i }; // corner case
    else q[i] = { out[u], in[v], in[w], i };
  }
  mo();
  for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}
/** end ***********************************************************************/

int main() {
  return 0;
}
