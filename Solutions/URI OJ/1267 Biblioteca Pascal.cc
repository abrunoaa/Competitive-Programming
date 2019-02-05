#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, d, i, janta;
  bool aluno[105];

  while (scanf("%d%d", &n, &d), n || d)
  {
    memset(aluno, 1, sizeof aluno);     // todos participam
    while (d--)
      for (i = 0; i < n; ++i)           // verifica participações no jantar
      {
        scanf("%d", &janta);            // participou?
        aluno[i] &= janta;              // det. se participa de todos
      }

    for (i = 0; i < n; ++i)             // procura um que participa de todos
      if (aluno[i])
        break;

    if (i < n) puts("yes");             // achou
    else       puts("no");
  }

  return 0;
}
