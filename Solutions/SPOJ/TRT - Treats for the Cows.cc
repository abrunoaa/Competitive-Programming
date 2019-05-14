#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, v[2010], memo[2010][2010];

ll sell(ll i = 0, ll j = n - 1)
{
  if (i > j) return 0;

  ll &pd = memo[i][j];
  if (pd != -1) return pd;

  ll age = i + (n - 1 - j) + 1;
  return pd = max(sell(i + 1, j) + v[i] * age, sell(i, j - 1) + v[j] * age);
}

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(memo, -1, sizeof memo);

  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> v[i];

  cout << sell() << '\n';

  return 0;
}
