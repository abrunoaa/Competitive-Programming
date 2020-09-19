void bfs(int s) {
  deque<int> q;
  q.push_back(s);
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (auto [v, w] : g[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        w == 0 ? q.push_front(v) : q.push_back(v);
      }
    }
  }
}
