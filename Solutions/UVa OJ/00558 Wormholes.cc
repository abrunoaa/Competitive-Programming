// grafo - ciclo negativo (Bellman Ford mod)

#include <bits/stdc++.h>
using namespace std;

#define inf static_cast < int > (1e9)

typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

int main()
{
  int i, j, n, m, x, y, t, test, size;
  bool neg;
  ii v;
  vi dis;
  vvii adj;

  scanf("%d", &test);
  while (test--)
  {
    scanf("%d%d", &n, &m);

    // reseta
    adj.assign(n, vii());
    dis.assign(n, inf);
    dis[0] = 0;

    // entrada do grafo
    while (m--)
    {
      scanf("%d%d%d", &x, &y, &t);
      adj[x].push_back(ii(y, t));
    }

    // Bellman Ford mod
    for (i = 0; i < n; ++i)
      for (j = 0, size = adj[i].size(); j < size; ++j)
      {
        v = adj[i][j];
        dis[v.first] = min(dis[v.first], dis[i] + v.second);  // relaxa
      }

    // checa ciclo negativo
    neg = 0;
    for (i = 0; !neg && i < n; ++i)
      for (j = 0, size = adj[i].size(); j < size; ++j)
      {
        v = adj[i][j];
        if (dis[v.first] > dis[i] + v.second)   // se ainda for possível relaxar:
        {
          neg = 1;                              // ciclo negativo existe!
          break;
        }
      }

    if (neg) printf("possible\n");
    else     printf("not possible\n");
  }

  return 0;
}
