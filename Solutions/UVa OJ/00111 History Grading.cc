#include <bits/stdc++.h>
using namespace std;

int i, j, aux, n, c[25], r[25], mem[25][25];

int align()
{
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      if (c[i - 1] == r[j - 1])
        mem[i][j] = mem[i - 1][j - 1] + 1;
      else
        mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);

  return mem[n][n];
}

int main()
{
  //freopen("in", "r", stdin);

  scanf("%d", &n);
  for (i = 0; i < n; ++i)
  {
    scanf("%d", &aux);
    c[aux - 1] = i;
  }

  //for (i = 0; i < n; ++i) printf("%d ", c[i]); puts("");

  for (i = 0; i < n; ++i)
    mem[i][0] = mem[0][i] = 0;

  while (scanf("%d", &aux) > 0)
  {
    r[aux - 1] = 0;
    for (i = 1; i < n; ++i)
    {
      scanf("%d", &aux);
      r[aux - 1] = i;
    }

    //for (i = 0; i < n; ++i) printf("%d ", r[i]); puts("");

    printf("%d\n", align());
  }

  return 0;
}
