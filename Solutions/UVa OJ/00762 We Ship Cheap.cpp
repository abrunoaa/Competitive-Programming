#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define MAX 900

const int inf = 1e9;
char see[MAX];
int moved, dis[MAX], v1, v2, p[MAX];
vector < int > adj[MAX];
map < string, int > m;
map < int, string > m2;
  string aux;

void print(int v)
{
  if (v == v1)
  {
    aux = m2[v].data();
  }
  else
  {
    print(p[v]);
    printf("%s %s\n", aux.data(), m2[v].data());
    aux = m2[v].data();
  }
}

int main()
{
  char c1[5], c2[5];
  int npos, i, a, *p1, *p2, u;
  queue < int > q;

  while (scanf("%d", &a) > 0)
  {
    for (npos = 1, i = -1; ++i < a; )
    {
      scanf(" %2s %2s", c1, c2);
      p1 = &m[c1];
      p2 = &m[c2];
      if (!*p1)
        *p1 = npos++;
      if (!*p2)
        *p2 = npos++;
      adj[*p1].push_back(*p2);
      adj[*p2].push_back(*p1);
      m2[*p1] = c1;
      m2[*p2] = c2;
    }
/*
for (i = 1; i < npos; i++)
{
  printf("%s :", m2[i].data());
  for (int j = 0; j < (int)adj[i].size(); j++)
    printf(" %s", m2[adj[i][j]].data());
  printf("\n");
}
//*/
    scanf(" %2s %2s", c1, c2);
    v1 = m[c1];
    v2 = m[c2];
    if (v1 == v2) // ??
      printf("%s %s\n\n", c1, c1);
    else
    {
      for (i = npos; i--; dis[i] = inf);
      q.push(v1);
      while (!q.empty())
      {
        u = q.front();
        q.pop();
        for (i = adj[u].size(); i--; )
          if (dis[adj[u][i]] == inf)
          {
            dis[adj[u][i]] = dis[u] + 1;
            p[adj[u][i]] = u;
            q.push(adj[u][i]);
          }
      }
      if (dis[v2] == inf)
        printf("No route\n\n");
      else
      {
        print(v2);
        printf("\n");
      }
    }

    m.clear();
    m2.clear();
    for (i = npos; i--; adj[i].clear());
  }

  return 0;
}
