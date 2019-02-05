// dp - dp nao classica
// dp de uma dimensao pois ao pegar um amburguer de m ou de n, sempre retorna max

#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;

int m, n, t;
ii ans, dp[10001];

ii operator + (int n, ii v)
{ return ii(v.first, v.second + n); }

// knapsack
// time = tempo que ja passou
ii ks (int time)
{
  // dp
  ii &ref = dp[time];
  if (ref.first != -1)
    return ref;

  // recursao
  if (time + m <= t && time + n <= t)
    ref = 1 + max(ks(time + m), ks(time + n));
  else if (time + m <= t)
    ref = 1 + ks(time + m);
  else if (time + n <= t)
    ref = 1 + ks(time + n);
  else
    ref = ii(time, 0);

  return ref;
}

int main()
{
  register int i, cs = 0;

  while (scanf("%d%d%d", &m, &n, &t) == 3)
  {
    for (i = 0; i <= t; ++i) dp[i].first = -1;
    ans = ks(0);

    printf("%d", ans.second);
    if (ans.first != t) printf(" %d", t - ans.first);
    puts("");
  }

  return 0;
}
