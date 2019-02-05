#include <bits/stdc++.h>
using namespace std;

int main()
{
  char name[500], names[500000], dot;
  register int i, j;
  const int inf = 1e9, MAX = 1e5;

  int teste, p, n, *ptr, np, pc, o, u, count = 0, v[MAX], dis[MAX];
  map < string, int > mp;
  queue < int > q;
  vector < vector < int > > mat(MAX);
//printf(" >>>>>>>>>>>>>>>>>>>>>>>>>> %d <<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n", MAX);
  dis[0] = inf;
  scanf("%d", &teste);
  while (teste--)
  {
    np = 1;
    for (scanf("%d%d", &p, &n); p--; )
    {
      i = -2;
      pc = 0;
      scanf(" %[^:]", names);
//printf(" # %s #\n", names);
      do
      {
        for (i += 2, j = dot = 0; names[i]; i++, j++)
          if (names[i] == ',')
            if (!dot)
            {
              name[j] = ',';
              dot = 1;
            }
            else
              break;
          else
            name[j] = names[i];
        name[j] = 0;
//printf(" < %s >\n", name);
        ptr = &mp[name];
        if (*ptr == 0)
          *ptr = np++;

        for (j = pc; j--; )
        {
            mat[v[j]].push_back(*ptr);
            mat[*ptr].push_back(v[j]);
        }
        v[pc++] = *ptr;

      } while (names[i]);
      scanf("%*[^\n]");
    }
/*
for (map < string, int >::iterator it = mp.begin(); it != mp.end(); it++)
  printf(" ! %d %s\n", it->second, it->first.data());
for (i = 0; ++i < np; )
{
  printf("%d :", i);
  for (int j = 0; j < (int)mat[i].size(); j++)
    printf(" %d", mat[i][j]);
  printf("\n");
}
//*/
    for (i = np; --i; dis[i] = inf);
    q.push(o = mp["Erdos, P."]);
    dis[o] = 0;
    while (!q.empty())
    {
      u = q.front();
      q.pop();
      for (i = mat[u].size(); i--; )
        if (dis[mat[u][i]] == inf)
        {
          dis[mat[u][i]] = dis[u] + 1;
          q.push(mat[u][i]);
        }
    }

    printf("Scenario %d\n", ++count);
    while (n--)
    {
      scanf(" %[^\n]", name);
      o = mp[name];
      if (dis[o] == inf)
        printf("%s infinity\n", name);
      else
        printf("%s %d\n", name, dis[o]);
    }
    
    mp.clear();
    for (i = np; --i; mat[i].clear());
  }

  return 0;
}
