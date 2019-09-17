int dis[maxn];
vector<ii> g[maxn];

void dijkstra(int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dis[u]) continue;
    for (auto [v, w] : g[u]) {
      if (d + w < dis[v]) {
        dis[v] = d + w;
        pq.emplace(dis[v], v);
      }
    }
  }
}
