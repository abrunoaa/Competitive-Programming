#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("in", "r", stdin);

  int t, d, i, l[10010], h[10010], q, p, flag, j;
  char m[10010][25];

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &d);
    for (i = 0; i < d; ++i)
      scanf(" %s%d%d", m[i], l + i, h + i);

    scanf("%d", &q);
    while (q--)
    {
      scanf("%d", &p);

      flag = 0;
      for (i = 0; i < d; ++i)       // varia veiculos
        if (p >= l[i] && p <= h[i])
        {                           // pode pegar esse
          if (flag)
          {                         // achou dois: para
            flag = 0;
            break;
          }

          flag = 1;                 // seta flag
          j = i;                    // salva nome
        }

      if (flag) printf("%s\n", m[j]);
      else      puts("UNDETERMINED");
    }

    if (t) puts("");
  }

  return 0;
}
