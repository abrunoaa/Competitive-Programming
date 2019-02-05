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

bool see[105][105], gr[105][105];
uint r, c, m, n, ans[105][105];

void dfs(uint x, uint y)
{
  if (see[x][y])
    return;
  see[x][y] = 1;

  uint m1, n1;

  m1 = x + m;
  n1 = y + n;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x - m;
  n1 = y + n;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x + m;
  n1 = y - n;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x - m;
  n1 = y - n;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x + n;
  n1 = y + m;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x - n;
  n1 = y + m;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x + n;
  n1 = y - m;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }

  m1 = x - n;
  n1 = y - m;
  if (m1 >= 0 && m1 < r && n1 >= 0 && n1 < c && !gr[m1][n1])
  {
    ans[m1][n1]++;
    dfs(m1, n1);
  }
}

int main()
{
  register uint i, j, teste;
  uint par, imp, count = 0, w, x, y;
  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d%d%d%d%d", &r, &c, &m, &n, &w);

    for (i = r; i--; )
      for (j = c; j--; )
      {
        gr[i][j] = 0;
        see[i][j] = 0;
        ans[i][j] = 0;
      }
    while (w--)
    {
      scanf("%d%d", &x, &y);
      gr[x][y] = 1;
    }

    dfs(0, 0);

    if (!m || !n || m == n)
      for (i = r; i--; )
        for (j = c; j--; )
          ans[i][j] /= 2;

    par = 0;
    imp = 0;
    if (!ans[0][0]) // bug?
      par++;
    for (i = r; i--; )
      for (j = c; j--; )
        if (ans[i][j])
        {
          if (ans[i][j] % 2)
            imp++;
          else
            par++;
        }
    printf("Case %d: %d %d\n", ++count, par, imp);
  }

  return 0;
}
