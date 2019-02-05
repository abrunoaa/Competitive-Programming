/*
 * Copyright 2017 Bruno Oliveira <abrunoaa@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <cstdio>
#include <map>
#include <queue>
using namespace std;

#define T // teste

#define MAX 70
#define SIMP(x, y)    \
  aux = gcd(max(x,y), min(x,y));    \
  x /= aux, y /= aux;

typedef unsigned int u;

u gcd(u x, u y) { return !y ? x : gcd(y, x % y); }

int main()
{
  bool push = 0, ar[MAX][MAX] = {0}, pr[MAX] = {0}, npush1 = 0, npush2 = 0;
  pair < u, u > adj[MAX][MAX];
  char com, n1[25], n2[25];
  register u i, j, k;
  u *pos1, *pos2, npos = 1, v1, v2, aux;
  map < string, u > m;
  queue < u > q;

  for (i = MAX; i--; )
    for (j = MAX; j--; )
      adj[i][j] = { 0,0 };

  while (scanf(" %c", &com), com != '.')
  {
    if (com == '!')
    {
      scanf("%d %s%*3c%d %s", &v1, n1, &v2, n2);
      SIMP(v1, v2)
      pos1 = &m[n1];
      pos2 = &m[n2];
      if (!*pos1)
      {
        *pos1 = npos++;
        npush1 = 1;
      }
      if (!*pos2)
      {
        *pos2 = npos++;
        npush2 = 1;
      }
      adj[*pos1][*pos1] = adj[*pos2][*pos2] = { 1, 1 };
      adj[*pos1][*pos2] = { v1, v2 };
      adj[*pos2][*pos1] = { v2, v1 };
      ar[*pos2][*pos1] = ar[*pos1][*pos2] = \
      ar[*pos1][*pos1] = ar[*pos2][*pos2] = 1;

      pr[*pos1] = pr[*pos2] = 1;
      if (!npush1)
        q.push(*pos1);
      else
        npush1 = 0;
      if (!npush2)
        q.push(*pos2);
      else
        npush2 = 0;
      while (!q.empty())
      {
        pr[i = q.front()] = 0;
        q.pop();
        for (j = 0; ++j < npos; )
          if (ar[i][j])
          {
            for (k = 0; ++k < npos; )
              if (!ar[j][k] && ar[i][k])
              {
                v1 = adj[i][j].second * adj[i][k].first;
                v2 = adj[i][j].first * adj[i][k].second;
                SIMP(v1, v2)
                adj[j][k] = { v1, v2 };
                adj[k][j] = { v2, v1 };
                ar[j][k] = ar[k][j] = 1;
                push = 1;
                if (!pr[k])
                {
                  pr[k] = 1;
                  q.push(k);
                }
              }
            if (push)
            {
              push = 0;
              q.push(j);
            }
          }
      }
#ifdef T
      printf("\n");
      for (i = 0; ++i < npos; )
      {
        for (j = 0; ++j < npos; )
          printf("[%3d,%3d] ", adj[i][j].first, adj[i][j].second);
        printf("\n");
      }
      printf(" >> arestas:\n");
      for (i = 0; ++i < npos; )
      {
        for (j = 0; ++j < npos; )
          printf("%d ", ar[i][j] ? 1 : 0);
        printf("\n");
      }
#endif
    }
    else
    {
      scanf(" %s%*3c%s", n1, n2);
      pos1 = &m[n1];
      pos2 = &m[n2];

      if (ar[*pos1][*pos2])
        printf("%d %s = %d %s\n", adj[*pos1][*pos2].first, n1, adj[*pos1][*pos2].second, n2);
      else
        printf("? %s = ? %s\n", n1, n2);
    }
  }

  return 0;
}
