#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ll n, b, i, fat, zero, mod;
  double dig, lb;

  while (scanf("%lld%lld", &n, &b) == 2)
  {
    dig = zero = 0;
    lb = log(b);
    mod = (ll)pow(b, floor(32 * M_LN2 / lb));

    for (i = fat = 1; i <= n; ++i)
    {
      dig += log(i) / lb;
      fat *= i;
      while (fat % b == 0) fat /= b, ++zero;
      fat %= mod;
    }

    printf("%lld %lld\n", zero, (ll)dig + 1);
  }

  return 0;
}
