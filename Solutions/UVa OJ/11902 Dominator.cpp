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
#include <cstring>
using namespace std;

#define MAX 110
#define GAY \
  printf("+"); \
  for (j = -1; ++j < x; ) \
    printf("-"); \
  printf("+\n");

bool see[MAX], see1[MAX], dom[MAX][MAX];
int adj[MAX][MAX], off, n, count = 0;

void dfs(int u) {
//printf("call %d : cont %d\n", u, u == off ? 0 : 1);
  if (u == off) {
    return;
  }

  see[u] = 1;
  for (register int i = -1; ++i < n; )
    if (adj[u][i] && !see[i]) {
      dfs(i);
    }
}

int main() {
  register int i, j;
  int teste, x;

  scanf("%d", &teste);
  while (teste--) {
    scanf("%d", &n);
    for (i = -1; ++i < n; ) {
      for (j = -1; ++j < n; ) {
        scanf("%d", &adj[i][j]);
        dom[i][j] = 0;
      }
      see[i] = 0;
    }
    /*
    for(i = -1; ++i < n; )
    {
      for (j = -1; ++j < n; )
        printf("%d ", adj[i][j] ? 1 : 0);
      printf("\n");
    }
    //*/
    off = -1;
    dfs(0);
    for (i = -1; ++i < n; ) {
      see1[i] = see[i];
    }
    for (j = -1; ++j < n; ) {
      see[j] = 0;
    }
    for (i = -1; ++i < n; ) {
      off = i;
//printf(" >>> %d calling...\n", off);
      dfs(0);
      for (j = -1; ++j < n; ) {
        if (see1[j] != see[j]) {
          dom[i][j] = 1;
        }
        see[j] = 0;
      }
    }

    printf("Case %d:\n", ++count);
    x = n * 2 - 1;
    GAY
    for (i = -1; ++i < n; ) {
      for (j = -1; ++j < n; ) {
        printf("|%c", dom[i][j] ? 'Y' : 'N');
      }
      printf("|\n");
      GAY
    }
  }

  return 0;
}
