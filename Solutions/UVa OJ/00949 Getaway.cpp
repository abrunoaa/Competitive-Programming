#include <cstdio>

int main()
{
  while (scanf("%d%d", &nv, &nh) > 0)
  {
    for (i = nv * 2; --i; )
      for (j = nh * 2; --j; mat[i][j] = 1);
    for (i = nv * 2; (i -= 2) > 0; )
      for (j = nh * 2; (j -= 2) > 0; mat[i][j] = 0);
    for (j = nh * 2 + 1, i = nv * 2 + 1; --i; mat[i][j] = 0);
    for (i = nv * 2 + 1; --j; mat[i][j] = 0);

    scanf("%d", &r);
    while (r--)
    {
      scanf("%d%d%d%d", &c1, &l1, &c2, &l2);
      l1 = l1 * 2 + 1;
      l2 = l2 * 2 + 1;
      c1 = c1 * 2 + 1;
      c2 = c2 * 2 + 1;

      if (l1 == l2)
        if (c1 < c2)
          if (mat[l1][++c1] > 0)
            mat[l1][c1] = -1;
          else
            mat[l1][c1] = 0;
        else
          if (mat[l1][--c1] > 0)
            mat[l1][c1] = -2;
          else
            mat[l1][c1] = 0;
      else
        if (l1 < l2)
          if (mat[++l1][c1] > 0)
            mat[l1][c1] = -1;
          else
            mat[l1][c1] = 0;
        else
          if (mat[--l1][c1] > 0)
            mat[l1][c1] = -2;
          else
            mat[l1][c1] = 0;
    }

    scanf("%d", &m);
    while (m--)
    {
      scanf("%d%d%d", &t, &c, &l);
      mp[t] = {l, c};
    }

    mp.clear();
  }

  return 0;
}
