#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n;
int dis[maxn];
int p[maxn];
set<int> g[maxn];

int bfs(int s) {
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  p[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dis[v] == -1) {
        dis[v] = 1 + dis[u];
        p[v] = u;
        q.push(v);
      }
    }
  }
  int d = -1;
  int ans = 0;
  for (int u = 1; u <= n; ++u) {
    if (dis[u] > d) {
      d = dis[u];
      ans = u;
    }
  }
  return ans;
}

void rec(int v, int u) {
  if (u != v) {
    g[p[v]].erase(v);
    g[v].erase(p[v]);
    rec(p[v], u);
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  int u = bfs(1);
  while (!g[u].empty()) {
    int v = bfs(u);
    cout << "? " << u << ' ' << v << endl;
    int r;
    cin >> r;
    if (r == -1) return 0;
    rec(v, u);
    u = bfs(r);
  }
  cout << "! " << u << endl;
  return 0;
}
