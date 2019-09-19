#include <bits/stdc++.h>
using namespace std;

const int maxn = 2003;

int dis[maxn];
vector<int> g[maxn];

int bfs(int s) {
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (v == s) {
        return dis[u] + 1;
      }
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      int h;
      cin >> h;
      if (h == 1) {
        g[u].push_back(v);
      }
    }
  }
  for (int u = 0; u < n; ++u) {
    int ans = bfs(u);
    if (ans == -1) {
      cout << "NO WAY" << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
