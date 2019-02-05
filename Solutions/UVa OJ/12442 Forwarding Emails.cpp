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
#include <iostream>
using namespace std;

int main()
{
  bool st[50005], see[50005];
  register uint i, j, k, n, u, v, teste, em[50005], count = 0, mp, maior;

  for (scanf("%d", &teste); teste--; )
  {
    scanf("%d", &n);
    for (i = 0; ++i <= n; )
    {
      scanf("%d%d", &u, &v);
      em[u] = v;
      st[i] = 0;
    }

    for (mp = maior = i = 0; ++i <= n; )
    {
      if (!st[i])
      {
        j = 0;
        while (++j <= n)
          see[j] = 0;

        for (j = i, k = 1; true; k++)
        {
          st[j] = see[j] = 1;
          if (see[em[j]])
            break;
          else
            j = em[j];
        }
        if (k > maior)
        {
          maior = k;
          mp = i;
        }
      }
    }

    printf("Case %d: %d\n", ++count, mp);
  }

  return 0;
}
