#include <bits/stdc++.h>
using namespace std;

#define maxn 16
#define f first
#define s second

typedef pair<int,int> ii;

int n, h[maxn];
ii memo[maxn][1 << maxn];

ii tsp(int u, int bm)
{
  if (!bm) return ii(h[u], 1);

  ii &pd = memo[u][bm];
  if (pd.f != -1) return pd;

  for (int i = 0; i < n; ++i)
    if (bm & (1 << i))
    {
      ii temp = tsp(i, bm ^ (1 << i));
      temp.f += abs(h[u] - h[i]);
      if (temp.f > pd.f)
        pd = temp;
      else if (temp.f == pd.f)
        pd.s += temp.s;
    }

  return pd;
}

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n && n)
  {
    ii ans(0, 0);
    memset(memo, -1, sizeof memo);

    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i)
    {
      ii temp = tsp(i, ((1 << n) - 1) ^ (1 << i));
      temp.f += 2 * n + h[i];
      if (temp.f > ans.f)
        ans = temp;
      else if (temp.f == ans.f)
        ans.s += temp.s;
    }

    cout << ans.f << ' ' << ans.s << '\n';
  }

  return 0;
}
