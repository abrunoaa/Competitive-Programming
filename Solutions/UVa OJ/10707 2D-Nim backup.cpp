#include <cstdio>
#include <queue>
using namespace std;

struct asdf
{
  int i, j;
};

#define MAX 105
const int inf = 100;

char mat1[MAX][MAX], mat2[MAX][MAX], mat3[MAX][MAX], gr1[MAX][MAX], gr2[MAX][MAX], eq;
int vgr1[5], vgr2[5], teste, w, h, n, x, y;

void fill(int i, int j)
{
  mat2[i][j] = 0;
  if (i + 1 < h  && mat2[i + 1][j]) fill(i + 1, j);
  if (i - 1 >= 0 && mat2[i - 1][j]) fill(i - 1, j);
  if (j + 1 < w  && mat2[i][j + 1]) fill(i, j + 1);
  if (j - 1 >= 0 && mat2[i][j - 1]) fill(i, j - 1);
}

int main()
{
  register int i, j, k;
  queue < asdf > q;
  asdf u;

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d%d%d", &w, &h, &n);
    for (i = h; i--; )
      for (j = w; j--; mat1[i][j] = mat2[i][j] = 0);
    for (i = n; i--; )
    {
      scanf("%d%d", &y, &x);
      mat1[x][y] = 1;
    }

    for (i = n; i--; )
    {
      scanf("%d%d", &y, &x);
      mat2[x][y] = 1;
    }

    eq = 1;
    while (eq)
    {
      for (i = 5; i--; vgr1[i] = 0);
      for (i = h; i--; )
        for (j = w; j--; gr1[i][j] = 0);
      for (i = h, j = -1; i-- && j < 0; )
        for (j = w; j-- && !mat1[i][j]; );
      if (i < 0)
        break;
      i++;
      q.push({i, j});
/*
printf(" > %d %d:\n", i, j);
for (i = 0; i < h; i++)
{
  printf("%d :", i);
  for (j = 0; j < w; j++)
    printf(" %d", (int)mat1[i][j]);
  printf("\n");
}
printf("------------------------------------\n");
for (i = 0; i < h; i++)
{
  printf("%d :", i);
  for (j = 0; j < w; j++)
    printf(" %d", (int)mat2[i][j]);
  printf("\n");
}
printf("\n");
//*/
      while (!q.empty())
      {
        u = q.front();
        q.pop();
        if (!mat1[u.i][u.j])
          continue;
        mat1[u.i][u.j] = 0;
        if (u.i + 1 < h  && mat1[u.i + 1][u.j])
          gr1[u.i][u.j]++, gr1[u.i + 1][u.j]++, q.push({u.i + 1, u.j});
        if (u.i - 1 >= 0 && mat1[u.i - 1][u.j])
          gr1[u.i][u.j]++, gr1[u.i - 1][u.j]++, q.push({u.i - 1, u.j});
        if (u.j + 1 < w  && mat1[u.i][u.j + 1])
          gr1[u.i][u.j]++, gr1[u.i][u.j + 1]++, q.push({u.i, u.j + 1});
        if (u.j - 1 >= 0 && mat1[u.i][u.j - 1])
          gr1[u.i][u.j]++, gr1[u.i][u.j - 1]++, q.push({u.i, u.j - 1});

        vgr1[(int)gr1[u.i][u.j]]++;
      }

      for (i = h; i--; )
        for (j = w; j--; mat3[i][j] = mat2[i][j]);

      while (1)
      {
        for (i = 5; i--; vgr2[i] = 0);
        for (i = h; i--; )
          for (j = w; j--; gr2[i][j] = 0);
        for (i = h, j = -1; i-- && j < 0; )
          for (j = w; j-- && !mat3[i][j]; );
        if (i < 0)
        {
          eq = 0;
          break;
        }
        i++;

        q.push({i, j});
        while (!q.empty())
        {
          u = q.front();
          q.pop();
          if (!mat3[u.i][u.j])
            continue;
          mat3[u.i][u.j] = 0;
          if (u.i + 1 < h  && mat3[u.i + 1][u.j])
            gr2[u.i][u.j]++, gr2[u.i + 1][u.j]++, q.push({u.i + 1, u.j});
          if (u.i - 1 >= 0 && mat3[u.i - 1][u.j])
            gr2[u.i][u.j]++, gr2[u.i - 1][u.j]++, q.push({u.i - 1, u.j});
          if (u.j + 1 < w  && mat3[u.i][u.j + 1])
            gr2[u.i][u.j]++, gr2[u.i][u.j + 1]++, q.push({u.i, u.j + 1});
          if (u.j - 1 >= 0 && mat3[u.i][u.j - 1])
            gr2[u.i][u.j]++, gr2[u.i][u.j - 1]++, q.push({u.i, u.j - 1});

          vgr2[(int)gr2[u.i][u.j]]++;
        }
/*
printf(" >> %d %d:\n", i, j);
for (k = 0; k < 5; k++)
  printf(" ! %d - %d\n", vgr1[k], vgr2[k]);
printf("--------\n");
//*/
        for (k = 5; k-- && vgr1[k] == vgr2[k]; );
        if (k < 0)
        {
          fill(i, j);
          break;
        }
      }
    }

    printf("%s\n", (eq ? "YES" : "NO"));
  }

  return 0;
}
