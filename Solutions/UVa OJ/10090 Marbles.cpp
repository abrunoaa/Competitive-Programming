#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d, q1, q2, q11, q21, n, n1, n2, c1, c2, k, flag;

void euclid (ll a, ll b) {
  if (!b) {
    q1 = 1, q2 = 0, d = a;
  } else {
    euclid(b, a % b);
    ll tmp = q1 - a / b * q2;
    q1 = q2;
    q2 = tmp;
  }
}

int main() {
  while (scanf("%lld%lld%lld%lld%lld", &n, &c1, &n1, &c2, &n2) == 5 && n) {
    euclid(n1, n2);             // equação diophantina: q1n1 + q2n2 = gcd(n1,n2)
    if (n % d) {
      // não tem solução inteira
      puts("failed");
      continue;
    }

    q1 *= n / d, q2 *= n / d;   // corrige equação: q1n1 + q2n2 = n

    // menor fica em q1
    if ((flag = q2 < q1)) { swap(q1, q2), swap(n1, n2), swap(c1, c2); }
    if (q1 < 0) {
      // q1 < 0: não tem solução negativa
      k = (ll)ceil(-q1 * d / (double)n2);
      q1 += n2 / d * k;         // faz q1 > 0
      q2 -= n1 / d * k;
      if (q2 < 0) {
        // não tem solução positiva
        puts("failed");
        continue;
      }
    }
    if (flag) { swap(q1, q2), swap(n1, n2), swap(c1, c2); }

    k = q1 / (n2 / d);          // pega a maioria de caixa 2 ;)
    q1 -= n2 / d * k;
    q2 += n1 / d * k;
    q11 = q1;
    q21 = q2;

    k = q2 / (n1 / d);          // pega a maioria de caixa 1
    q1 += n2 / d * k;
    q2 -= n1 / d * k;

    // se a 1ª escolha for mais barata: pega ela
    if (q11 * c1 + q21 * c2 < q1 * c1 + q2 * c2) { q1 = q11, q2 = q21; }
    printf("%lld %lld\n", q1, q2);
  }

  return 0;
}
