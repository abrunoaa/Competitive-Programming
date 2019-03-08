#include <bits/stdc++.h>
using namespace std;

int main()
{
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int i, n, sum, ans, a[110], b[110];

  while (cin >> n)
  {
    for (i = 0; i < n; ++i) cin >> a[i], b[i] = (a[i] ? -1 : 1);

    if (*min_element(a, a + n))
    {
      cout << n - 1 << '\n';
      continue;
    }
    for (i = sum = ans = 0; i < n; ++i)
    {
      sum += b[i];
      ans = max(ans, sum);
      if (sum < 0) sum = 0;
    }

    for (i = 0; i < n; ++i)
      if (a[i])
        ++ans;

    cout << ans << '\n';
  }

  return 0;
}
