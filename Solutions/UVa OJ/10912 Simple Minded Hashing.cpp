#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cs = 0, l, s;
int dp[400][26][27];

// conta qtde de strings
// sum = soma
// len = comprimento
//   c = char atual considerado
int substr (int sum, int len, int c) {
  // base
  if (sum == s && len == l) { return 1; }            // chegou ao fim
  if (sum >= s || len >= l || c > 26) { return 0; }  // estado invalido

  // dp
  int &ref = dp[sum][len][c];
  if (ref != -1) { return ref; }

  // ignora esta letra + aceita
  return ref = substr(sum, len, c + 1) + substr(sum + c, len + 1, c + 1);
}

int main() {
  while (scanf("%d%d", &l, &s), l || s) {
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", ++cs, substr(0, 0, 1));
  }

  return 0;
}
