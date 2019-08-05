#include <bits/stdc++.h>
using namespace std;

int inf = 1e9, nt, t, w, i, gold, n, flag = 0;
int dp[1002][32], d[32], dor[32], g[32];
vector < int > ans;

// knap sack: t = tempo disponivel, p = posição
int recovery (int t, int p) {
  if (t <= 0 || p == nt) { return 0; }                    // não pode pegar mais/acabou
  if (dp[t][p] != -1) { return dp[t][p]; }                // já foi calculado
  if (d[p] > t) {                                     // só pode ignorar
    return dp[t][p] = recovery(t, p + 1);
  }

  // pode ignorar ou pegar
  return dp[t][p] = max(recovery(t, p + 1), g[p] + recovery(t - d[p], p + 1));
}

// recupera o caminho percorrido
void path (int t, int p) {
  if (t <= 0 || p == nt) { return; }                      // mesmo caso base

  if (d[p] <= t && recovery(t, p + 1) != dp[t][p]) {
    // obj p foi "pego"
    ans.push_back(p);
    path(t - d[p], p + 1);
  } else {
    path(t, p + 1);  // obj p foi ignorado
  }
}

int main() {
  ans.reserve(40);

  while (scanf("%d%d%d", &t, &w, &nt) > 0) {          // t = capacidade de ar
    // w = constante
    if (flag) { puts(""); }                               // nt = nº de tesouros
    else { flag = 1; }

    w *= 3;                                           // "1 * descida + 2 * subida"
    for (i = 0; i < nt; ++i) {
      scanf("%d%d", dor + i, g + i);                  // profundidade/quantidade
      d[i] = dor[i] * w;                              // custo para pegar este
    }

    memset (dp, -1, sizeof dp);                       // limpa a tabela de dp
    ans.clear();                                      // limpa o caminho

    gold = recovery(t, 0);                            // retorna o máximo possível
    path(t, 0);                                       // armazena caminho em 'ans'
    n = ans.size();                                   // total de "mergulhos"

    // solução
    printf("%d\n%d\n", gold, n);
    for (i = 0; i < n; ++i) {
      printf("%d %d\n", dor[ans[i]], g[ans[i]]);
    }
  }

  return 0;
}
