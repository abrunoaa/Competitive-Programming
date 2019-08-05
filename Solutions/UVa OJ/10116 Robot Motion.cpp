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

bool pass[10][10];
char m[10][10];
bool stop;
int nl, nc, i, j, s, c1, l1, loop;

int move (int l, int c) {
  if (l < 0 || l >= nl || c < 0 || c >= nc) {
    return i;
  }

  if (!pass[l][c]) {
    pass[l][c] = 1;

    i++;
    switch (m[l][c]) {
    case 'N':
      j = move(l - 1, c);
      break;

    case 'E':
      j = move(l, c + 1);
      break;

    case 'S':
      j = move(l + 1, c);
      break;

    default:
      j = move(l, c - 1);
    }
    if (!loop) {
      return j;
    }
  }

  if (c1 == c && l1 == l) {
    stop = 1;
    return i;
  }
  if (stop) {
    return i;
  }
  if (c1 == -1 && l1 == -1) {
    c1 = c;
    l1 = l;
  }

  loop++;
  return --i;
}

int main() {
  while (scanf("%d%d%d", &nl, &nc, &s), nl || nc || s) {
    for (i = 0; i < nl; i++)
      for (j = 0; j < nc; j++) {
        scanf(" %c", &m[i][j]);
        pass[i][j] = 0;
      }

    loop = 0;
    stop = 0;
    c1 = l1 = -1;
    i = 0;
    j = move(0, s - 1);
    if (loop) {
      printf("%d step(s) before a loop of %d step(s)\n", j, loop);
    } else {
      printf("%d step(s) to exit\n", j);
    }
  }
}
