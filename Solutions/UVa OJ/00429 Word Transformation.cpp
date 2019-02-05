#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

//#define TESTE
#define MAX 205

int main()
{
  char w[MAX][15], n1[15], n2[15], err;
  register int i, j, p, u, npos, teste, dis[MAX], p2, p1;
  vector < int > adj[MAX];
  map < string, int > m;
  queue < int > q;

  scanf("%d\n", &teste);
  while (teste--)
  {
    for (p = npos = 0; scanf("%[^\n]\n", w[p]), w[p][0] != '*'; )
    {
      for (i = npos; i--; )
      {
        if (strlen(w[p]) != strlen(w[i]))
          continue;
        for (err = 0, j = -1; w[p][++j]; )
          if (w[p][j] != w[i][j])
          {
            if (!err)
              err = 1;
            else
              break;
          }
        if (!w[p][j])
        {
          adj[j = m[w[i]]].push_back(npos);
          adj[npos].push_back(j);
        }
      }
      m[w[p++]] = npos++;
    }
#ifdef TESTE
    printf("-------------------------------------------------------\n");
    for (auto i = m.begin(); i != m.end(); i++)
      printf(" >> %10s == %d\n", i->first.data(), i->second);
    for (i = 0; i < npos; i++)
    {
      printf("%2d :", i);
      for (j = 0; j < (int)adj[i].size(); j++)
        printf(" %2d", adj[i][j]);
      printf("\n");
    }
    printf("-------------------------------------------------------\n");
#endif
    while (scanf("%[^ \n]s", n1) > 0)
    {
      scanf(" %[^\n]%*1c", n2);
      p1 = m[n1];
      p2 = m[n2];
      if (p1 == p2) // ???
      {
        printf("%s %s 0\n", n1, n1);
        continue;
      }
      for (i = npos; i--; dis[i] = 1e9);
      dis[p1] = 0;
      q.push(p1);
      while (!q.empty())
      {
        u = q.front();
        q.pop();
#ifdef TESTE
        printf(" - proc %d\n", u);
#endif
        for (i = adj[u].size(); i--; )
          if (dis[adj[u][i]] == 1e9)
          {
            dis[adj[u][i]] = dis[u] + 1;
            if (adj[u][i] == p2)
            {
              for (i = q.size(); i--; q.pop());
              break;
            }
            else
              q.push(adj[u][i]);
          }
      }
#ifdef TESTE
      for (i = 0; i < npos; i++)
        printf(" ! %2d == %d\n", i, dis[i]);
#endif
      printf("%s %s %d\n", n1, n2, dis[p2]);
    }

    for (i = npos; i--; adj[i].clear());
    m.clear();
    if (teste)
    {
      scanf(" ");
      printf("\n");
    }
  }

  return 0;
}
