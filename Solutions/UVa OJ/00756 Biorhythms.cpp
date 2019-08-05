#include <cstdio>

int main() {
  int p, e, i, d, ans, cs = 0;

  while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4 && !(p < 0 && e < 0 && i < 0 && d < 0)) {
    ans = (5544 * (p % 23) + 14421 * (e % 28) + 1288 * (i % 33)) % 21252 - d;
    if (ans <= 0) { ans += 21252; }
    printf("Case %d: the next triple peak occurs in %d days.\n", ++cs, ans);
  }

  return 0;
}

/*
 * (ans + d) % nk = ak % nk
 *
 * ans + d = x
 *     ans = x - d
 *
 * x % nk = ak % nk
 *
 * n = multiplicatório(nk), k = 1, 2, 3, ..., K
 * Nk = n / nk
 * Nk * xk % nk = 1   >>   encontrar xk
 *
 * x = somatório(ak * Nk * xk) % n, k = 1, 2, 3, ..., K
 *
 * para o problema: ans = (5544p + 14421e + 1288i) % 21252 - d
 * nota:
 *     n = 21252       = 23 * 28 * 33
 *     a =   p   e   i
 *    nk =  23  28  33
 *    Nk = 924 759 644
 *    xk =   6  19   2
 *     x = (924 * 6 * p + 759 * 19 * e + 644 * 2 * i) % 21252
 */

