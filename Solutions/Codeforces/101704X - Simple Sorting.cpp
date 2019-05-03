#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> x;

int main()
{
  //~ freopen("xin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;

  cin >> n;
  x.reserve(n + 10);
  for (int i = 0, v; i < n; ++i)
  {
    cin >> v;
    x.push_back(v);
  }

  if (n % 2 == 0)
    sort(x.rbegin(), x.rend());
  else
    sort(x.begin(), x.end());

  x.erase(unique(x.begin(), x.end()), x.end());

  for (int i = 0; i < (int)x.size(); ++i)
    cout << x[i] << '\n';

  return 0;
}
