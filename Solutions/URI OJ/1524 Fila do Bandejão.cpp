#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef pair < int, ii > iii;

const int inf = 1e9;
int n, k, i;
int vet[1001], dp[1001][1001];

// knapsack: procura os subgrupos
// rem = grupos que faltam
//  id = valor atual
int ks(int rem, int id) {
  // chegou ao fim:
  // se terminou retorna o último (é do último grupo)
  // senão inf (não formou todos os grupos)
  if (id == n) { return rem ? inf : vet[id - 1]; }

  // dp
  int &ref = dp[rem][id];
  if (ref != -1) { return ref; }

  // formou todos: apenas add o atual ao grupo anterior
  if (!rem) { return ref = ks(rem, id + 1); }

  // add o atual ao grupo anterior ou cria um novo a partir desse
  return ref = min(ks(rem, id + 1), ks(rem - 1, id + 1) - vet[id] + vet[id - 1]);
}

int main() {
  vet[0] = 0;                           // a1 = 0, sempre
  while (scanf("%d%d", &n, &k) == 2) {
    // reseta
    memset(dp, -1, sizeof dp);

    // entrada
    for (i = 1; i < n; ++i) {
      scanf("%d", vet + i);
    }

    // saída
    printf("%d\n", ks(k - 1, 1));
  }

  return 0;
}
