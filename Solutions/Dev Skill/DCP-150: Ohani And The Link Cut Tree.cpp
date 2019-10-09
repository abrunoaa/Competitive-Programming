#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int> ii;

const int maxn = (int)1e5 + 3;

bool del[maxn];
int dis[maxn], p[maxn], x[maxn], y[maxn], par[maxn];
vector<ii> g[maxn];

void bfs(int s) {
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto neig : g[u]) {
      int v, w;
      tie(v, w) = neig;
      if (dis[v] == -1) {
        dis[v] = dis[u] + w;
        q.push(v);
      }
    }
  }
}

int find(int u) {
  return (u == p[u] ? u : p[u] = find(p[u]));
}

void unite(int u, int v) {
  u = find(u);
  v = find(v);
  if (dis[u] < dis[v]) {
    swap(u, v);
  }
  p[u] = v;
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> par[i];
  }
  for (int i = 2; i <= n; ++i) {
    int w;
    cin >> w;
    g[par[i]].emplace_back(i, w);
  }
  bfs(1);
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
  int q;
  cin >> q;
  for (int u = 0; u < q; ++u) {
    cin >> x[u] >> y[u];
    if (x[u] == 1) {
      del[y[u]] = 1;
    }
  }
  for (int u = 2; u <= n; ++u) {
    if (!del[u]) {
      unite(u, par[u]);
    }
  }
  deque<ii> ans;
  for (int i = q - 1; i >= 0; --i) {
    if (x[i] == 1) {
      unite(y[i], par[y[i]]);
    } else {
      int p = find(y[i]);
      ans.emplace_front(p, dis[y[i]] - dis[p]);
    }
  }
  for (auto p : ans) {
    int a, b;
    tie(a, b) = p;
    cout << a << ' ' << b << '\n';
  }
  return 0;
}
