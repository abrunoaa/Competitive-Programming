#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = (int)1e5 + 3;

bool vis[maxn];
int ans;
vector<pair<int, int>> g[maxn];

bool isprime(int x) {
  if (x < 2) return 0;
  for (int p = 2; p * p <= x; ++p) {
    if (x % p == 0) {
      return 0;
    }
  }
  return 1;
}

int dfs(int u) {
  vis[u] = 1;
  int x1 = 0, x2 = 0;
  for (auto [v, w] : g[u]) {
    if (!vis[v]) {
      auto d = w + dfs(v);
      if (d > x1) {
        x2 = x1;
        x1 = d;
      } else if (d > x2) {
        x2 = d;
      }
    }
  }
  ans = max(ans, x1 + x2);
  return x1;
}

main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (isprime(w)) {
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
  }
  ans = 0;
  for (int u = 1; u <= n; ++u) {
    if (!vis[u]) {
      dfs(u);
    }
  }
  cout << ans << '\n';
  return 0;
}
