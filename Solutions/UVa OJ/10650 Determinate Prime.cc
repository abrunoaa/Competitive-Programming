#include <bits/stdc++.h>
using namespace std;

#define MAX 35000
#define pb push_back

bitset<MAX> epr;
vector<int> pr;

void gera ()
{
  int i, j;

  epr.set();
  epr[0] = epr[1] = 0;
  for (i = 2; i < MAX; ++i)
    if (epr[i])
    {
      pr.pb(i);
      for (j = i * i; j < MAX; j += i)
        epr[j] = 0;
    }
}

int main()
{
  int i, j, x, y;

  gera ();
  while (scanf("%d%d", &x, &y) == 2 && (x || y))
  {
    if (x > y) swap(x, y);
    for (i = lower_bound(pr.begin(), pr.end(), x) - pr.begin() + 2; pr[i] <= y; ++i)
      if (pr[i] - pr[i - 1] == pr[i - 1] - pr[i - 2])
      {
        for (j = i + 1; pr[j] - pr[j - 1] == pr[j - 1] - pr[j - 2]; ++j);
        if (i > 2 && pr[i - 1] - pr[i - 2] != pr[i - 2] - pr[i - 3] && pr[--j] <= y)
        {
          printf("%d %d", pr[i - 2], pr[i - 1]);
          for (; i <= j; ++i)
            printf(" %d", pr[i]);
          puts("");
        }
      }
  }

  return 0;
}

