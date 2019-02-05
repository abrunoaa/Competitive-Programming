#include <cstdio>
#include <cstring>

char x[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
char y[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int l, c, w;
char mat[105][105], ini, rep;

void col(register int i, register int j)
{
  if (i >= 0 && i < l && j >= 0 && j < c && mat[i][j] == ini)
  {
    mat[i][j] = rep;
    w++;
    for (register int k = -1; ++k < 8; col(i + x[k], j + y[k]));
  }
}

int main()
{
  int teste;
  register int i, j;

  scanf("%d", &teste);
  while (teste--)
  {
    i = 0;
    while (scanf(" %[LW]s", mat[i++]));
    c = i;
    l = strlen(mat[0]);
    while (scanf("%d%d", &i, &j) > 0)
    {
      i--; j--;
      ini = mat[i][j];
      rep = ini == 'W' ? 'A' : 'W';
      w = 0;
      col(i, j);
      printf("%d\n", w);
    }
    if (teste)
      printf("\n");
  }

  return 0;
}
