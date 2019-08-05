#include <bits/stdc++.h>
using namespace std;

int main() {
  register long i, q = 0;
  double m1;

  for (i = 6; q < 10; ++i) {
    m1 = (sqrt(((i * i) << 3) + 1) - (i << 1) - 1) / 2.0;       // equação de P.A.
    if (fabs(m1 - static_cast < long long >(m1)) < 1e-9) {      // se é inteiro
      // é solução
      printf("%10ld%10ld\n", i, i + static_cast < long >(m1));
      ++q;                                                      // encontrou + 1
      i *= 5.82842712L;                                         // acelera mudança
    }
  }

  return 0;
}

/*
 * >> Para n = i - 1:
 * a1 = 1
 * an = i - 1
 *
 * Sn = (2 * a1 + (n - 1) * d) * n / 2
 *    = (2 * 1 + (i - 1 - 1) * 1) * (i - 1) / 2
 *    = (2 + i - 2) * (i - 1) / 2
 *    = i * (i - 1) / 2
 *
 * >> Para n = i + 1:
 * b1 = i + 1
 * bm = i + m
 *
 *                             Sm = Sn
 * (2 * b1 + (m - 1) * d) * m / 2 = i * (i - 1) / 2
 *      (2 * (i + 1) + m - 1) * m = i^2 - i
 *               (2i + m + 1) * m = i^2 - i
 *                  m^2 + 2im + m = i^2 - i
 *        m^2 + 2im + m - i^2 + i = 0
 *   m^2 + (2i + 1)m + (-i^2 + i) = 0
 *
 * - Aplicando bháskara:
 * m1 =  (sqrt(8 * i^2 + 1) - 2i - 1) / 2
 * m2 = (-sqrt(8 * i^2 + 1) - 2i - 1) / 2
 *
 * >> m2 retorna apenas negativo, logo não interessa.
 * >> se m1 não for inteiro, logo não gera soma inteira e não é solução.
 *
 * >> 46611179 / 7997214 ≃ 5.82842712, que é o último resultado.
 */





