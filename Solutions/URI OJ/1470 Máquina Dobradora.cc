// backtracking

#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;

int n, m, val, i;
vi v, w1, w2;

// transforma v de todas as formas possíveis
bool transforma (vi& v)
{
  if (v == w1 || v == w2)     // checa se é a solução
    return 1;
  if (v.size() < w1.size())   // impossível chegar à solução:
    return 0;                 // sempre vai diminuir de tamanho

  int i, j, size = v.size();
  for (i = 1; i < size; ++i)  // dobraduras
  {
    vi u;

    // "dobra"
    for (j = 0; j < i; ++j) u.push_back(v[2 * i - j - 1] + v[j]);

    // append os outros valores que não são modificados
    for (j = 2 * i; j < size; ++j) u.push_back(v[j]);

    // checa se a partir deste chega à solução
    if (transforma(u)) return 1;
  }

  return 0;
}

int main()
{
  while (scanf("%d", &n) == 1)
  {
    // reseta
    v.clear();
    w1.clear();

    while (n--)
    {
      scanf("%d", &val);
      v.push_back(val);
    }

    scanf("%d", &m);
    while (m--)
    {
      scanf("%d", &val);
      w1.push_back(val);                // w1 = vetor normal
    }

    w2.assign(w1.rbegin(), w1.rend());  // w2 = vetor invertido

    puts(transforma(v) ? "S" : "N");
  }

  return 0;
}
