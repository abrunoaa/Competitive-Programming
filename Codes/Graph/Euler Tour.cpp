set<int> g[maxn];   // multiset if multigraph

/* Euler tour exists iff degree[v] is even for all v.
 * Euler path exists iff degree[v] is even for all v except two of them.
 * Just connect them to vertex nil, and find the tour starting at nil.            */
vector<int> eulerTour(int source) {
  vector<int> cycle;
  stack<int,vector<int>> s;
  s.push(source);
  while (!s.empty()) {
    int u = s.top();
    if (g[u].empty()) {
      cycle.push_back(u);
      s.pop();
    } else {
      int v = *g[u].begin();
      g[u].erase(v);
      g[v].erase(u);
      s.push(v);
    }
  }
  return cycle;
}
