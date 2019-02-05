#include <bits/stdc++.h>
using namespace std;

#define reg register
#define MAXP 31700      // sqrt(1e9) ≃ 31622.776601684

typedef long long ll;

int t, nmax, vmax, l, u, n;
bitset<MAXP> epr;
vector<int> pr;

void init (reg ll n = MAXP)
{
  epr.set();
  epr[0] = epr[1] = 0;
  pr.reserve((int)(n / log(n)) << 1);

  reg ll i, j;
  for (i = 2; i < n; ++i)
    if (epr[i])
    {
      pr.push_back(i);
      for (j = i * i; j < n; j += i)
        epr[j] = 0;
    }
}

int ndiv (int k)
{
  int i = 0, f, n = 1, cnt;

  while (f = pr[i++], f * f <= k)
  {
    cnt = 0;
    while (k % f == 0) k /= f, ++cnt;
    n *= cnt + 1;
  }

  if (k > 1) return n << 1;
  return n;
}

int main()
{
  init();

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &l, &u);

    nmax = -1e9;
    for (reg int i = l, j = u; i <= j; ++i)
    {
      n = ndiv(i);
      if (n > nmax)
        nmax = n, vmax = i;
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, vmax, nmax);
  }

  return 0;
}
