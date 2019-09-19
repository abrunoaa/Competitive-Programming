#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int inf = 0x3f3f3f3f;
const int maxn = 103;

int dis[maxn];
vector<ii> g[maxn];

void dijkstra(int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  priority_queue<ii,vector<ii>,greater<ii>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dis[u]) continue;
    for (auto [v, w] : g[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, e, timer, m;
  cin >> n >> e >> timer >> m;
  for (int u = 1; u <= n; ++u) {
    g[u].clear();
  }
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    g[b].push_back({a, w});
  }
  dijkstra(e);
  int ans = 0;
  for (int u = 1; u <= n; ++u) {
    if (dis[u] <= timer) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
