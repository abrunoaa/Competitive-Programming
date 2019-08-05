#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxn 201
#define inf 0x3f3f3f3f3f3f3f3f

typedef long long ll;

bool vis[maxn];
int N, M;
int p[maxn];
ll flow[maxn][maxn];
vector<int> g[maxn];

bool bfs(int source, int sink) {
  memset(vis, 0, sizeof vis);
  vis[source] = 1;
  queue<int> q;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)g[u].size(); ++i) {
      int v = g[u][i];
      if (!vis[v] && flow[u][v]) {
        p[v] = u;
        if (v == sink) { return 1; }
        q.push(v);
        vis[v] = 1;
      }
    }
  }

  return 0;
}

ll maxflow(int source, int sink) {
  ll mf = 0;
  while (bfs(source, sink)) {
    ll f = inf;
    for (int u = sink; u != source; u = p[u]) {
      f = min(f, flow[p[u]][u]);
    }
    for (int u = sink; u != source; u = p[u]) {
      flow[p[u]][u] -= f;
      flow[u][p[u]] += f;
    }
    mf += f;
  }

  return mf;
}

int main() {
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> M) {
    memset(flow, 0, sizeof flow);
    for (int i = 0; i < M; ++i) { g[i].clear(); }

    for (int i = 0, S, E, I; i < N; ++i) {
      cin >> S >> E >> I, --S, --E;
      flow[S][E] += I;

      g[S].push_back(E);
      g[E].push_back(S);
    }

    cout << maxflow(0, M - 1) << '\n';
  }

  return 0;
}
