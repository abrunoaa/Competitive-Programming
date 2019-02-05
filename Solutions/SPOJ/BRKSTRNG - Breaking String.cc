#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 1010

int c[maxn];
int memo[maxn][maxn], best[maxn][maxn];

int main()
{
  // freopen("hin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int len, n;

  while (cin >> len >> n)
  {
    for (int i = 1; i <= n; ++i) cin >> c[i];

    c[0] = 0;
    c[++n] = len;
    ++n;

    for (int i = n - 2; i >= 0; --i)
    {
      memo[i][i + 1] = 0;
      best[i][i + 1] = i;
      for (int j = i + 2; j < n; ++j)
      {
        int &pd = memo[i][j] = inf;
        for (int k = best[i][j - 1], up = best[i + 1][j]; k <= up; ++k)
        {
          int x = c[j] - c[i] + memo[i][k] + memo[k][j];
          if (x < pd)
          {
            pd = x;
            best[i][j] = k;
          }
        }
      }
    }

    cout << memo[0][n - 1] << '\n';
  }

  return 0;
}
