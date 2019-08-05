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
#include <string>
#include <cstring>
#include <unistd.h>
using namespace std;

//#define T

int main() {
  bool adj[30][30] = {0};
  char s[300], ord[30][30];
  int mino, thes, cand, len[30] = {0};
  register int i, p, mov, lim;

  while (scanf(" %[^\n]s", s), *s != '#') {
    i = -1;
    lim = -1; // only  necessary
    while (1) {
      p = s[++i] - 65;
#ifdef T
      printf("--%c %d\n", p + 65, i);
#endif
      if (p > lim) {
        lim = p;
      }
      for (i += 2; s[i] != ';' && s[i] != '.'; i++) {
        ord[p][len[p]++] = (s[i] -= 65);
        if (p != s[i]) { // need?
          adj[p][(int)s[i]] = 1;
        }
      }
      if (s[i] == '.') {
        break;
      }
    }
    lim++;
    mino = s[i + 2] - 65;
    thes = s[i + 4] - 65;
    cand = stoi(s + i + 6);

    /// pursuit
    mov = 0;
    while (1) {
#ifdef T
      printf("m %c | t %c | c %d\n", mino + 65, thes + 65, cand);
      printf("    ");
      for (i = 0; i < lim; i++) {
        printf("%c ", i + 65);
      }
      printf("| len > ord\n");
      for (int i = 0, j; i < lim; i++) {
        printf("%c : ", i + 65);
        for (j = 0; j < lim; j++) {
          printf("%d ", adj[i][j]);
        }
        printf("|  %d  > ", len[i]);
        for (j = 0; j < len[i]; j++) {
          printf("%c ", ord[i][j] + 65);
        }
        printf("\n");
      }
      //sleep(5);
#endif
      for (i = -1;
#ifdef T
           printf(" -- %d < %d[%c] && (!%d || %c == %c)\n", i, len[mino], mino + 65,
                  adj[mino][(int)ord[mino][i]] ? 1 : 0, thes + 65, ord[mino][i] + 65),
#endif
           ++i < len[mino] && (!adj[mino][(int)ord[mino][i]] || thes == ord[mino][i]); );
      if (i == len[mino]) { // trapped
        break;
      }
      thes = mino;          // follow
      mino = ord[mino][i];  // run

      if (++mov == cand) {
        mov = 0;
        printf("%c ", thes + 65);
        for (i = lim; i--; adj[i][thes] = 0); // indegree = 0
      }
    }
    printf("/%c\n", mino + 65);

    for (i = lim; i--; len[i] = 0)
      for (p = lim; p--; adj[i][p] = 0);
  }

  return 0;
}
