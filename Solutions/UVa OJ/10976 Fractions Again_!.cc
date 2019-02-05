#include <bits/stdc++.h>
using namespace std;

/*
 *          1/k = 1/x + 1/y
 *    1/k - 1/y = 1/x
 * (y - k) / yk = 1/x
 * yk / (y - k) = x
 *
 * Todos devem ser inteiros e x >= y.
 */

int main()
{
  long long int X[1000], Y[1000], x, y, k, c;

  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  while (scanf("%lld", &k) > 0)
  {
    c = 0;                                                  // conta qtde
    for (y = k + 1; (x = y * k / (y - k)) >= y; ++y)        // varia y até que x < y
      if (k == x * y / (x + y) && x * y % (x + y) == 0 && y * k % (y - k) == 0)
      {                                                     // verifica se é solução
        X[c] = x;                                           // add
        Y[c++] = y;
      }

    printf("%lld\n", c);
    for (x = 0; x < c; ++x)
      printf("1/%lld = 1/%lld + 1/%lld\n", k, X[x], Y[x]);
  }

  return 0;
}
