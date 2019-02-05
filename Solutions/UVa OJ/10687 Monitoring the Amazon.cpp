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
#include <vector>
#include <cmath>
#include <cinttypes>
using namespace std;

typedef uint64_t ull;

vector < vector < int > > adj(1005);
bool see[1005];
int i, j, n, mep1, mep2;

#define pot(n) ((n)*(n))
#define dist(x1, x2, y1, y2) sqrt(pot((x2) - (x1)) + pot((y2) - (y1)))

int x[1005], y[1005];

void dfs (int u)
{
  see[u] = 1;
  for (int i = 0, size = adj[u].size(); i < size; i++)
    if (!see[adj[u][i]])
      dfs(adj[u][i]);
}

int main()
{
  ull dis, me1, me2;
  while (scanf("%d", &n), n)
  {
    i = -1;
    while (++i < n)
      scanf("%d%d", &x[i], &y[i]);

    for (i = 0; i < n; i++)
    {
      me1 = me2 = UINT64_MAX;
      mep1 = mep2 = 0;
      for (j = 0; j < n; j++)
        if (i != j)
        {
          dis = dist(x[i], x[j], y[i], y[j]) * 10000;
          if (dis < me1)
          {
            me2 = me1;
            mep2 = mep1;
            me1 = dis;
            mep1 = j;
            continue;
          }
          if (dis < me2)
          {
            me2 = dis;
            mep2 = j;
            continue;
          }
          if (dis == me1)
          {
            if (me1 == me2)
            {
              if (x[mep1] < x[mep2] || (x[mep1] == x[mep2] && y[mep1] < y[mep2]))
              {
                if (x[i] < x[mep2] || (x[i] == x[mep2] && y[i] < y[mep2]))
                {
                  me2 = dis;
                  mep2 = j;
                }
              }
              else
                if (x[i] < x[mep1] || (x[i] == x[mep1] && y[i] < y[mep1]))
                {
                  me1 = dis;
                  mep1 = j;
                }
              continue;
            }
            if (x[i] < x[mep1] || (x[i] == x[mep1] && y[i] < y[mep1]))
            {
              me1 = dis;
              mep1 = j;
              continue;
            }
          }
          if (dis == me2 && (x[i] < x[mep2] || (x[i] == x[mep2] && y[i] < y[mep2])))
          {
            me2 = dis;
            mep2 = j;
          }
        }

      adj[i].push_back(mep1);
      adj[i].push_back(mep2);
      see[i] = 0;
    }
    /*
    for (i = 0; i < n; i++)
      for (j = 0; (unsigned)j < adj[i].size(); j++)
        printf("%d -> %d\n", i, adj[i][j]);
//*/
    dfs(0);
    for (i = 0; i < n; i++)
      if (!see[i])
      {
        printf("There are stations that are unreachable.\n");
        break;
      }
    if (i == n)
      printf("All stations are reachable.\n");

    for (i = 0; i < n; i++)
      adj[i].clear();
  }

  return 0;
}
