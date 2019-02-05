#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 10010ll               // sqrt(max^2 + max + 41) ≃ 10010

typedef long long ll;

ll a, b;
ll soma[MAX];
bitset<MAX> bsprimos;
vector<ll> primos;

void gera (ll n = MAX)
{
  ll i, j;
  bsprimos.set();
  bsprimos[0] = bsprimos[1] = 0;
  for (i = 2; i < n; ++i)
    if (bsprimos[i])
    {
      primos.pb(i);
      for (j = i * i; j < n; j += i)
        bsprimos[j] = 0;
    }
}

bool ePrimo (ll v)
{
  if (v < MAX) return bsprimos[v];

  ll i;
  for (i = 0; i < (ll)primos.size() && v % primos[i]; ++i);
  return i == (ll)primos.size();
}

int main()
{
  gera();

  soma[0] = 1;
  for (ll i = 1; i < MAX; ++i)
    soma[i] = soma[i - 1] + (ePrimo(i * i + i + 41) ? 1 : 0);

  while (scanf("%lld%lld", &a, &b) == 2)
    printf("%.2lf\n", (soma[b] - (a ? soma[a - 1] : 0)) * 100.0 / (b - a + 1) + 1e-9);

  return 0;
}
