#include <bits/stdc++.h>
using namespace std;

/*
 * a % d = b % d   =>   (a - b) % d = 0
 * Assim,
 *    d = maiorDivisorComum(todosOsNumeros)
 */

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main()
{
  int d, i, fst, tmp;
  vector<int> v; v.reserve(1010);

  while (scanf("%d", &tmp) == 1 && tmp)
  {
    fst = tmp;
    while (scanf("%d", &tmp) == 1 && tmp) v.push_back(tmp - fst);

    if (v.size() > 1)
    {
      d = gcd(v[0], v[1]);
      for (i = 2; i < (int)v.size(); ++i)
        d = gcd(v[i], d);
    }
    else
      d = v[0];

    printf("%d\n", abs(d));

    v.clear();
  }

  return 0;
}
