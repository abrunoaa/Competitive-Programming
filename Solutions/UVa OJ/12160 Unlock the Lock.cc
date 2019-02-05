#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;

int main()
{
  freopen("in", "r", stdin);

  register int u, i, x;
  int lk, un, r, caso = 0, botao[20];
  const int inf = 1e9;
  queue < int > q;
  vi dis;

  while (scanf("%d%d%d", &lk, &un, &r), lk || un || r) {
    for (i = 0; i < r; ++i)
      scanf("%d", botao + i);

    dis.assign(10005, inf);         // flag p/ inf
    dis[lk] = 0;                    // qtde ate o cod inicial

    // bfs
    q.push(lk);                     // insere o 1º cod
    while (!q.empty()) {
      u = q.front();                // pega o prox
      if (u == un)                  // chegou no codigo
        break;
      q.pop();

      for (i = 0; i < r; ++i) {     // percorre todos os botoes
        x = (u + botao[i]) % 10000; // pega os 4 ultimos digitos do atual + um botao

        if (dis[x] == inf) {        // se nao visitou: visita
          dis[x] = dis[u] + 1;      // qtde == qtde ate anterior + 1
          q.push(int(x));           // insere p/ processar
        }
      }
    }
    // \bfs

    printf("Case %d: ", ++caso);
    if (dis[un] == inf)             // não chegou no unlock
      puts("Permanently Locked");
    else {
      printf("%d\n", dis[un]);      // qtde ate unlock
      do q.pop();                   // ESVAZIA PORRA!!!!!!!!!
      while (!q.empty());
    }
  }

  return 0;
}
