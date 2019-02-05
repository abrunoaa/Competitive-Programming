#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mdc (ll a, ll b) { return b ? mdc(b, a % b) : a; }

int main()
{
  ll t, m, n, tmp, cs = 0;

  scanf("%lld", &t);
  while (t--)
  {
    scanf("%lld%lld", &m, &n);
    tmp = mdc(m, n);
    printf("Case %lld: %lld\n", ++cs, m / tmp + n / tmp);
  }

  return 0;
}
