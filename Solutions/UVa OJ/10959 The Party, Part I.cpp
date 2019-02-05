#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1e9;
const int MAX = 1005;

int main()
{
  register int i;
  int dis[MAX], p1, p2, teste, p, d, u;
  vector < int > adj[MAX];
  queue < int > q;

  dis[0] = 0;

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d%d", &p, &d);
    while (d--)
    {
      scanf("%d%d", &p1, &p2);
      adj[p1].push_back(p2);
      adj[p2].push_back(p1);
    }

    for (i = p; --i; dis[i] = inf); // dis[0] == 0
    q.push(0);
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

    for (i = 0; ++i < p; printf("%d\n", dis[i]));
    if (teste)
      printf("\n");
    for (i = p; i--; adj[i].clear());
  }

  return 0;
}
