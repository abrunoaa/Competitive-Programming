#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("in597A", "r", stdin);

  long long a, b, k;
  while (cin >> k >> a >> b)
  {
    if (a % k) a += (a < 0 ?  0 : k) - a % k;
    if (b % k) b += (b < 0 ? -k : 0) - b % k;
    cout << (a > b ? 0 : (b - a + k) / k) << '\n';
  }

  return 0;
}
