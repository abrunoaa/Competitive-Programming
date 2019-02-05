#include <bits/stdc++.h>
using namespace std;

#define maxn 12
#define maxt 52
#define inf 0x3f3f3f3f
#define fst(x) x.first
#define snd(x) x.second.first
#define trd(x) x.second.second
#define mt(x, y, z) tri(x, ii(y, z))

typedef pair<int,int> ii;
typedef pair<int,ii> tri;

struct cmp { bool operator () (tri &x, tri &y) const { return trd(x) > trd(y); } };

int N, M, T, gasCost[maxn];
int dist[maxn][maxt];           // dist[i][j] = custo para chegar na cidade i com gas = j
vector<ii> g[maxn];

int dijkstra()
{
  int ans = inf;
  priority_queue<tri,vector<tri>,cmp> pq;
  pq.push(mt(0, T, 0));
  memset(dist, inf, sizeof dist);

  while (!pq.empty())
  {
    tri top = pq.top();
    pq.pop();
    int u = fst(top);                                   // vértice atual
    int t = snd(top);                                   // gas no tanque atual
    int c = trd(top);                                   // custo atual

    if (c > dist[u][t]) continue;                       // é mais caro que o atual
    if (u == N - 1) ans = min(ans, c);                  // chegou: pega o melhor

    for (int i = 0; i < (int)g[u].size(); ++i)
    {
      int v = g[u][i].first;                            // vizinho do atual
      int gasNeed = g[u][i].second;                     // gas necessária
      if (t - gasNeed >= 0 && dist[v][t - gasNeed] > c) // se chega em v e tem vantagem
      {
        dist[v][t - gasNeed] = c;                       // atualiza custo
        pq.push(mt(v, t - gasNeed, c));                 // add para processar
      }
    }
    for (int k = 1; k + t <= T; ++k)                    // abastece k litros
    {
      int cost = gasCost[u] * k + c;                    // custo para abastecer
      if (cost < dist[u][k + t])                        // se é melhor abastecer
      {
        dist[u][k + t] = cost;                          // custo para chegar
        pq.push(mt(u, k + t, cost));                    // add para processar
      }
    }
  }

  return (ans == inf ? -1 : ans);
}

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> M >> T && (N || M || T))
  {
    for (int i = 0; i < N; ++i) g[i].clear();
    for (int i = 0, a, b, c; i < M; ++i)
    {
      cin >> a >> b >> c, --a, --b;
      g[a].push_back(ii(b, c));
      g[b].push_back(ii(a, c));
    }
    for (int i = 0; i < N; ++i) cin >> gasCost[i];

    cout << dijkstra() << '\n';
  }

  return 0;
}
