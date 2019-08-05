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

#define ELSE \
  else \
    if (st[l][c] == '*') \
    { \
      st[l][c] = '.'; \
      stick++; \
    }

int main() {
  char com, st[105][105];
  register int i, j;
  int n, m, s, face, stick, l, c;
  while (scanf("%d%d%d", &n, &m, &s), n || m || s) {
    stick = 0;
    face = 99999;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf(" %c", &st[i][j]);
        if (face == 99999 && st[i][j] >= 'A' && st[i][j] <= 'Z') {
          if (st[i][j] == 'N') {
            face = 0;
          } else if (st[i][j] == 'L') {
            face = 1;
          } else if (st[i][j] == 'S') {
            face = 2;
          } else {
            face = 3;
          }
          st[i][j] = '.';
          l = i;
          c = j;
        }
      }
    } // fim for leitura
    /*
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        printf("%c ", st[i][j]);
      printf("\n");
    }
    //*/
    while (s--) {
      scanf(" %c", &com);
      if (com == 'F') {
        if (face == 0) {
          if ((--l < 0) || st[l][c] == '#') {
            ++l;
          }
          ELSE
        } else if (face == 1) {
          if ((++c >= m) || st[l][c] == '#') {
            c--;
          }
          ELSE
        } else if (face == 2) {
          if ((++l >= n) || st[l][c] == '#') {
            l--;
          }
          ELSE
        } else {
          if ((--c < 0) || st[l][c] == '#') {
            c++;
          }
          ELSE
        }
      } else {
        if (com == 'D')
          if (face == 3) {
            face = 0;
          } else {
            face++;
          } else if (face) {
          face--;
        } else {
          face = 3;
        }
      }
    } // fim while comando

    printf("%d\n", stick);
  }
}
