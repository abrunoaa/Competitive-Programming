#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mdc (ll a, ll b) { return b ? mdc(b, a % b) : a; }
ll mmc (ll a, ll b) { return a * (b / mdc(a, b)); }

int main()
{
  ll s, i, N, m, sum, ans_m, ans_n, tmp, cs = 0;
  vector<ll> a(10);

  scanf("%lld", &s);
  while (s--)
  {
    a.clear();

    scanf("%lld", &N);
    for (i = 0; i < N; ++i) scanf("%lld", &tmp), a.push_back(tmp);

    m = 1;
    for (auto x : a) m = mmc(m, x);

    sum = 0;
    for (auto x : a) sum += m / x;

    ans_m = N * m;
    ans_n = sum;

    m = mdc(ans_m, ans_n);
    printf("Case %lld: %lld/%lld\n", ++cs, ans_m / m, ans_n / m);
  }

  return 0;
}

/*
 * m = mdc(a1, a2, ..., an)
 * N / (1/a1 + 1/a2 + ... + 1/an) = N / ((m/a1 + m/a2 + ... + m/an) / m)
 *                                = N / (sum / m)
 *                                = N * m / sum
 */
