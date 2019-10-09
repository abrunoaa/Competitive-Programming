#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int maxn = (int)2e3 + 3;  // n = número de vértices do lado esquerdo
const int maxm = (int)2e3 + 3;  // m = número de vértices do lado direito
const int inf = 0x3f3f3f3f;
const int nil = 0;              // supõe que o grafo é indexado em 1

int n, m, dist[maxn + maxm], match[maxn + maxm];
vector<int> g[maxn + maxm];     // nil + g[1 .. n] + g[n+1 .. n+m]

// Hopcroft-Karp O(E sqrt(V)): maximum cardinality matching on a bipartite graph
bool bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (match[i] == nil) {
      dist[i] = 0;
      q.push(i);
    } else {
      dist[i] = inf;
    }
  }
  dist[nil] = inf;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {                // *** g[nil] está vazio! ***
      if (dist[match[v]] == inf) {
        dist[match[v]] = dist[u] + 1;
        q.push(match[v]);
      }
    }
  }
  return dist[nil] != inf;
}

bool dfs(int u) {
  if (u == nil) return true;
  for (int v : g[u]) {
    if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  dist[u] = inf;
  return false;
}

int hopcroft_karp() {
  for (int u = 1; u <= n + m; ++u)
    match[u] = nil;
  int matching = 0;
  while (bfs())
    for (int u = 1; u <= n; ++u)
      if (match[u] == nil && dfs(u))
        ++matching;
  return matching;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int np;
  while (cin >> np) {
    for (int i = 1; i <= np; ++i) {
      g[i].clear();
    }
    n = m = 0;
    map<ii,int> mp;
    while (np--) {
      int x, y;
      cin >> x >> y;
      bool odd = (x + y) % 2;
      int &u = mp[{x, y}] = (odd ? ++n : ++m);
      for (int i = 0; i < 4; ++i) {
        static int X[] = {0,0,1,-1};
        static int Y[] = {1,-1,0,0};
        int dx = x + X[i];
        int dy = y + Y[i];
        if (mp.count({dx, dy})) {
          int v = mp[{dx, dy}];
          if (odd) {
            g[u].push_back(v);
          } else {
            g[v].push_back(u);
          }
        }
      }
    }
    for (int u = 1; u <= n; ++u) {
      for (int &v : g[u]) {
        v += n;
      }
    }
    cout << n + m - hopcroft_karp() << '\n';
  }
  return 0;
}
