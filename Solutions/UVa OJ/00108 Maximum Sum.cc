#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("in", "r", stdin);

  int n, i, j, k, ma, sub;
  int mat[120][120];

  while (scanf("%d", &n) > 0)
  {
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      {
        scanf("%d", mat[i] + j);
        if (j) mat[i][j] += mat[i][j - 1];
      }

    ma = -1e9;
    for (i = 0; i < n; ++i)
      for (j = i; j < n; ++j)
      {
        sub = 0;
        for (k = 0; k < n; ++k)
        {
          if (i) sub += mat[k][j] - mat[k][i - 1];
          else   sub += mat[k][j];

          if (sub < 0) sub = 0;
          if (sub > ma) ma = sub;
        }
      }

    printf("%d\n", ma);
  }

  return 0;
}
