/// Menor diâmetro de uma floresta

#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

char vis[maxn];
int n, m, dis[maxn];
vector<int> g[maxn];

// calcula o diametro do grafo
/// ==> diam DEVE começar com -1
void dfs(int u, int d, int cmp, int &vert, int &diam) {
  if (d > diam) {
    diam = d;
    vert = u;
  }

  vis[u] = 2;
  for (int v : g[u])
    if (vis[v] == cmp) {
      dfs(v, d + 1, cmp, vert, diam);
    }
  vis[u] = 1;
}

int minDiameterForest() {
  if (n == 1) { return 0; }
  if (n == 2) { return 1; }

  int k = 0;
  for (int u = 0; u < n; ++u) if (!vis[u]) {
      int v;
      int &d = dis[u] = -1;
      dfs(u, 0, 0, v, d);
      dfs(v, 0, 1, v, d);

      k = max(k, d);
      d = (d + 1) / 2;
    }

  sort(dis, dis + n, greater<int>());
  return max(k, max(dis[0] + dis[1] + 1, dis[1] + dis[2] + 2));
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << minDiameterForest() << '\n';

  return 0;
}
