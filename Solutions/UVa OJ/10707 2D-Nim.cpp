#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("../cpp source code/input/10707.txt", "r", stdin);
#endif

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d%d%d", &w, &h, &n);
    for (i = n; i--; )
    {
      scanf("%d%d", &x, &y);
      mat1[y][x] = 1;
    }
    for (i = n; i--; )
    {
      scanf("%d%d", &x, &y);
      mat2[y][x] = 1;
    }
    
    for (i = h; i--; )
    {
      for (j = w; j--; )
        if (mat1[i][j])
        {
          num = 1;
          while (j-- && mat1[i][j])
            num++;
          if (j < 0)
            j = 0;
          l1[num]++;
        }
      for (j = w; j--; )
        if (mat2[i][j])
        {
          num = 1;
          while (j-- && mat2[i][j])
            num++;
          if (j < 0)
            j = 0;
          l2[num]++;
        }
    }
    for (j = w; j--; )
    {
      for (i = h; i--; )
        if (mat1[i][j])
        {
          num = 1;
          while (i-- && mat1[i][j])
            num++;
          if (i < 0)
            i = 0;
          c1[num]++;
        }
      for (i = h; i--; )
        if (mat2[i][j])
        {
          num = 1;
          while (i-- && mat2[i][j])
            num++;
          if (i < 0)
            i = 0;
          c2[num]++;
        }
    }
  }

  return 0;
}
