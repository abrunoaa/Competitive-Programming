#include <bits/stdc++.h>
using namespace std;

#define MAX (1 << 16)

typedef long long ll;

bitset<MAX> epr;
vector<int> pr;

void sieve (ll n = MAX) {
  epr.set();
  epr[0] = epr[1] = 0;

  pr.reserve((int)(n / log(n)) << 1);
  for (ll i = 2; i < n; ++i)
    if (epr[i]) {
      pr.push_back(i);
      for (ll j = i * i; j < n; j += i) {
        epr[j] = 0;
      }
    }
}

/*
 * mdc(2², 3², 5²) = 2² * 3² * 5²
 * Logo, a resposta poderá ser formada apenas de multiplos de nº primo.
 * >> resposta = 2² + 3² + 5²
 */
ll summation (ll n) {
  if (n == 1) { return 2; }                                 // caso básico: ans = 1 + 1

  ll ans = 0, q = 0;

  for (ll i = 0, p = pr[0], up = sqrt(n); p <= up; p = pr[++i])
    if (n % p == 0) {                                   // é divisível
      ++q;                                              // +1 divisor
      ll k = 1;                                         // encontra o valor do divisor
      while (n % p == 0) { n /= p, k *= p; }
      ans += k;                                         // soma na resposta
    }
  if (n > 1) { ans += n, ++q; }                             // se n é primo, add ele

  return ans + (q == 1);                                // nota: se tiver apenas um
}                                                       // divisor, soma 1 (divide todos)

int main() {
  sieve();

  ll n, cn = 0;
  while (scanf("%lld", &n) == 1 && n) { printf("Case %lld: %lld\n", ++cn, summation(n)); }

  return 0;
}
