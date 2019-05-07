#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll inf = 1e18;

ll rxNeed, ryNeed, xNeed, yNeed, n, cost = inf;
ll rx, ry, x, y, c;

ll f(ll rx, ll ry, ll x, ll y, ll c)
{
  ll cost = inf;
  for (int i = 0; i < 2; ++i)
  {
    ll dx = max((x + xNeed - 1) / x, (rx + rxNeed - 1) / rx);
    ll dy = max((y + yNeed - 1) / y, (ry + ryNeed - 1) / ry);
    cost = min(cost, dx * dy * c);
    swap(rx, ry);
    swap(x, y);
  }

  return cost;
}

int main()
{
  freopen("giant.in", "r", stdin);
  freopen("giant.out", "w", stdout);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> rxNeed >> ryNeed >> xNeed >> yNeed;
  cin >> n;
  while (n--)
  {
    cin >> rx >> ry >> x >> y >> c;
    cost = min(cost, f(rx, ry, x, y, c));
  }

  cout << cost << '\n';

  return 0;
}
