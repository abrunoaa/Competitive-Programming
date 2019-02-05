#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define MAX ((1 << 16) + 10)

typedef long long ll;
typedef pair<int,int> ii;

bitset<MAX> eprimo;
vector<int> primo;
vector<ii> fatores(100);

ll mdc(ll a, ll b) { return b ? mdc(b, a % b) : a; }

void sieve (int n = MAX)
{
  eprimo.set();
  eprimo[0] = eprimo[1] = 0;

  primo.reserve((int)(n / log(n)) << 1);
  for (ll i = 2; i < n; ++i)
    if (eprimo[i])
    {
      primo.push_back(i);
      for (ll j = i * i; j < n; j += i)
        eprimo[j] = 0;
    }
}

void fatora (ll n)
{
  fatores.clear();
  for (ll i = 0, p = primo[0]; p * p <= n; p = primo[++i])
  {
    if (n % p == 0) fatores.push_back(ii(p, 0));
    while (n % p == 0) n /= p, ++fatores.back().snd;
  }
  if (n > 1) fatores.push_back(ii(n, 1));
}

int main()
{
  sieve();

  ll n;
  while (scanf("%lld", &n) == 1 && n)
  {
    fatora(n * (n < 0 ? -1 : 1));                 // abs(n) em fatores primos.

    ll resp = fatores[0].snd;
    for (ii x : fatores)                          // Nota: 1º loop faz mdc(k, k) == k.
      resp = mdc(resp, x.snd);                    // Não afeta resultado.

    if (n < 0)                                    // Se a entrada for negativa:
      while (resp % 2 == 0)                       // não pode ser par (-n == -b ^ ímpar),
        resp /= 2;                                // então divide até ser ímpar.

    printf("%lld\n", resp);
  }

  return 0;
}

/*
 * 216 = 2^3 * 3^3
 * 216 = x^mdc(3, 3)
 * 216 = x^3
 * 216 = 6^3
 *
 * 648 = 2^3 * 3^4
 * 648 = x^mdc(3, 4)
 * 648 = x^1
 * 618 = 618^1
 *
 * 129600 = 2^6 * 3^4 * 5^2
 * 129600 = x^mdc(6, 4, 2)
 * 129600 = x^2
 * 129600 = 360^2
 *
 * 648000 = 2^6 * 3^4 * 5^3
 * 648000 = x^mdc(6, 4, 3)
 * 648000 = x^1
 * 648000 = 648000^1
 */
