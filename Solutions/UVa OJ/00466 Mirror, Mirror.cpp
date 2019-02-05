#include <cstdio>

//#define T

int main()
{
  char mat1[15][15], mat2[15][15];
  register int i, j, ii, jj;
  int n, count = 0;

  while (scanf("%d", &n) != EOF)
  {
    for (i = -1; ++i < n; )
    {
      for (j = -1; ++j < n; )
        scanf(" %1c", &mat1[i][j]);
      for (j = -1; ++j < n; )
        scanf(" %1c", &mat2[i][j]);
    }
#ifdef T
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        printf("%c ", mat1[i][j]);
      printf(" | ");
      for (j = 0; j < n; j++)
        printf("%c ", mat2[i][j]);
      printf("\n");
    }
#endif
    j = n;
    for (i = -1; ++i < n && j == n; )
      for (j = -1; ++j < n && mat1[i][j] == mat2[i][j]; );
    if (i == n)
    {
      printf("Pattern %d was preserved.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1, ii = n - 1; ++i < n && j == n; ii--)
      for (j = -1; ++j < n && mat1[i][j] == mat2[j][ii]; );
    if (i == n)
    {
      printf("Pattern %d was rotated 90 degrees.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1, ii = n - 1; ++i < n && j == n; ii--)
      for (j = -1, jj = n - 1; ++j < n && mat1[i][j] == mat2[ii][jj]; jj--);
    if (i == n)
    {
      printf("Pattern %d was rotated 180 degrees.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1, ii = 0; ++i < n && j == n; ii++)
      for (j = -1, jj = n - 1; ++j < n && mat1[i][j] == mat2[jj][ii]; jj--);
    if (i == n)
    {
      printf("Pattern %d was rotated 270 degrees.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1, ii = n - 1; ++i < n && j == n; ii--)
      for (j = -1; ++j < n && mat1[i][j] == mat2[ii][j]; );
    if (i == n)
    {
      printf("Pattern %d was reflected vertically.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1; ++i < n && j == n; )
      for (j = -1; ++j < n && mat1[i][j] == mat2[j][i]; );
    if (i == n)
    {
      printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1; ++i < n && j == n; )
      for (j = -1, jj = n - 1; ++j < n && mat1[i][j] == mat2[i][jj]; jj--);
    if (i == n)
    {
      printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", ++count);
      continue;
    }

    j = n;
    for (i = -1, ii = n - 1; ++i < n && j == n; ii--)
      for (j = -1, jj = n - 1; ++j < n && mat1[i][j] == mat2[jj][ii]; jj--);
    if (i == n)
    {
      printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", ++count);
      continue;
    }

    printf("Pattern %d was improperly transformed.\n", ++count);
  }

  return 0;
}
