#include <bits/stdc++.h>
using namespace std;

int k, n, v[501], w[501], *dp[2000001];

int knap(int k, int i)
{
  if (k <= 0 || i == n) return 0;
  if (dp[k][i] != -1) return dp[k][i];

  if (w[i] <= k)
    return dp[k][i] = max(knap(k, i + 1), v[i] + knap(k - w[i], i + 1));
  return dp[k][i] = knap(k, i + 1);
}

int main()
{
  //freopen("in", "r", stdin);

  register int i, j;

  scanf("%d%d", &k, &n);
  for (i = 0; i < n; ++i)
    scanf("%d%d", v + i, w + i);

  for (i = k + 1; --i >= 0; )
  {
    dp[i] = new int[n + 1];
    for (j = n + 1; j; dp[i][--j] = -1);
  }

  printf("%d\n", knap(k, 0));
}
