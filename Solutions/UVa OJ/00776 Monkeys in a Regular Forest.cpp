#include <cstdio>

//#define T
#define MAX 5000

char mat[MAX][MAX] = {0}, com, ini;
int monk[MAX][MAX], ident[MAX], cor, r, c;

void col(register int i, register int j)
{
  if (i >= 0 && i < r && j >= 0 && j < c && mat[i][j] == ini)
  {
    mat[i][j] = 0;
    monk[i][j] = cor;
    col(i, j + 1);
    col(i, j - 1);
    col(i + 1, j);
    col(i + 1, j + 1);
    col(i + 1, j - 1);
    col(i - 1, j);
    col(i - 1, j + 1);
    col(i - 1, j - 1);
  }
}

int main()
{
  bool cont = 1;
  register int i, j;

  while (cont)
  {
    i = j = 0;
    while (scanf("%1[A-Za-z\n%% ]", &com) != EOF && com != '%')
      if (com != ' ')
      {
        if (com == '\n')
        {
          c = j;
          j = 0;
          i++;
        }
        else
          mat[i][j++] = com;
      }
    if (com != '%')
      cont = 0;
    else
      scanf("%*c"); // other \n
    r = i;
#ifdef T
    printf("-----------------\n%d %d\n", r, c);
    for (i = 0; i < r; i++)
    {
      printf("%d : ", i);
      for (j = 0; j < c; j++)
        printf("%c ", mat[i][j]);
      printf("\n");
    }
    printf("-----------------\n");
#endif
    cor = 1;
    for (i = -1; ++i < r; )
      for (j = -1; ++j < c; )
        if (mat[i][j])
        {
          ini = mat[i][j];
          col(i, j);
          cor++;
        }
    for (j = -1; ++j < c; )
    {
      ident[j] = -1;
      for (i = -1; ++i < r; )
        if (monk[i][j] > ident[j])
          ident[j] = monk[i][j];
      i = 0;
      while (ident[j])
      {
        ident[j] /= 10;
        i++;
      }
      ident[j] = i;
    }
    for (i = -1; ++i < r; )
    {
      printf("%*d", ident[0], monk[i][0]);
      for (j = 0; ++j < c; )
        printf(" %*d", ident[j], monk[i][j]);
      printf("\n");
    }
    printf("%%\n");
  }

  return 0;
}
