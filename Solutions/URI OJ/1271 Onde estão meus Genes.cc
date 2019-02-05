#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;

int main()
{
  int i, n, r, q, pos, gen = 0;
  ii inv[1005];

  while (scanf("%d%d", &n, &r) > 0 && n)
  {
    for (i = 0; i < r; ++i)                               // lê as inversões
      scanf("%d%d", &inv[i].first, &inv[i].second);

    printf("Genome %d\n", ++gen);
    scanf("%d", &q);
    while (q--)
    {
      scanf("%d", &pos);                                  // lê a posição inicial
      for (i = 0; i < r; ++i)                             // inverte apenas o inicial
        if (pos >= inv[i].first && pos <= inv[i].second)
          pos = inv[i].first + inv[i].second - pos;
      printf("%d\n", pos);
    }
  }

  return 0;
}
