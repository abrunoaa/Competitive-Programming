#include <bits/stdc++.h>
using namespace std;

#define MAX 1001000
#define reg register int

int gcd(reg a, reg b)
{ return b ? gcd(b, a % b) : a; }

int main() {
  int n, ans, qtd;
  reg v, u, i, k, x, y, z;
  bool fr[MAX];

  while (scanf("%d", &n) == 1) {
    for (i = n + 1; --i; fr[i] = 1);

    qtd = ans = 0;
    for (u = 2; u * u <= n; ++u)
      for (v = u % 2 + 1; v < u; v += 2)          // nota: apenas os ímpares
        if (gcd(u, v) == 1) {                     // somente primitivos
          x = u * u - v * v;
          y = 2 * u * v;
          z = u * u + v * v;
          if (z > n) { break; }                       // nota: z <= n
          ++ans;                                  // são coprimos (pois são primitivos)
          for (k = 1; z * k <= n; ++k) {
            fr[x * k] = fr[y * k] = fr[z * k] = 0;
          }
        }
    for (i = 1; i <= n; ++i)
      if (fr[i]) {
        ++qtd;
      }
    printf("%d %d\n", ans, qtd);
  }

  return 0;
}

/*
 * x = u^2 - v^2
 * y = 2uv
 * z = u^2 + v^2
 *
 * (x,y,z) é primitivo se m e n são coprimos e m - n é ímpar.
 */
