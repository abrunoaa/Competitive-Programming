#include <bits/stdc++.h>
using namespace std;

#define MAX 100000010ll
#define reg register ll

typedef long long ll;

ll n, p;
bitset<MAX> epr;
vector<ll> pr;

void gera ()
{
  reg i, j, k;

  epr.set();
  epr[0] = 0;
  pr.reserve(MAX / log(MAX) * 1.1);  // reserva ±qtde de primos até max
  pr.push_back(2);
  for (i = 3; i < MAX; i += 2)
    if (epr[i >> 1])
    {
      pr.push_back(ll(i));
      for (j = i * i, k = i << 1; j < MAX; j += k)
        epr[j >> 1] = 0;
    }
}

int main()
{
  gera();

  reg i;
  while (scanf("%lld", &n) == 1)
  {
    if ((n & 1) && n > 1)                                       // é ímpar:
      i = p = (epr[(n - 2) >> 1] ? 2 : -1);                     // deve ser: 2 + 1primo
    else                                                        // é par:
    {                                                           // deve ser ímpar + ímpar
      // procura o do "meio" (menor diff possível)
      i = lower_bound(pr.begin(), pr.end(), n / 2) - pr.begin();
      if (pr[i] >= n / 2) --i;                                  // deve ser menor
      for (p = pr[i]; i >= 0; p = pr[--i])                      // procura a soma
        if (epr[(n - p) >> 1] && (((n - p) & 1) || n - p == 2))
          break;                                                // achou!
    }
    if (i >= 0)
      printf("%lld is the sum of %lld and %lld.\n", n, p, n - p);
    else
      printf("%lld is not the sum of two primes!\n", n);
  }

  return 0;
}
