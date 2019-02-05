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
#include <set>
using namespace std;

//#define T

// if go out
#define VER \
  for (j = -1; ++j < f && out[j] != p; ); \
  if (j == f) \
  { \
    out[f++] = p; \
    break; \
  }

int main()
{
  char face, com[105];
  register int i, f = 0, j; // f == length out
  int mx, my, x, y;
  unsigned int p, out[205];

  scanf("%d%d", &mx, &my);
  while (scanf("%d%d %c", &x, &y, &face) != EOF)
  {
    if (face == 'N')
      face = 0;
    else
      if (face == 'E')
        face = 1;
      else
        if (face == 'S')
          face = 2;
        else
          face = 3;

    scanf(" %s", com);
    i = -1;
#ifdef T
    printf(" +++ %d %d %d %d %d - %s\n", mx, my, x, y, face, com);
#endif
    while (com[++i])
    {
#ifdef T
      printf(" >>> %d %d %d %c\n", x, y, face, com[i]);
#endif
      if (com[i] == 'F')
        if (face == 0)
        {
          if (++y > my)
          {
            p = x * 100 + --y;
            VER
          }
        }
        else
          if (face == 1)
          {
            if (++x > mx)
            {
              p = --x * 100 + y;
              VER
            }
          }
          else
            if (face == 2)
            {
              if (--y < 0)
              {
                p = x * 100 + ++y;
                VER
              }
            }
            else
            {
              if (--x < 0)
              {
                p = ++x * 100 + y;
                VER
              }
            }
      else
        if (com[i] == 'R')
          if (face == 3)
            face = 0;
          else
            face++;
        else
          if (face)
            face--;
          else
            face = 3;
    }

    printf("%d %d %c%s\n", x, y, (face == 0 ? 'N' : face == 1 ? 'E' : face == 2 ? 'S' : 'W'), (com[i] ? " LOST" : ""));
#ifdef T
    if (com[i])
      printf(" > %d\n", p);
    for (j = 0; j < f; j++)
      printf(" ! %d %d\n", j, out[j]);
#endif
  }
  return 0;
}
