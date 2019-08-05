#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);

  int n, m, v, i, j, turn, turn1, ans[100010];
  map < int, int > mp;

  while (scanf("%d%d", &n, &m), n || m) {
    for (i = 0; i < n; ++i) {     // reseta resposta
      ans[i] = -1;
    }
    for (i = 1; i <= m; ++i) {    // valores para o vetor
      scanf("%d", &turn);         // lê a qtde de trocas
      turn1 = turn;               // salva pos
      do {
        v = mp[turn];             // pega a posição do próximo no vetor
        if (!v) {                 // ainda não foi pego
          v = turn;  // novo valor
        }
        turn = v;                 // troca valor para evitar loop
      } while (mp[v]);            // enquanto a posição já estiver ocupada

      ans[v] = i;                 // salva vetor resposta
      mp[turn1] = v + 1;          // salva posição
    }

    for (j = 0; j < n; ++j)       // preenche o que faltou
      if (ans[j] == -1) {
        ans[j] = i++;
      }

    printf("%d", ans[0]);         // 1º nº
    for (i = 1; i < n; ++i) {     // imprime os demais
      printf(" %d", ans[i]);
    }
    puts("");

    mp.clear();
  }

  return 0;
}
