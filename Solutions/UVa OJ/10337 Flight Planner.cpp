#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int t, x, n;
int w[10][1005], dp[10][1005];

// checa todas as possibilidades
// l = linha
// c = coluna
int fly (int l, int c) {
  // chegou ao fim: deve estar na ultima linha
  if (c == n) { return (l < 9 ? inf : 0); }

  // dp
  int &ref = dp[l][c];
  if (ref) { return ref; }

  // recursao
  ref = 30 + fly(l, c + 1);                           // segue reto
  if (l < 9) { ref = min(ref, 20 + fly(l + 1, c + 1)); }  // desce
  if (l > 0) { ref = min(ref, 60 + fly(l - 1, c + 1)); }  // sobe

  return ref -= w[l][c];                              // + windstrength
}

int main() {
  register int i, j;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &x);
    n = x / 100;                  // nº de entradas

    for (i = 0; i <= 9; ++i)      // nv 0~9
      for (j = 0; j < n; ++j) {   // n windstrengths
        scanf("%d", w[i] + j);
        dp[i][j] = 0;             // reseta dp
      }

    printf("%d\n\n", fly(9, 0));
  }

  return 0;
}
