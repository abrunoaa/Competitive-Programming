#include <cstdio>

#define MAX 25

char mat[MAX][MAX], land;
int m, n, number;

void col(int i, int j)
{
  number++;
  mat[i][j] = 0;
  if (i + 1 < m  && mat[i + 1][j] == land)  col(i + 1, j);
  if (i - 1 >= 0 && mat[i - 1][j] == land)  col(i - 1, j);
  if (j + 1 < n) { if (mat[i][j + 1] == land)  col(i, j + 1); }
  else if (mat[i][0] == land)  col(i, 0);


  if (j - 1 >= 0) { if (mat[i][j - 1] == land)  col(i, j - 1); }
  else if (mat[i][n - 1] == land)  col(i, n - 1);
}

int main()
{
  register int i, j;
  int x, y, max;
  while (scanf("%d%d", &m, &n) > 0)
  {
    for (i = -1; ++i < m; scanf(" %[^\n]", mat[i]));
    scanf("%d%d", &x, &y);
    land = mat[x][y];
    col(x, y);
    for (i = m, max = 0; i--; )
      for (j = n; j--; )
        if (mat[i][j] == land)
        {
          number = 0;
          col(i, j);
          if (number > max)
            max = number;
        }
    printf("%d\n", max);
  }

  return 0;
}
