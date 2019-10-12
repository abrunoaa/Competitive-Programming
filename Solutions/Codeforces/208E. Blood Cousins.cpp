#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int maxn = (int)1e5 + 3;
const int maxl = (int)log2(maxn) + 1;

int n, r[maxl][maxn];
int ans[maxn];
vector<int> g[maxn];
vector<ii> qry[maxn];

void merge(auto &a, auto &b) {
  if (a.size() < b.size()) {
    swap(a, b);
  }
  for (auto [k, x] : b) {
    a[k] += x;
  }
}

map<int,int> dfs(int u, int depth) {
  map<int,int> d;
  for (int v : g[u]) {
    auto tmp = dfs(v, depth + 1);
    merge(d, tmp);
  }
  d[depth] = 1;
  for (auto [i, pi] : qry[u]) {
    ans[i] = d[depth + pi];
  }
  return move(d);
}

void build() {
  for (int k = 1; k < maxl; ++k) {
    for (int u = 1; u <= n; ++u) {
      int v = r[k - 1][u];
      r[k][u] = r[k - 1][v];
    }
  }
}

int find(int u, int p) {
  for (int k = 0; k < maxl; ++k) {
    if ((p >> k) & 1) {
      u = r[k][u];
    }
  }
  return u;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int u = 1; u <= n; ++u) {
    cin >> r[0][u];
    g[r[0][u]].push_back(u);
  }
  build();
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int v, p;
    cin >> v >> p;
    qry[find(v, p)].emplace_back(i, p);
  }
  for (int u = 1; u <= n; ++u) {
    if (!r[0][u]) {
      dfs(u, 1);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << max(0, ans[i] - 1) << ' ';
  }
  cout << '\n';
  return 0;
}
