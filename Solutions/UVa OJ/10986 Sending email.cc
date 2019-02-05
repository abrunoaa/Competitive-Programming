#include <bits/stdc++.h>
using namespace std;

#define inf static_cast < int > (1e9)

typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < vii > vvii;

int main()
{
  //freopen ("in", "r", stdin);

  register int i, size, u;
  int test, n, m, s, t, s1, s2, p, cont = 0;
  ii front, v;
  priority_queue <ii, vii, greater<ii> > pq;
  int dis[21000];
  vii adj[21000];

  scanf("%d", &test);
  while (--test >= 0)
  {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (i = n; i; )
    {
      dis[--i] = inf;
      adj[i].resize(0);
    }

    while (--m >= 0)
    {
      scanf("%d%d%d", &s1, &s2, &p);
      adj[s1].push_back(ii(s2, p));
      adj[s2].push_back(ii(s1, p));
    }

    // dijkstra basicao
    dis[s] = 0;
    pq.push(ii(0, s));
    while (!pq.empty())
    {
      front = pq.top();
      pq.pop();
      u = front.second;

      if (front.first > dis[u])
        continue;

      for (i = 0, size = adj[u].size(); i < size; ++i)
      {
        v = adj[u][i];
        if (dis[u] + v.second < dis[v.first])
          pq.push(ii((dis[v.first] = dis[u] + v.second), v.first));
      }
    }

    if (dis[t] != inf)
      printf("Case #%d: %d\n", ++cont, dis[t]);
    else
      printf("Case #%d: unreachable\n", ++cont);
  }

  return 0;
}
