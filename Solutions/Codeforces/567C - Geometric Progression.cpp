#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  ll i, n, k, tmp, ans;
  vector<ll> v;
  map<ll,ll> left, right;

  while (cin >> n >> k)
  {
    v.clear(), left.clear(), right.clear();

    for (i = 0; i < n; ++i) cin >> tmp, v.push_back(tmp), ++right[tmp];
    for (i = ans = 0; i < n - 1; ++i)
    {
      --right[v[i]];
      if (v[i] % k == 0) ans += left[v[i] / k] * right[v[i] * k];
      ++left[v[i]];
    }

    cout << ans << '\n';
  }

  return 0;
}
