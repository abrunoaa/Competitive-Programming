#include <bits/stdc++.h>
using namespace std;

int n, q, d, m;
int num[205], dp[11][201][201];

// (a0 + ... + an) % x = (a0 % x + ... + an % x) % x

// knapsack
//  m = qtde de números para escolher
// id = posição
//  s = soma atual
int sum(int m, int id, int s)
{
  if (!m)                 return s % d == 0;    // escolheu m números
  if (id == n)            return 0;             // acabou números
  if (dp[m][id][s] != -1) return dp[m][id][s];  // já calculou

  // exclui/inclui este número da sequência de números
  return dp[m][id][s] = sum(m, id + 1, s) + sum(m - 1, id + 1, s + num[id] % d);
}

int main()
{
  register int i, st = 0, qy;

  while (scanf("%d%d", &n, &q), n || q)         // n = qtde de números
  {                                             // q = qtde de perguntas
    for (i = 0; i < n; ++i)                     // num = números
      scanf("%d", num + i);

    printf("SET %d:\n", ++st);
    qy = 0;
    while (q--)
    {
      scanf("%d%d", &d, &m);                    // d = nº para dividir
                                                // m = qtde de nº para escolher
      memset(dp, -1, sizeof dp);
      printf("QUERY %d: %d\n", ++qy, sum(m, 0, 0));
    }
  }

  return 0;
}
