#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  int n, ans, a, b, c, x, X, y, Y, z;

  while (cin >> n >> a >> b >> c)
  {
    ans = 0;

    for (x = 0, X = n / a; x <= X; ++x)
      for (y = 0, Y = n / b; y <= Y; ++y)
      {
        z = n - a * x - b * y;
        if (z % c == 0 && 0 <= z) ans = max(ans, x + y + z / c);
      }

    cout << ans << '\n';
  }

  return 0;
}
