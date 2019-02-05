#include <bits/stdc++.h>
using namespace std;

int T, i, n, g, mw, ans;
int p[1002], w[1002], dp[32][1002];

// knap sack
// rem = disponível, id = posição atual
int buy (int rem, int id)
{
  if (rem <= 0 || id == n) return 0;            // caso base
  if (dp[rem][id] != -1)   return dp[rem][id];  // já calculado
  if (w[id] > rem)                              // só pode ignorar
    return dp[rem][id] = buy(rem, id + 1);

  // pode ignorar ou pegar
  return dp[rem][id] = max(buy(rem, id + 1), p[id] + buy(rem - w[id], id + 1));
}

int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);                            // n = nº de objetos

    for (i = 0; i < n; ++i)
      scanf("%d%d", p + i, w + i);              // p = preço, w = peso

    scanf("%d", &g);                            // nº de pessoas
    ans = 0;
    while (g--)
    {
      memset(dp, -1, sizeof dp);                // reinicia memo
      scanf("%d", &mw);                         // peso q a g-ésima pessoa carrega
      ans += buy(mw, 0);                        // cada pessoa carrega um pouco
    }

    printf("%d\n", ans);
  }

  return 0;
}
