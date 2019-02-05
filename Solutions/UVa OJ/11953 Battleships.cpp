#include <cstdio>

char x, m[105][105];
int n;

void col(int i, int j)
{
  if (m[i][j] == 'x')
    x = 1;
  m[i][j] = '.';
  if (i + 1 < n  && m[i + 1][j] != '.') col(i + 1, j);
  if (i - 1 >= 0 && m[i - 1][j] != '.') col(i - 1, j);
  if (j + 1 < n  && m[i][j + 1] != '.') col(i, j + 1);
  if (j - 1 >= 0 && m[i][j - 1] != '.') col(i, j - 1);
}

int main()
{
  register int i, j, ship, count = 0;
  int teste;

  scanf("%d", &teste);
  while (teste--)
  {
    scanf("%d", &n);
    for (i = -1; ++i < n; scanf(" %[^\n]s", m[i]));
/*
printf(" >> %d\n", n);
for (i = 0; i < n; i++)
{
  for (j = 0; j < n; j++)
    printf("%c", m[i][j]);
  printf("\n");
}
//*/
    for (i = n, ship = 0; i--; )
      for (j = n; j--; )
        if (m[i][j] != '.')
        {
          x = 0;
//printf("%d %d\n", i, j);
          col(i, j);
          if (x)
            ship++;
        }
/*
printf("--------------\n");
for (i = 0; i < n; i++)
{
  for (j = 0; j < n; j++)
    printf("%c", m[i][j]);
  printf("\n");
}
//*/
    printf("Case %d: %d\n", ++count, ship);
  }

  return 0;
}
