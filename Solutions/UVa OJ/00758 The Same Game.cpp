#include <bits/stdc++.h>
using namespace std;

struct str
{
  int i, j;
};

vector < vector < char > > mat;
int rep, cor;
str ch[10000], u;

inline bool maius(char c)
{
  return c >= 'A' && c <= 'Z';
}

int cont(int i, int j)
{
  mat[i][j] = rep;
  int ans = 1;

  if (i + 1 < (int)mat.size() && j < (int)mat[i + 1].size() && mat[i + 1][j] == cor)
    ans += cont(i + 1, j);
  if (i - 1 >= 0 && j < (int)mat[i - 1].size() && mat[i - 1][j] == cor)
    ans += cont(i - 1, j);
  if (j + 1 < (int)mat[i].size() && mat[i][j + 1] == cor)
    ans += cont(i, j + 1);
  if (j - 1 >= 0 && mat[i][j - 1] == cor)
    ans += cont(i, j - 1);

  return ans;
}

void fill(int i, int j)
{
  mat[i][j] = 0;

  if (i + 1 < (int)mat.size() && j < (int)mat[i + 1].size() && mat[i + 1][j] == cor)
    fill(i + 1, j);
  if (i - 1 >= 0 && j < (int)mat[i - 1].size() && mat[i - 1][j] == cor)
    fill(i - 1, j);
  if (j + 1 < (int)mat[i].size() && mat[i][j + 1] == cor)
    fill(i, j + 1);
  if (j - 1 >= 0 && mat[i][j - 1] == cor)
    fill(i, j - 1);
}

int main()
{
  register int i, j;
  int teste, tot, mov, max, col, mai, maj, points, rem, num, row, game = 0;

  scanf("%d", &teste);
  while (teste--)
  {
    printf("Game %d:\n\n", ++game);
    mat.assign(15, vector < char > (10));

    for (j = 10; j--; )
      for (i = -1; ++i < 15; )
        scanf(" %c", &mat[i][j]);
/*
printf("--------------------------------------------------\n");
for (i = -1; ++i < (int)mat.size(); )
{
  for (j = -1; ++j < (int)mat[i].size(); )
    printf(" %c", mat[i][j]);
  printf("\n");
}
printf("--------------------------------------------------\n");
scanf(" ");
//*/
    for (tot = mov = 0; ;)
    {
      // maius
      row = mat.size();
      for (i = -1, max = 0; ++i < row; )
      {
        col = mat[i].size();
        for (j = -1; ++j < col; )
          if (maius(mat[i][j]))
          {
            cor = mat[i][j];
            rep = mat[i][j] + 32;
            if ((num = cont(i, j)) > max)
            {
              max = num;
              mai = i;
              maj = j;
            }
          }
      }
      if (max == 1)
        break;

      points = (max - 2) * (max - 2);
      printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
        ++mov, maj + 1, mai + 1, max, mat[mai][maj] - 32, points);
      tot += points;

      cor = mat[mai][maj];
      rep = 0;
      fill(mai, maj);
      for (i = mat.size(); i--; )
        for (j = mat[i].size(); j--; )
          if (!mat[i][j])
            mat[i].erase(mat[i].begin() + j);
      for (i = mat.size(); i--; )
        if (mat[i].empty())
          mat.erase(mat.begin() + i);
      if (mat.empty())
        break;
/*
printf("--------------------------------------------------\n");
for (i = -1; ++i < (int)mat.size(); )
{
  for (j = -1; ++j < (int)mat[i].size(); )
    printf(" %c", mat[i][j]);
  printf("\n");
}
printf("--------------------------------------------------\n");
scanf(" ");
//*/



      // minus
      row = mat.size();
      for (i = -1, max = 0; ++i < row; )
      {
        col = mat[i].size();
        for (j = -1; ++j < col; )
          if (!maius(mat[i][j]))
          {
            cor = mat[i][j];
            rep = mat[i][j] - 32;
            if ((num = cont(i, j)) > max)
            {
              max = num;
              mai = i;
              maj = j;
            }
          }
      }
      if (max == 1)
        break;

      points = (max - 2) * (max - 2);
      printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
        ++mov, maj + 1, mai + 1, max, mat[mai][maj], points);
      tot += points;

      cor = mat[mai][maj];
      rep = 0;
      fill(mai, maj);
      for (i = mat.size(); i--; )
        for (j = mat[i].size(); j--; )
          if (!mat[i][j])
            mat[i].erase(mat[i].begin() + j);
      for (i = mat.size(); i--; )
        if (mat[i].empty())
          mat.erase(mat.begin() + i);
      if (mat.empty())
        break;
/*
printf("--------------------------------------------------\n");
for (i = -1; ++i < (int)mat.size(); )
{
  for (j = -1; ++j < (int)mat[i].size(); )
    printf(" %c", mat[i][j]);
  printf("\n");
}
printf("--------------------------------------------------\n");
scanf(" ");
//*/
    }

    rem = 0;
    if (mat.empty())
      tot += 1000;
    else
      for (i = mat.size(); i--; )
        rem += mat[i].size();

    printf("Final score: %d, with %d balls remaining.%s", tot, rem, (teste ? "\n\n" : "\n"));
  }

  return 0;
}
