#include <cstdio>
#include <queue>
using namespace std;

#define MAX 1005

const int inf = 1e9;
static_assert(inf > 1000, "cuzao");

struct str {
  int i, j, dis;
};

int main() {
  register int i, j;
  char mat[MAX][MAX];
  int dis[MAX][MAX], r, c, row, rn, nb, cb, rs, cs, rd, cd;
  queue < str > q;
  str u;

  while (scanf("%d%d", &r, &c), r || c) {
    for (i = r; i--; )
      for (j = c; j--; mat[i][j] = 1, dis[i][j] = inf);

    scanf("%d", &row);
    while (row--) {
      scanf("%d%d", &rn, &nb);
      while (nb--) {
        scanf("%d", &cb);
        mat[rn][cb] = 0;
      }
    }

    scanf("%d%d%d%d", &rs, &cs, &rd, &cd);

    q.push({rs, cs, -1});
    while (!q.empty()) {
      u = q.front();
      q.pop();
      if (dis[u.i][u.j] == inf) {
        mat[u.i][u.j] = 0;
        dis[u.i][u.j] = u.dis + 1;

        if (u.i + 1 < r  && mat[u.i + 1][u.j])  q.push({u.i + 1, u.j, u.dis + 1});
        if (u.i - 1 >= 0 && mat[u.i - 1][u.j])  q.push({u.i - 1, u.j, u.dis + 1});
        if (u.j + 1 < c  && mat[u.i][u.j + 1])  q.push({u.i, u.j + 1, u.dis + 1});
        if (u.j - 1 >= 0 && mat[u.i][u.j - 1])  q.push({u.i, u.j - 1, u.dis + 1});
      }
    }
    /*
    for (i = 0; i < r; i++)
    {
      for(j = 0; j < c; j++)
        printf("%3d", dis[i][j] == inf ? -1 : dis[i][j]);
      printf("\n");
    }
    //*/
    printf("%d\n", dis[rd][cd]);
  }

  return 0;
}
