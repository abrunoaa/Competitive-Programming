#include <bits/stdc++.h>
using namespace std;

#define MAX 20000010

bitset<MAX> epr;
vector<int> pr, tp;

void sieve (int n = MAX)
{
  long long i, j;

  epr.set();
  epr[0] = epr[1] = 0;
  pr.reserve(n / log(n) * 1.1);
  for (i = 0; i < n; ++i)
    if (epr[i])
    {
      pr.push_back(i);
      for (j = i * i; j < n; j += i)
        epr[j] = 0;
    }
}

void twin (int s = 100001)
{
  for (int i = 1, sz = pr.size(); s && i < sz; ++i)
    if (pr[i] - pr[i - 1] == 2)
    {
      tp.push_back(i);
      --s;
    }
}

int main()
{
  sieve();
  twin();

  int s;

  while (scanf("%d", &s) == 1)
    printf("(%d, %d)\n", pr[tp[s - 1] - 1], pr[tp[s - 1]]);

  return 0;
}
