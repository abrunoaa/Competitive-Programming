#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair < int, int > ii;
typedef vector < int >    vi;
typedef vector < ii >     vii;
typedef vector < vii >    vvii;

int m, n;
vi vis;
vvii adj;
priority_queue < ii, vii, greater<ii> > pq;

ull prim ()
{
  register int i, u, size;
  ull cost = 0;
  ii v;
  vis.assign(m, 0);

  // proccess 0
  vis[0] = 1;
  for (i = 0, size = adj[0].size(); i < size; ++i)
  {
    v = adj[0][i];
    if (!vis[v.first])
      pq.push(ii(v.second, v.first));
  }

  while (!pq.empty())
  {
    v = pq.top();
    pq.pop();
    u = v.second;
    if (!vis[u])
    {
      cost += v.first;

      // proccess u
      vis[u] = 1;
      for (i = 0, size = adj[u].size(); i < size; ++i)
      {
        v = adj[u][i];
        if (!vis[v.first])
          pq.push(ii(v.second, v.first));
      }
    }
  }

  return cost;
}

int main()
{
  //freopen("in", "r", stdin);

  int x, y, z;
  ull tot;

  while (scanf("%d%d", &m, &n), m || n)
  {
    tot = 0;
    adj.assign(m+2, vii());
    while (--n >= 0)
    {
      scanf("%d%d%d", &x, &y, &z);
      adj[x].push_back(ii(y, z));
      adj[y].push_back(ii(x, z));
      tot += z;
    }
    printf("%lld\n", tot - prim());
  }
  return 0;
}
