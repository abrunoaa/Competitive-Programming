#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

int main()
{
  //freopen("in", "r", stdin);

  register int i, j, u, ub;
  int n, ei, nd, lr, sum, dist, k;
  const int inf = 1e9;
  queue < int > q;
  ii v;
  vi dis, vis, e;
  vvii adj;

  while (scanf("%d", &n), n != -1)
  {
    adj.assign(n, vii());
    e.assign(n, 0);

    for (i = 0; i < n; ++i)
    {
      scanf("%d%d", &ei, &nd);
      e[i] = -ei;                         // inverte o peso para encontrar ciclos + facil

      while (nd--)
      {
        scanf("%d", &lr);
        adj[i].push_back(ii(--lr, 0));    // nao pode setar o peso agora
      }
    }

    for (i = n; i--; )                    // seta o peso correto
      for (j = adj[i].size(); j--; )
        adj[i][j].second = e[adj[i][j].first];

    // bellman
    dis.assign(n, inf);
    dis[0] = 0;

    for (i = n - 1; i--; )
      for (u = n; u--; )
        for (j = adj[u].size(); j--; )
        {
          v = adj[u][j];
          sum = dis[u] + v.second;
          if (sum < dis[v.first] && sum < 100)  // nao pode ultrapassar 100
            dis[v.first] = sum;
        }
    // \bellman

    dist = dis[n - 1];
    vis.assign(n, 0);
    for (u = n; u-- && dist == inf; )
      for (j = adj[u].size(); j--; )
      {
        v = adj[u][j];
        if (dis[v.first] > dis[u] + v.second && dis[v.first] != inf && !vis[v.first])
        {
                      // ciclo negativo: pode ficar dando voltas e carregar o 'especial'
                      // mas tem que verificar se o ciclo chega no ultimo vertice!
          // bfs
          q.push(v.first);
          vis[v.first] = 1;

          while (!q.empty())
          {
            ub = q.front();
            q.pop();
            for (i = adj[ub].size(); i--; )
            {
              k = adj[ub][i].first;
              if (!vis[k])
              {
                vis[k] = 1;
                q.push(k);
              }
            }
          }
          // \bfs

          if (vis[n - 1])
          {               // chega no ultimo
            dist = 0;     // flag
            break;        // pode parar
          }
        }
      }

    if (dist < 100) puts("winnable");
    else            puts("hopeless");
  }

  return 0;
}
