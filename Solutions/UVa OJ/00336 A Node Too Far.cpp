#include <cstdio>
#include <map>
#include <vector>
#include <queue>
using namespace std;

//#define _TESTE_01121998

int main()
{
  register int i, u, count = 0, v, npos;
  int ttl, s, nc, n1, n2, dis[100000];
  int *p1, *p2;
  vector < int > adj[100000];
  queue < int > q;
  map < int, int > m;

  while (scanf("%d", &nc), nc)
  {
    for (npos = 1, i = nc; i--; )
    {
      scanf("%d%d", &n1, &n2);
      p1 = &m[n1];
      p2 = &m[n2];
      if (!*p1)
        *p1 = npos++;
      if (!*p2)
        *p2 = npos++;
      adj[*p1].push_back(*p2);
      adj[*p2].push_back(*p1);
    }
#ifdef _TESTE_01121998
    printf("-------------------------------------------------------\n");
    for (auto i = m.begin(); i != m.end(); i++)
      printf(" >> %2d == %2d\n", i->first, i->second);
    for (i = 1; i < npos; i++)
    {
      printf("%2d :", i);
      for (u = 0; u < (int)adj[i].size(); u++)
        printf(" %2d", adj[i][u]);
      printf("\n");
    }
    printf("-------------------------------------------------------\n");
#endif
    while (scanf("%d%d", &s, &ttl), s || ttl)
    {
      for (i = npos; --i; dis[i] = 1e9);
      dis[(v = m[s])] = 0;
      q.push(v);
      while (!q.empty())
      {
        u = q.front();
        q.pop();
#ifdef _TESTE_01121998
        printf(" - process %d\n", u);
#endif
        if (dis[u] == ttl)
        {
          i = q.size();
          while (i--)
            q.pop();
          break;
        }
        for (i = adj[u].size(); i--; )
          if (dis[adj[u][i]] == 1e9)
          {
            dis[adj[u][i]] = dis[u] + 1;
            q.push(adj[u][i]);
          }
      }
#ifdef _TESTE_01121998
      for (i = 1; i < npos; i++)
        printf(" ! %2d == %d\n", i, dis[i]);
#endif
      for (u = 0, i = npos; --i; )
        if (dis[i] == 1e9)
          u++;
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++count, u, s, ttl);
    }
    for (i = npos; --i; adj[i].clear());
    m.clear();
  }

  return 0;
}
