// dp - janela deslizante

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int n, c, tira1, tira2, i, ans, lim;
int furo[2005], dp[2005];

// custo para cobrir os furos de i até id
int cobre (int id)
{
  // chegou ao fim: 0cm de tira necessária (acabou os furos!)
  if (id == n) return 0;

  // dp
  int& ref = dp[id];
  if (ref != -1) return ref;

  // conta quantos furos pode cobrir com uma tira a partir de id
  int j, k;
  for (j = id + 1; j < n && furo[id] + tira1 >= furo[j]; ++j);
  for (k = id + 1; k < n && furo[id] + tira2 >= furo[k]; ++k);

  // procura qual é o melhor para cobrir id: tira1 ou tira2
  return ref = min(cobre(j) + tira1, cobre(k) + tira2);
}

int main()
{
  while (scanf("%d%d%d%d", &n, &c, &tira1, &tira2) == 4)
  {
    for (i = 0; i < n; ++i)
    {
      scanf("%d", furo + i);      // 1ª volta no pneu
      furo[i + n] = furo[i] + c;  // após uma volta completa no pneu
    }

    ans = inf;
    lim = n;                      // salva valor original de n
    for (i = 0; i < lim; ++i)
    {
      memset(dp + i, -1, n << 2); // reseta
      ans = min(ans, cobre(i));   // cobre de i até n (n furos)
      ++n;                        // "desliza" para frente
    }

    printf("%d\n", ans);
  }

  return 0;
}
