#include <bits/stdc++.h>
using namespace std;

const int maxn = 33;
const int maxm = 33;
const int inf = 0x3f3f3f3f;
const int nil = 0;  // supõe que o grafo é indexado em 1

int a[maxn][maxn];
int n, m, dist[maxn + maxm], match[maxn + maxm];
vector<int> g[maxn + maxm];

// Hopcroft-Karp O(E sqrt(V)): maximum cardinality matching on a bipartite graph
bool bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (match[i] == nil) {
      dist[i] = 0;
      q.push(i);
    }
    else {
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

bool can(int min) {
  for (auto &x : g) {
    x.clear();
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] >= min) {
        g[i].push_back(n + j);
      }
    }
  }
  m = n;
  return hopcroft_karp() == n;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  int i = 1, j = (int)1e6;
  while (i < j) {
    int mid = (i + j + 1) / 2;
    if (can(mid)) {
      i = mid;
    } else {
      j = mid - 1;
    }
  }
  cout << i << '\n';
  return 0;
}
