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

int main()
{
  vector < vector < pair < int, int > > > adj(105);

  int aux[105];
  register int i, j, k;
  int teste, n, m, u, v, point, pos, count = 0;

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d%d", &n, &m);
    for (i = -1; ++i < n; )
      scanf("%d", aux + i);

    for (i = m; i--; )
    {
      scanf("%d%d", &u, &v);
      adj[u].push_back(make_pair(v, aux[v]));
    }

    pos = 0;
    point = 0;
    while ((j = adj[pos].size()))
    {
      for (k = 0, i = 0; ++i < j; )
        if (adj[pos][i].second > adj[pos][k].second)
          k = i;

      point += adj[pos][k].second;
      pos = adj[pos][k].first;
    }

    printf("Case %d: %d %d\n", ++count, point, pos);

    for (i = n; i--; )
      adj[i].clear();
  }

  return 0;
}
