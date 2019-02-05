#include <cstdio>
#include <queue>
using namespace std;

//#define TESTE

struct str
{
  int i, j, k, dis;
};

int main()
{
  register int i, j, k;
  str u, s, e;
  int l, r, c, dis[35][35][35];
  char m[35][35][35];
  queue < str > q;

  for (i = 35; i--; )
    for (j = 35; j--; m[i][j][0] = m[i][0][j] = '!');

  while (scanf("%d%d%d", &l, &r, &c), l | r | c)
  {
    r++; c++;
    for (s.i = i = -1; ++i < l; )
    {
      for (j = 0; ++j < r; m[i][j][c] = '!')
      {
        scanf(" %[^\n]", m[i][j] + 1);
        for (k = c; --k; dis[i][j][k] = 1e9)
          if (m[i][j][k] == 'S')
          {
            m[i][j][k] = '.';
            s = {i, j, k, -1};
          }
      }
      for (k = c + 1; k--; m[i][j][k] = '!');
    }
#ifdef TESTE
    for (i = 0; i < l; i++)
    {
      for (j = 0; j <= r; j++)
      {
        for (k = 0; k <= c; k++)
          printf("%c", m[i][j][k]);
        printf("\n");
      }
      printf("\n");
    }
    printf(" >> %d %d %d | %d %d %d\n", i, j, k, l, r, c);
#endif
    k = 1;
    q.push(s);
    e.i = -1;
    while (!q.empty())
    {
      u = q.front();
      q.pop();
#ifdef TESTE
      printf(" - proc %2d %2d %2d, %2d | %d\n", u.i, u.j, u.k, u.dis, k);
#endif
      if (m[u.i][u.j][u.k] == '.' && dis[u.i][u.j][u.k] - 1e9 <= 0.0001)
      {
        m[u.i][u.j][u.k] = '!';
        dis[u.i][u.j][u.k] = u.dis + 1;

        if (u.i + 1 < l)    q.push({u.i + 1, u.j, u.k, u.dis + 1});
        if (u.i - 1 >= 0 )  q.push({u.i - 1, u.j, u.k, u.dis + 1});
        q.push({u.i, u.j + 1, u.k, u.dis + 1});
        q.push({u.i, u.j - 1, u.k, u.dis + 1});
        q.push({u.i, u.j, u.k + 1, u.dis + 1});
        q.push({u.i, u.j, u.k - 1, u.dis + 1});
      }
      else
        if (m[u.i][u.j][u.k] == 'E')
        {
          e = {u.i, u.j, u.k, u.dis + 1};
          i = q.size();
          while (i--)
            q.pop();
          break;
        }
    }

#ifdef TESTE
    for (i = 0; i < l; i++)
    {
      for (j = 1; j < r; j++)
      {
        for (k = 1; k < c; k++)
          printf("%2d ", dis[i][j][k] > 1e6 ? -1 : dis[i][j][k]);
        printf("\n");
      }
      printf("\n");
    }
    printf("\n");
#endif

    if (e.i == -1)
      printf("Trapped!\n");
    else
      printf("Escaped in %d minute(s).\n", e.dis);
  }

  return 0;
}
