#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k, n, m, x, y;

  while (scanf("%d", &k), k)
  {
    scanf("%d%d", &n, &m);
    while (k--)
    {
      scanf("%d%d", &x, &y);
      if (x == n || y == m)
        puts("divisa");
      else
        if (x < n)
          if (y < m)
            puts("SO");
          else
            puts("NO");
        else
          if (y < m)
            puts("SE");
          else
            puts("NE");
    }
  }

  return 0;
}
