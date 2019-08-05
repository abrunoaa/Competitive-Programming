#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, qtd, flag, x[5005];

  while (scanf("%d", &n), n) {
    qtd = flag = 0;

    scanf("%d", x);                             // lê o 1º
    for (i = 1; i < n; ++i) {                   // lê o restante
      scanf("%d", x + i);
      if (!x[i] && !x[i - 1]) {                 // não pode ter dois espaços
        // consecutivos vazios
        if (i == 1) {                           // caso: 0 0 1 1 0
          flag = 1;
        }
        x[i] = 1;                               // põe a cerca
        ++qtd;                                  // +1 cerca
      }
    }

    if (!x[0] && !x[n - 1] && (!flag || !x[2])) { // verif. se precisa de cerca nas
      ++qtd;  // "pontas"
    }

    printf("%d\n", qtd);
  }

  return 0;
}
