#include <cstdio>
#include <cmath>
#include <cstring>

typedef long long ll;

ll gcd (ll a, ll b)
{ return !b ? a : gcd(b, a % b); }

int main()
{
  ll j, k, n, rep, pot, den, num, g, cs = 0;
  double x, ant;
  char s[20];

  while (scanf("%lld %[.0-9]", &j, s) == 2 && j >= 0)
  {
    n = strlen(s);                                    // tamanho do número
    k = n - 2 - j;                                    // qtd que não faz parte da dízima
    sscanf(s, "%lf", &x);                             // número real

    if (j)
    {                                                 // tem dízima
      sscanf(s + k + 2, "%lld", &rep);                // pega a dízima
      pot = 2 * j + k;                                // 1ª potência para somar
      do
      {
        ant = x;                                      // salva anterior
        x += rep * pow(10, -pot);                     // add mais uma dízima
        pot += j;                                     // vai mais para a direita
      } while (x - ant > 0);                          // insere o máximo possível

      den = pow(10, k + j) - pow(10, k);              // denominador
    }
    else
    {                                                 // não tem dízima
      den = pow(10, k);                               // denominador
    }

    num = (ll)round(den * x);                         // numerador

    g = gcd(den, num);                                // simplifica fração
    den /= g;
    num /= g;

    printf("Case %lld: %lld/%lld\n", ++cs, num, den);
  }

  return 0;
}
