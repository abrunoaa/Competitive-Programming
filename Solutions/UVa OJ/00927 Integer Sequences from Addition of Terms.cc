#include <bits/stdc++.h>
using namespace std;

/*
 * Para An = 23n^4 + 3; (teste 1 dos exemplos)
 * b = {  26,   371,   1866, ...}
 *       25x    50x     75x, ...
 *      1~25  26~75  76~150
 *
 * Para k = 100, n = 3, pois 76 <= k <= 150.
 *
 * usando PAs: a0 + a1 + ... + an = (a1 + an) * n/2
 *             a0 + a1 + ... + an = k
 *
 *              k = (d + dn) * n/2
 *             2k = (d + dn) * n
 *             2k = dn + dn^2
 * dn^2 + dn - 2k = 0
 *
 * n = -1/2 +- sqrt((d + 8k) / 4d)
 *
 * como posição negativa não existe:
 *
 * n = -1/2 + sqrt((d + 8k) / 4d)
 */

int main()
{
  freopen("in", "r", stdin);

  long long C, pol, i, ct[50], d, k, N, n, ans;

  scanf("%lld", &C);
  while (C--)
  {
    scanf("%lld", &pol);
    for (i = 0; i <= pol; ++i)
      scanf("%lld", ct + i);

    scanf("%lld%lld", &d, &k);

    N = 1;
    n = ceil(-0.5 + sqrt((d + 8 * k) / (d * 4.0))); // valor de n (arred. p/ cima)

    ans = 0;
    for (i = 0; i <= pol; ++i)                      // varia polinomios
    {
      ans += ct[i] * N;                             // soma
      N *= n;                                       // aumenta o grau (n^1, n^2, ...)
    }

    printf("%lld\n", ans);
  }

  return 0;
}
