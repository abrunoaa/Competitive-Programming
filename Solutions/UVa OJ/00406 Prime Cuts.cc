#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, i, lim, c, qtd;
vector<int> primos;

void gera ()
{
  int i, j;
  primos.push_back(1e9);  // reserva lugar para o 1
  for (i = 2; i < 1005; ++i)
  {
    for (j = 0; j < (int)primos.size() && i % primos[j]; ++j);
    if (j == (int)primos.size())
      primos.push_back(i);
  }
  primos[0] = 1;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  gera();

  while (cin >> n >> c)
  {
    cout << n << ' ' << c << ':';
    qtd = lower_bound(primos.begin(), primos.end(), n) - primos.begin();

    if (primos[qtd] == n) ++qtd;
    c = 2 * c - qtd % 2;

    if (c >= qtd)
      for (i = 0; i < qtd; ++i)
        cout << ' ' << primos[i];
    else
      for (i = qtd / 2 - c / 2, lim = qtd / 2 + (int)ceil(c / 2.0); i < lim; ++i)
        cout << ' ' << primos[i];

    cout << endl << endl;
  }

  return 0;
}
