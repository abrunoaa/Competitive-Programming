#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e6 + 3;

int vis[maxn];
int dis[maxn];
vector<int> g[maxn];

bool bfs(int s, int str) {
  if (vis[s] != -1) return 0;
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  vis[s] = s;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dis[u] == str) break;
    for (int v : g[u]) {
      if (vis[v] == s) continue;
      if (vis[v] != -1) return 0;
      vis[v] = s;
      dis[v] = dis[u] + 1;
      q.push(v);
    }
  }
  return 1;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, r, m;
    cin >> n >> r >> m;
    for (int u = 1; u <= n; ++u) {
      g[u].clear();
      vis[u] = -1;
    }
    while (r--) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    bool ans = 1;
    while (m--) {
      int k, s;
      cin >> k >> s;
      ans = ans && bfs(k, s);
    }
    for (int u = 1; ans && u <= n; ++u) {
      ans &= vis[u] != -1;
    }
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
