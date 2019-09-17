#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int maxn = 5003;

int n, m, k = 1;
int vis[maxn], ans[maxn];
vector<ii> g[maxn];

void dfs(int u) {
  vis[u] = 1;
  for (auto [v, p] : g[u]) {
    ans[p] = 1;
    if (vis[v] == 0) {
      dfs(v);
    } else if (vis[v] == 1) {
      ans[p] = 2;
      k = 2;
    }
  }
  vis[u] = 2;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
  }
  for (int u = 1; u <= n; ++u) {
    if (vis[u] == 0) {
      dfs(u);
    }
  }
  cout << k << '\n';
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
