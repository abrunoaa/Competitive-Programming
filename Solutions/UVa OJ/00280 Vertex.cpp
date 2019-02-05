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
using namespace std;

bool see[105];
vector < vector < int > > adj(105);

void dfs (int u)
{
  see[u] = 1;
  for (int j = adj[u].size(); j-- ; )
    if (!see[adj[u][j]])
      dfs(adj[u][j]);
}

int main()
{
  int i, j, k, n;
  while (scanf("%d", &n), n)
  {
    while (scanf("%d", &i), i--)
      while (scanf("%d", &j), j--)
        adj[i].push_back(j);

    scanf("%d", &i);
    while (i--)
    {
      for (j = n; j--; )
        see[j] = 0;
      scanf("%d", &j);

      for (k = adj[--j].size(); k--; )
        if (!see[adj[j][k]])
          dfs(adj[j][k]);
      for (j = n, k = 0; j--; )
        if (!see[j])
          k++;
      printf("%d", k);
      for (j = -1; ++j < n; ) // print in order
        if (!see[j])
          printf(" %d", j +1);
      printf("\n");
    }

    for (j = n; j--; adj[j].clear());
  }

  return 0;
}
