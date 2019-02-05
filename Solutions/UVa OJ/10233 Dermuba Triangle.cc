#include <bits/stdc++.h>
using namespace std;

// ceil(sqrt(2^31)) = 46301

long sq[50000]; // squares

long bin(long v)
{
  long i = 0, j = 47000, med;

  while (i != j)
  {
    med = (i + j) >> 1;
    if (sq[med] < v)
      i = med + 1;
    else
      j = med;
  }

  return i;
}

int main()
{
  register long i, j;
  register double h;
  long n, m, ndif, mdif;

  for (i = 0; i < 47001; ++i)
    sq[i] = i * i;

  while (scanf("%ld%ld", &n, &m) > 0)
  {
    if (n > m)
      swap(n, m);

    i = bin(n);
    j = bin(m);

    if (n != sq[i])
      --i;
    if (m != sq[j])
      --j;

    // diff em relacao a x = 0
    ndif = n - sq[i] - sqrt(sq[i]);
    mdif = m - sq[j] - sqrt(sq[j]);

    // pega a altura
    // j - i == diff no eixo y // altura
    h = (j - i) * 0.866025403784;

    if (((n - sq[i]) & 1) && !((m - sq[j]) & 1))      // n com base para cima e m com base para baixo
      h += 0.288675134595;
    else if (!((n - sq[i]) & 1) && ((m - sq[j]) & 1)) // n com base para baixo e m com base para cima
    {
      if (j - i)
        h -= 0.288675134595;
      else
        h = 0.288675134595;
    }

    // hypot(x, y) = sqrt(x^2 + y^2)
    // abs(mdif - ndif) == diff no eixo x // base
    printf("%.3lf\n", hypot(abs(mdif - ndif) * 0.5, h));
  }

  return 0;
}





