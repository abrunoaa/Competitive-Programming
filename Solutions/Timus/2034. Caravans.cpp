#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int n, m;
int ds[maxn], df[maxn], dr[maxn], possible[maxn];
vector<int> g[maxn];

void bfs(int s, int* dis) {
  memset(dis, -1, n * sizeof(*dis));
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
}

int calc(int s, int f, int r) {
  bfs(s, ds);
  bfs(f, df);
  bfs(r, dr);
  for (int u = 0; u < n; ++u) {
    if (ds[u] + df[u] == ds[f]) {
      int &p = possible[ds[u]];
      p = max(p, dr[u]);
    }
  }
  int ans = min(dr[s], dr[f]);
  for (int d = 1; d < ds[f]; ++d) {
    ans = min(ans, possible[d]);
  }
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s, f, r;
  cin >> s >> f >> r;
  --s, --f, --r;
  cout << calc(s, f, r) << '\n';
  return 0;
}
