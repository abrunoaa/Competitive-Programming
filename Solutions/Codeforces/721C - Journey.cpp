#include <bits/stdc++.h>
using namespace std;

#define maxn 5010
#define inf 0x3f3f3f3f
#define st first
#define nd second

typedef pair<int, int> ii;
typedef pair<int, ii> tri;

int n, m, t, p[maxn][maxn], dist[maxn][maxn];
vector<ii> g[maxn];

struct Cmp {
  bool operator () (const tri &x, const tri &y) const {
    return !(x.nd.st < y.nd.st);
  }
};

void dijkstra() {
  memset(p, -1, sizeof p);
  p[1][1] = 1;
  memset(dist, inf, sizeof dist);
  dist[1][1] = 0;
  priority_queue<tri, vector<tri>, Cmp> pq;
  pq.push(tri(1, ii(0, 1)));

  while (!pq.empty()) {
    tri top = pq.top();
    pq.pop();

    int vis = top.st;
    int d = top.nd.st;
    int u = top.nd.nd;

    if (d > dist[u][vis]) { continue; }

    // cerr << " >> " << u << ' ' << vis << ' ' << d << endl;

    for (ii v : g[u]) {
      if (d + v.nd <= t && d + v.nd < dist[v.st][vis + 1]) {
        dist[v.st][vis + 1] = d + v.nd;
        p[v.st][vis + 1] = u;
        pq.push(tri(vis + 1, ii(d + v.nd, v.st)));
      }
    }
  }
}

void print(int u, int v) {
  if (u != 1) {
    print(p[u][v], v - 1);
    cout << ' ';
  }
  cout << u;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m >> t;
  while (m--) {
    int u, v, ti;
    cin >> u >> v >> ti;
    g[u].push_back(ii(v, ti));
  }
  dijkstra();
  int v;
  for (v = n; dist[n][v] > t; --v);
  cout << v << '\n';
  print(n, v);
  cout << '\n';

  return 0;
}
