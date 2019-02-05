#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define zero(x) (fabs(x) < 1e-9)

ll gcd (ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
  ll n, r, i, j, ans, sz;
  double r0;
  vector<ll> div;

  while (scanf("%lld", &n) == 1 && n)
  {
    r = r0 = sqrt(n);
    for (i = 1; i < r; ++i)
      if (n % i == 0)
        div.pb(i), div.pb(n / i);
    if (n % r == 0)
    {
      div.pb(r);
      if (!zero(r0 - r))
        div.pb(n / r);
    }

    // nota: ans = 1: lcm(n, n) = n
    for (i = 0, ans = 1, sz = div.size(); i < sz; ++i)
      for (j = i + 1; j < sz; ++j)
        if (gcd(div[i], div[j]) == 1)
          ++ans;

    printf("%lld %lld\n", n, ans);

    div.clear();
  }

  return 0;
}

