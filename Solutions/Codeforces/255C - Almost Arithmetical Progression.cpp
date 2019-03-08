#include <bits/stdc++.h>
using namespace std;

int main()  // 11.639s >> FU***!!!
{
  register int n, i, j, q, maxq, aux;
  int N, b[4005], r, rep[1000005] = {}, *paux;
  map < int, int > dp[4005];

  scanf("%d", &N);
  //N = 4000;
  n = N;

  if (n <= 2)                               // so pode ter uma sequencia de n valores
    maxq = n;
  else
  {
    maxq = 2;                                     // minimo possivel / precisa?
    for (i = 0; i < n; ++i)
    {
      scanf("%d", b + i);
      //b[i] = i;
      ++rep[b[i]];                                // qtd de vezes q bi aparece
    }
/*
for (i = 0; i < n; ++i)
  printf("%d ", b[i]);
puts("\n");
for (i = 0; i <= 1e6; ++i)
  if (rep[i])
    printf(" -> %d rep %d\n", i, rep[i]);
puts("");
//*/
    for (i = 0; ++i < n;)                        // loop normal / pos 0 desnecessaria
      for (j = i; --j >= 0; )                     // volta contando
        if (rep[b[i]] > 1 || rep[b[j]] > 1)       // checa se pode ter sequencia???
        {
          r = b[i] - b[j];                        // ** i > j **
          q = ((aux = dp[j][r]) ? aux + 1 : 2);   // se ja foi calculado: aproveita
                                                  // >> TEM i E j NA SEQUENCIA == 2
//printf(" ## %d %d == %d %d\n", i, j, r, q);
          r *= -1;                // a proxima sequencia inverte a razao: 1 <- 2 <- 1
          if (q > *(paux = &dp[i][r]))        // se é maior q a sequencia atual em dp
          {
//printf("   >> %d %d : %d %d\n", i, r, q, maxq);
            if ((*paux = q) > maxq)               // atualiza / se é o maior de todos
              maxq = q;
          }
        }
  }

  printf("%d\n", maxq);

  return 0;
}
