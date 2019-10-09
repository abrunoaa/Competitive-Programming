#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 0x3f3f3f3f3f3f3f3f

const int maxn = 103;

int n, k, m;
int dis[maxn];
int g[maxn][maxn];

void floydWarshal() {
  for (int t = 0; t < n; ++t)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        g[i][j] = min(g[i][j], g[i][t] + g[t][j]);
}

bool can(int battery) {
  for (int s = 0; s < n; ++s) {
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 0; v < n; ++v) {
        if (g[u][v] <= battery && dis[v] == inf) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }
    for (int u = 0; u < n; ++u) {
      if (dis[u] > k) {
        return 0;
      }
    }
  }
  return 1;
}

int solve() {
  int l = 1, r = (int)1e18;
  while (l < r) {
    int battery = (l + r) / 2;
    if (can(battery)) {
      r = battery;
    } else {
      l = battery + 1;
    }
  }
  return l;
}

signed main() {
  assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(g, 63, sizeof(g));
    cin >> n >> k >> m;
    for (int u = 0; u < n; ++u) {
      g[u][u] = 0;
    }
    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u][v] = g[v][u] = w;
    }
    floydWarshal();
    cout << solve() << '\n';
  }
  return 0;
}
