#include <bits/stdc++.h>
using namespace std;

#define MAX 1001000
#define reg register ll

typedef long long ll;

const ll inf = 1e9;
ll l, u, menor, maior, menori, maiori;
bitset<MAX> epr;
vector<ll> pr, primos;

void sieve (reg n = MAX)
{
  epr.set();
  epr[0] = epr[1] = 0;
  pr.clear();
  pr.reserve((ll)(n / log(n)) << 1);
  for (reg i = 2; i < n; ++i)
    if (epr[i])
    {
      pr.push_back(ll(i));
      for (reg j = i * i; j < n; j += i)
        epr[j] = 0;
    }
}

bool ePrimo (reg v)
{
  if (v < MAX) return epr[v];
  for (reg i = 0, p = pr[0]; p * p <= v; p = pr[++i])
    if (v % p == 0)
      return 0;
  return 1;
}

int main()
{
  sieve();

  while (scanf("%lld%lld", &l, &u) == 2)
  {
    menor = inf, maior = -inf;
    for (reg i = l, j = u; i <= j; ++i)
      if (ePrimo(i))
      {
        if (!primos.empty())
        {
          reg diff = i - primos.back();
          if (diff < menor) menor = diff, menori = primos.size();
          if (diff > maior) maior = diff, maiori = primos.size();
        }
        primos.push_back(ll(i));
      }
    if (menor == inf || maior == -inf)
      puts("There are no adjacent primes.");
    else
      printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
                primos[menori - 1], primos[menori], primos[maiori - 1], primos[maiori]);

    primos.clear();
  }

  return 0;
}
