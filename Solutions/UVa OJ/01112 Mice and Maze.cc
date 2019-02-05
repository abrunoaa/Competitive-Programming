#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

#define inf static_cast<int>(1e9)

int e, n;
ii fr, v;
vi dis;
vvii adj;
priority_queue < ii, vii, greater<ii> > pq;

int dijkstra (int s)
{
  register int i, size, u;
  dis.assign(n, inf);
  dis[s] = 0;
  pq.push(ii(0, s));
  while (!pq.empty())
  {
    fr = pq.top();
    pq.pop();
    u = fr.second;
    if (fr.first > dis[u])
      continue;
    for (i = 0, size = adj[u].size(); i < size; ++i)
    {
      v = adj[u][i];
      if (dis[u] + v.second < dis[v.first])
      {
        dis[v.first] = dis[u] + v.second;
        pq.push(ii(dis[v.first], v.first));
      }
    }
  }
  return dis[e];
}

int main()
{
  //freopen("in", "r", stdin);

  register int i, q;
  int T, t, m, a, b, w;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d%d%d", &n, &e, &t, &m);
    --e;                // celula de saida
    adj.assign(n, vii());
    while (m--)
    {
      scanf("%d%d%d", &a, &b, &w);
      adj[a - 1].push_back(ii(b - 1, w));
    }

    for (i = q = 0; i < n; ++i) // para todo rato
      if (dijkstra(i) <= t) // chama dijkstra
        ++q;  // saiu
    printf("%d\n", q);
    if (T)
      printf("\n");
  }

  return 0;
}
