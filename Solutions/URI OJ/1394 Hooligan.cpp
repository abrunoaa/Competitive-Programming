#include <bits/stdc++.h>
using namespace std;

#define maxn 45
#define maxv 2000
#define inf 0x3f3f3f3f
#define pb push_back

int N, M, G, pontos[maxn], partidas[maxn][maxn];
bool vis[maxv];
int pai[maxv], fluxo[maxv][maxv];
vector<int> g[maxv];

bool bfs(int so, int si) {
  memset(vis, 0, sizeof vis);

  queue<int> q;
  q.push(so);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < (int)g[u].size(); ++i) {
      int v = g[u][i];
      if (!vis[v] && fluxo[u][v] > 0) {
        pai[v] = u;
        if (v == si) { return 1; }
        vis[v] = 1;
        q.push(v);
      }
    }
  }

  return 0;
}

int maxflow(int so, int si) {
  int mf = 0;

  while (bfs(so, si)) {
    int f = inf;
    for (int u = si; u != so; u = pai[u]) {
      f = min(f, fluxo[pai[u]][u]);
    }
    for (int u = si; u != so; u = pai[u]) {
      fluxo[pai[u]][u] -= f;
      fluxo[u][pai[u]] += f;
    }
    mf += f;
  }

  return mf;
}

inline void add(int u, int v, int f) {
  g[u].pb(v);
  g[v].pb(u);
  fluxo[u][v] = f;
}

int main() {
  // freopen("br", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> M >> G && (N || M || G)) {
    memset(pontos, 0, sizeof pontos);
    memset(partidas, 0, sizeof partidas);
    memset(fluxo, 0, sizeof fluxo);
    for (int i = 0; i < maxv; ++i) { g[i].clear(); }

    while (G--) {
      char c;
      int i, j;
      cin >> i >> c >> j;
      ++partidas[i][j], ++partidas[j][i];
      if (c == '<') {
        pontos[j] += 2;
      } else {
        ++pontos[i];
        ++pontos[j];
      }
    }

    // processa o time 0
    for (int i = 1; i < N; ++i) { pontos[0] += 2 * (M - partidas[0][i]); }

    // processa os outros
    int total = 0;                      // total de partidas
    int part = N + 2;                   // vértices de partidas
    for (int i = 1; i < N; ++i)
      for (int j = i + 1; j < N; ++j) {
        int p = M - partidas[i][j];
        if (p) {
          add(0, part, 2 * p);
          add(part, i + 1, 2 * p);
          add(part, j + 1, 2 * p);
          total += p;
          ++part;
        }
      }

    // liga no sink com o máximo que cada time pode fazer
    bool flag = 0;
    for (int i = 1; i < N; ++i) {
      if (pontos[i] >= pontos[0]) {
        flag = 1;
        break;
      }
      add(i + 1, 1, pontos[0] - pontos[i] - 1);
    }

    cout << (!flag && maxflow(0, 1) == 2 * total ? 'Y' : 'N') << '\n';
  }

  return 0;
}
