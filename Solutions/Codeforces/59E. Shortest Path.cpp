#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int,int> ii;

const int maxn = 3003;

int n;
int dis[maxn][maxn];
ii p[maxn][maxn];
vector<int> g[maxn];
set<tuple<int,int,int>> forbidden;

void rec(int u, int v) {
  if (v == 1) {
    cout << v;
  } else {
    auto [a, b] = p[u][v];
    rec(a, b);
    cout << ' ' << v;
  }
}

void bfs() {
  queue<ii> q;
  q.push({0, 1});
  memset(dis, 63, sizeof(dis));
  dis[0][1] = 0;
  p[0][1] = {0, 0};
  while (!q.empty()) {
    auto [w, u] = q.front();
    q.pop();
    for (int v : g[u]) {
      if (!forbidden.count({w, u, v}) && dis[w][u] + 1 < dis[u][v]) {
        dis[u][v] = dis[w][u] + 1;
        p[u][v] = {w, u};
        q.push({u, v});
        if (v == n) {
          cout << dis[u][v] << '\n';
          rec(u, v);
          cout << '\n';
          return;
        }
      }
    }
  }
  cout << "-1\n";
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m, k;
  cin >> n >> m >> k;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  while (k--) {
    int a, b, c;
    cin >> a >> b >> c;
    forbidden.insert({a, b, c});
  }
  bfs();
  return 0;
}
