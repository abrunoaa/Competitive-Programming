#include <bits/stdc++.h>
using namespace std;

int D, i, j, n, m, ans, ag[2010], tom[2010], mem[2010][2010];

// Needleman-Wunsch’s algorithm
int align()
{
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (ag[i - 1] == tom[j - 1])
        mem[i][j] = mem[i - 1][j - 1] + 1;
      else
        mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);

  return mem[n][m];
}

int main()
{
  //freopen("in", "r", stdin);

  scanf("%d", &D);
  while (D--)
  {
    for (n = 0; scanf("%d", ag + n), ag[n]; ++n); // agnus

    ans = -1;
    while (scanf("%d", tom), *tom)
    {
      for (m = 1; scanf("%d", tom + m), tom[m]; ++m); // tom
      ans = max(ans, align());
    }

    printf("%d\n", ans);
  }

  return 0;
}
