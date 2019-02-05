#include <bits/stdc++.h>
using namespace std;

int n, m, ans, flag, weight[11][105], dp[11][105];
vector < int > print;

int tsp (int l, int c)
{
  // base
  if (c == n) return 0;
  if (l < 0) l = m - 1;
  else if (l == m) l = 0;

  // dp
  int &ref = dp[l][c];
  if (ref != -1) return ref;

  // recursao
  ref = tsp(l - 1, c + 1);
  ref = min(ref, tsp(l, c + 1));
  ref = min(ref, tsp(l + 1, c + 1));

  return ref += weight[l][c];
}

void path (int l, int c)
{
  // base
  if (c == n) return;
  if (l < 0) l = m - 1;
  else if (l == m) l = 0;

  // caminho
  if (flag) printf(" ");
  else      flag = 1;
  printf("%d", l + 1);

  int v = dp[l][c] - weight[l][c];  // peso
  if (l == m - 1)                   // varia ordem de visita
  {
    if (v == tsp(l + 1, c + 1))
      return path(l + 1, c + 1);
    if (v == tsp(l - 1, c + 1))
      return path(l - 1, c + 1);
    return path(l, c + 1);
  }

  if (l)
  {
    if (v == tsp(l - 1, c + 1))
      return path(l - 1, c + 1);
    if (v == tsp(l, c + 1))
      return path(l, c + 1);
    return path(l + 1, c + 1);
  }

  if (v == tsp(l, c + 1))
    return path(l, c + 1);
  if (v == tsp(l + 1, c + 1))
    return path(l + 1, c + 1);
  return path(l - 1, c + 1);
}

int main()
{
  register int i, j;

  while (scanf("%d%d", &m, &n) == 2)
  {
    for (i = 0; i < m; ++i)
      for (j = 0; j < n; ++j)
      {
        scanf("%d", weight[i] + j);
        dp[i][j] = -1;                // reseta dp
      }

    ans = 1e9;                        // inf
    for (i = 0; i < m; ++i)           // varia as linhas para começar
      if (tsp(i, 0) < ans)            // se for o menor caminho
      {
        ans = tsp(i, 0);
        j = i;
      }

    flag = 0;                         // flag para imprimir espaço
    path(j, 0);                       // imprime o caminho
    printf("\n%d\n", ans);
  }

  return 0;
}
