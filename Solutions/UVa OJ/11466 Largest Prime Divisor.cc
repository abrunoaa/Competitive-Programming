#include <bits/stdc++.h>
using namespace std;

#define MAX 10000100LL

typedef long long ll;

bitset<MAX> epr;
vector<ll> pr, fat;

void gera ()
{
  ll i, j;

  epr.set();
  epr[0] = epr[1] = 0;
  pr.reserve((ll)(MAX / log(MAX) * 1.01));
  for (i = 2; i < MAX; ++i)
    if (epr[i])
    {
      pr.push_back(i);
      for (j = i * i; j < MAX; j += i)
        epr[j] = 0;
    }
}

bool ePrimo (ll v)
{
  if (v < MAX) return epr[v];
  ll i;
  for (i = 0; i < (ll)pr.size() && v % pr[i]; ++i);
  return i == (ll)pr.size();
}

void fatora (ll n)
{
  fat.clear();
  for (ll i = 0, p = pr[0]; n > 1 && p * p <= n; p = pr[++i])
    if (n % p == 0)
    {
      fat.push_back(p);
      while (n % p == 0) n /= p;
    }
  if (n > 1) fat.push_back(n);
}

int main()
{
  ll n;

  gera();
  while (scanf("%lld", &n) == 1 && n)
  {
    if (n < 0) n *= -1;
    fatora(n);
    if (fat.size() < 2) puts("-1");
    else                printf("%lld\n", fat.back());
  }

  return 0;
}
