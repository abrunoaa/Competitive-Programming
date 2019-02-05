//

#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;

ii p[] = {ii(0,1), ii(0,0), ii(1,0), ii(2,0), ii(2,1), ii(2,2), ii(1,2), ii(0,2), ii('e', 'e')};

int main()
{
  bool sur[5][5];
  register int i;
  int x, y, d, x1, y1, s;

  while (scanf("%d", &x), x != -1)
  {
    scanf("%d%d", &y, &d);
    for (i = 0; i < 8; ++i)
    {
      scanf("%d%d%d", &x1, &y1, &s);

      x1 -= x;
      y1 -= y;
      if (!x1)
      {
        if (y1 == 1)
          sur[0][1] = s;
        else
          sur[2][1] = s;
      }
      else if (x1 < 0)
      {
        if (!y1)
          sur[1][0] = s;
        else if (y1 > 0)
          sur[0][0] = s;
        else
          sur[2][0] = s;
      }
      else
      {
        if (!y1)
          sur[1][2] = s;
        else if (y1 > 0)
          sur[0][2] = s;
        else
          sur[2][2] = s;
      }
    }

    d -= 2;
    if (d < 0) d += 8;

    while (!sur[p[d].first][p[d].second])
      d = (d + 1) % 7;

    printf("%d\n", d);
  }
}
