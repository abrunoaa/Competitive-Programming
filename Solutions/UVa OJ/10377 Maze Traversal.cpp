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

typedef unsigned int uint;

int main()
{
  register char face, *cmd = new char[5000005], m[70][70];
  register uint l, c, i, teste;
  uint ml, mc;

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d%d", &ml, &mc);
    i = -1;
    while (++i < ml)
      scanf("%*c%[^\n]s", m[i]);

    scanf("%d%d", &l, &c);
    l--; c--;
    face = 0;
    do
    {
      scanf("%*[ \n]%[^ \n]", cmd);
      i = -1;
      while (cmd[++i])
      {
        /*
        printf("%d %d %d %d\n", l, c, ml, mc);
        for (int j = 0; j < ml; j++)
        {
          for (int i = 0; i < mc; i++)
            if (i == c && j == l)
              printf("H ");
            else
              printf("%c ", m[j][i]);
          printf("\n");
        }
        printf("\n");
        usleep(200000);
        //*/
        if (cmd[i] == 'F')
        {
          if (face == 0)
          {
            if (m[l -1][c] == ' ')
              l--;
          }
          else
            if (face == 1)
            {
              if (m[l][c +1] == ' ')
                c++;
            }
            else
              if (face == 2)
              {
                if (m[l +1][c] == ' ')
                  l++;
              }
              else
              {
                if (m[l][c -1] == ' ')
                  c--;
              }
        }
        else
          if (cmd[i] == 'R')
            if (face == 3)
              face = 0;
            else
              face++;
          else
            if (cmd[i] == 'L')
            {
              if (face)
                face--;
              else
                face = 3;
            }
            else
              break;
      }

    } while (cmd[i] != 'Q');

    printf("%d %d %c%s", l +1, c +1, (face == 0 ? 'N' : face == 1 ? 'E' : face == 2 ? 'S' : 'W'), teste ? "\n\n" : "\n");
  }

  delete cmd;
  return 0;
}
