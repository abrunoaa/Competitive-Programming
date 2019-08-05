#include <cstdio>

int main() {
  long long v;

  while (scanf("%lld", &v) == 1 && v)
    if (v % 9) {
      printf("%lld\n", v / 9 * 10 + v % 9);
    } else {
      printf("%lld %lld\n", (v - 9) / 9 * 10 + 9, v / 9 * 10);
    }

  return 0;
}

/*
 * a = (n - último dígito de n) / 10
 * b = último dígito de n
 *
 * n = 10a + b
 * m = a
 *
 * n - m = 10a + b - a
 *     v = 9a + b
 * v - b = 9a
 *     a = (v - b) / 9
 *
 * como a é inteiro, (v - b) % 9 == 0
 * como b só tem 1 dígito:
 *    se v % 9 == 0
 *        b = 0 ou b = 9
 *        a = v / 9 ou a = (v - 9) / 9
 *    senão
 *        b = nº que transforma v em múltiplo de 9
 *        b = v % 9
 *        a = (v - b % 9) / 9
 *        a = v / 9               (c++ arredonda para baixo)
 */
