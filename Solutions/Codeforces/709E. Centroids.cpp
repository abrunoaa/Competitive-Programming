#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)4e5 + 3;

int n;
vector<int> g[maxn];
bool ans[maxn];
int branch[maxn];

int find(int u, int p) {
  int s = 1;
  bool ok = 1;
  for (int v : g[u]) {
    if (v != p) {
      int d = find(v, u);
      ok &= d <= n / 2;
      s += d;
    }
  }
  ok &= n - s <= n / 2;
  if (ok) throw u;
  return s;
}

int dfs(int u, int p) {
  int &s = branch[u] = 1;
  for (int v : g[u])
    if (v != p)
      s += dfs(v, u);
  return s;
}

void solve(int u, int p, int a, int b, bool bestBranch) {
  for (int v : g[u]) {
    if (v != p) {
      assert(branch[v] <= n / 2);
      solve(v, u, a, b, bestBranch || a == v);
    }
  }
  ans[u] = 1;
  if (n - branch[u] > n / 2) {
    int x = n - (branch[a] - (bestBranch ? branch[u] : 0)) - branch[u];
    x = min(x, n - branch[b] - branch[u]);
    ans[u] = x <= n / 2;
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  try {
    find(1, 0);
  } catch (int centroid) {
    dfs(centroid, 0);
    int a = 0, b = 0;
    for (int v : g[centroid]) {
      if (branch[v] > branch[a]) {
        b = a;
        a = v;
      } else if (branch[v] > branch[b]) {
        b = v;
      }
    }
    solve(centroid, 0, a, b, 0);
  }
  for (int u = 1; u <= n; ++u) {
    cout << ans[u] << ' ';
  }
  cout << '\n';
  return 0;
}
