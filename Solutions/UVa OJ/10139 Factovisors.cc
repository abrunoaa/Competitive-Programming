#include <bits/stdc++.h>
using namespace std;

#define MAX (1 << 16)

typedef long long ll;
typedef pair<int,int> ii;

bitset<MAX> epr;
vector<int> pr;
vector<ii> fatoresM;

void init (unsigned n = MAX)
{
  epr.set();
  epr[0] = epr[1] = 0;

  unsigned i, j;
  for (i = 2; i < n; ++i)
    if (epr[i])
    {
      pr.push_back(i);
      for (j = i * i; j < n; j += i) epr[j] = 0;
    }
}

void fatora (int n)
{
  int i = 0, pf;
  while (pf = pr[i++], pf * pf <= n)
  {
    if (n % pf == 0) fatoresM.push_back(ii(pf, 0));
    while (n % pf == 0) n /= pf, ++fatoresM.back().second;
  }
  if (n > 1) fatoresM.push_back(ii(n, 1));
}

int main()
{
  init();
  fatoresM.reserve(10000);

  int n, m, fail, power;
  ll i;
  double diff;

  while (scanf("%d%d", &n, &m) == 2)
  {
    fatoresM.clear(), fatora(m);

    fail = 0;
    for (auto it : fatoresM)
    {
      power = 0;
      diff = 1.0 / (double)it.first;
      for (i = n / it.first; i; i *= diff) power += i;
      if (power < it.second)
      {
        fail = 1;
        break;
      }
    }

    if (fail) printf("%d does not divide %d!\n", m, n);
    else      printf("%d divides %d!\n", m, n);
  }

  return 0;
}
