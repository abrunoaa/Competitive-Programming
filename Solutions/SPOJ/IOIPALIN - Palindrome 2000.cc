#include <bits/stdc++.h>
using namespace std;

int n;
int dp[5050][5050];
char st[5050];

int longPal (int l, int r)  // left/right
{
  if (l == r) return 1;
  if (l == r - 1) return st[l] == st[r] ? 2 : 1;
  if (dp[l][r] != -1) return dp[l][r];
  if (st[l] == st[r]) return dp[l][r] = longPal(l + 1, r - 1) + 2;
  return dp[l][r] = max(longPal(l + 1, r), longPal(l, r - 1));
}

int main()
{
  //freopen("in", "r", stdin);

  register int i, j;

  while (scanf("%d", &n) > 0)
  {
    scanf(" %s", st);
    for (i = n + 1; --i >= 0; )
      for (j = n + 1; j; dp[i][--j] = -1);
    printf("%d\n", n - longPal(0, n - 1));
  }

  return 0;
}
