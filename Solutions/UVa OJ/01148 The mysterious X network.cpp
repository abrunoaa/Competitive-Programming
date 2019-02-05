#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int inf = 1e9;
const int MAX = 1e5 + 5;

int main()
{
  int i, teste, n, cam, nsay, say, c1, c2, u, dis[MAX];
  queue < int > q;
  vector < int > adj[MAX];

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d", &n);
    for (i = n; i--; dis[i] = inf)
    {
      scanf("%d%d", &cam, &nsay);
      while (nsay--)
      {
        scanf("%d", &say);
        adj[cam].push_back(say);
      }
    }
    scanf("%d%d", &c1, &c2);
    dis[c1] = 0;
    q.push(c1);
    while (!q.empty())
    {
      u = q.front();
      q.pop();
      for (i = adj[u].size(); i--; )
        if (dis[adj[u][i]] == inf)
        {
          dis[adj[u][i]] = dis[u] + 1;
          q.push(adj[u][i]);
        }
    }
/*
for (i = 0; i < n; i++)
  printf(" ! %d == %d\n", i, dis[i]);
//*/
    printf("%d %d %d%s", c1, c2, dis[c2] - 1, (teste ? "\n\n" : "\n"));
    for (i = n; i--; adj[i].clear());
  }

  return 0;
}
