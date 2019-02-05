#include <bits/stdc++.h>
using namespace std;

#define MAX 10010
#define fst first
#define snd second

typedef long long ll;
typedef pair<ll,ll> ii;

bitset<MAX> epr;
vector<ll> pr;
vector<ii> fatores(100);
map<ll,ll> fatoresFatorial;

void sieve (ll n = MAX)
{
  epr.set();
  epr[0] = epr[1] = 0;

  pr.reserve((ll)(n / log(n)) << 1);
  for (ll i = 2; i < n; ++i)
    if (epr[i])
    {
      pr.push_back(i);
      for (ll j = i * i; j < n; j += i)
        epr[j] = 0;
    }
}

void fatora (ll n)
{
  fatores.clear();
  for (ll i = 0, p = pr[0]; p * p <= n; p = pr[++i])
  {
    if (n % p == 0) fatores.push_back(ii(p, 0));
    while (n % p == 0) n /= p, ++fatores.back().snd;
  }
  if (n > 1) fatores.push_back(ii(n, 1));
}

void fatoraFatorial (ll n)
{
  fatoresFatorial.clear();
  for (ll i = 0, p = pr[0]; p <= n; p = pr[++i])
  {
    auto& f = fatoresFatorial[p];
    for (ll k = p; k <= n; k *= p)
      f += n / k;
  }
}

int main()
{
  sieve();

  ll tc, m, n, k, cs = 0;

  scanf("%lld", &tc);
  while (tc--)
  {
    scanf("%lld%lld", &m, &n), fatora(m), fatoraFatorial(n);

    k = 1e9;
    for (auto x : fatores)
      k = min(k, (ll)(fatoresFatorial[x.fst] / x.snd));

    printf("Case %lld:\n", ++cs);
    if (k)  printf("%lld\n", k);
    else    puts("Impossible to divide");
  }

  return 0;
}

/*
 * 10! = 2^8 * 3^4 * 5^2 * 7^1
 *
 * 2^k | 10!
 * 2^k = 2^8   =>   k = 8
 *
 *   4^k | 10!
 * 2^2^k | 10!
 *  2^2k | 10!
 * 2^2k = 2^8   =>   k = 4
 *
 *       6^k | 10!
 * (2 * 3)^k | 10!
 * 2^k * 3^k | 10!
 * 2^k = 2^8   =>   k = 8
 * 3^k = 3^4   =>   k = 4
 * k = min(8, 4)
 * k = 4
 *
 *        12^k | 10!
 * (2^2 * 3)^k | 10!
 * 2^2^k * 3^k | 10!
 *  2^2k * 3^k | 10!
 * 2^2k = 2^8   =>   k = 4
 *  3^k = 3^4   =>   k = 4
 * k = min(4, 4)
 * k = 4
 *
 *          24^k | 10!
 * (2^2 * 3^2)^k | 10!
 * 2^2^k * 3^2^k | 10!
 *   2^2k * 3^2k | 10!
 * 2^2k = 2^8   =>   k = 4
 * 3^2k = 3^4   =>   k = 2
 * k = min(2, 4)
 * k = 2
 */
