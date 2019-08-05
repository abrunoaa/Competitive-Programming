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

#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX 510
#define T  // test

typedef pair < int, int > ii;

int main() {
  register int i, j;
  int count = 0, n, m, a, b, l, madj[MAX][MAX] = {0}, dis[MAX], at, b1, b2, l1, l2;
  double h;
  ii f;
  vector < vector < ii > > ladj(MAX);
  priority_queue < ii, vector < ii >, greater < ii > > pq;

  dis[0] = 0; // 0 -> 0 == 0

  while (scanf("%d%d", &n, &m), n || m) {
    for (i = m; i--; ) {
      scanf("%d%d%d", &a, &b, &l);
      a--;
      b--;
      madj[a][b] = madj[b][a] = l;
      ladj[a].push_back(ii(b, l));
      ladj[b].push_back(ii(a, l));
    }
#ifdef T
    printf("\n + ladj:\n");
    for (i = 0; i < n; i++)
      for (j = 0; j < (int)ladj[i].size(); j++) {
        printf(" + %d -> %d :: %d\n", i, ladj[i][j].first, ladj[i][j].second);
      }

    printf("\n - madj:\n -      ");
    for (j = 0; j < n; j++) {
      printf("%2d ", j);
    }
    printf("\n");
    for (i = 0; i < n ; i++) {
      printf(" - %2d | ", i);
      for (j = 0; j < n; j++) {
        printf("%2d ", madj[i][j]);
      }
      printf("\n");
    }
#endif
    for (i = n; --i; dis[i] = 1000000000);  // d[0] == 0

    /// dijkstra
    pq.push(ii(0, 0));  // 0 == start (key 1)
    while (!pq.empty()) {
      f = pq.top(); // process
      pq.pop();
      if (f.first > dis[f.second]) {
        continue;
      }
      for (i = ladj[f.second].size(); i--; ) {
        l1 = ladj[f.second][i].first;
        l2 = ladj[f.second][i].second;
        if (l2 + dis[f.second] < dis[l1]) { // relax
          dis[l1] = dis[f.second] + l2;
          pq.push(ii(dis[l1], l1));
        }
      }
    }
#ifdef T
    printf("\n >> dis:\n");
    for (i = 0; i < n; i++) {
      printf(" >> 0 -> %d == %d\n", i, dis[i]);
    }
#endif
    h = 0.000;  // > sec
    for (i = n; i--; )
      for (j = i; ++j < n; )
        if (madj[i][j]) {
#ifdef T
          printf(" ! S = %12.9lf | %d %d\n", max(dis[i], dis[j]) + abs(abs(dis[i] - dis[j]) - madj[i][j]) / 2.0, i, j);
#endif
          // ↓↓↓↓↓↓↓↓↓↓↓↓ conta cabulosa ↓↓↓↓↓↓↓↓↓↓↓↓
          h = max(h, max(dis[i], dis[j]) + abs(abs(dis[i] - dis[j]) - madj[i][j]) / 2.0 );
        }
#ifdef T
    printf(" ! h = %.9lf\n", h);
#endif
    at = -1;  // flag
    for (i = n; i--; )
      if (fabs(h - dis[i]) < 0.001) { // 0.001 for precision
        at = i;
        break;
      }
    if (at == -1) { // between dominoes
      for (i = n; i--; )
        for (j = i; ++j < n; )
          if (madj[i][j] && fabs(h - max(dis[i], dis[j]) + (abs(dis[i] - dis[j]) - madj[i][j]) / 2.0) < 0.001) {
            b1 = i;
            b2 = j;
            i = 0;
            break;
          }
      printf("System #%d\nThe last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",
             ++count, h, b1 + 1, b2 + 1);
    } else
      printf("System #%d\nThe last domino falls after %.1lf seconds, at key domino %d.\n\n",
             ++count, h, at + 1);

    for (i = n; i--; ladj[i].clear())
      for (j = n; j--; madj[i][j] = 0);
  }

  return 0;
}
