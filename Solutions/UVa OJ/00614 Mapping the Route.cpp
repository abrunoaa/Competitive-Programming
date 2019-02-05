// grafo implícito - flood fill - IO difícil

#include <bits/stdc++.h>
using namespace std;

#define GOAL -1
#define WALL -2
#define FAIL -3

int i, j, qtde, mat[30][30], nc, nl, ls, cs, lg, cg, d, maze = 0;
int L[] = { 0, -1, 0, 1}, C[] = { -1, 0, 1, 0};

bool move (int l, int c)
{
  if (mat[l][c] == GOAL)                // chegou ao fim
  {
    mat[l][c] = ++qtde;                 // qtde até ele
    return 1;                           // flag
  }

  if (!mat[l][c])                       // ainda não tentou
  {
    mat[l][c] = ++qtde;                 // qtde até ele
    for (int i = 0; i < 4; ++i)         // esq, cima, dir, baixo
      if (move(l + L[i], c + C[i]))     // checa se chega ao fim por aqui
        return 1;                       // flag

    mat[l][c] = FAIL;                   // tentou ir mas não conseguiu
    --qtde;                             // diminui qtde percorrida
  }

  return 0;
}

int main()
{
  while (scanf("%d%d%d%d%d%d", &nl, &nc, &ls, &cs, &lg, &cg),
                                                    nl || nc || ls || cs || lg || cg)
  {
    // converte todas as dimensões para ter espaço entre as células
    ls = (ls - 1) * 2 + 1;
    cs = (cs - 1) * 2 + 1;
    cg = (cg - 1) * 2 + 1;
    lg = (lg - 1) * 2 + 1;
    nl = nl * 2 + 1;
    nc = nc * 2 + 1;

    // reseta matriz
    memset(mat, 0, sizeof mat);
    for (i = 0; i < nl; i += 2)
      for (j = 0; j < nc; j += 2)
        mat[i][j] = WALL;               // flag para parede (entre linhas e colunas)

    // entrada da matriz
    for (i = 1; i < nl; i += 2)
      for (j = 1; j < nc; j += 2)
      {
        scanf("%d", &d);
        if (d == 1 || d == 3)           // muro a direita
          mat[i][j + 1] = WALL;
        if (d == 2 || d == 3)           // muro em baixo
          mat[i + 1][j] = WALL;
      }

    // cerca a matriz com parede
    for (i = 1; i < nl; i += 2) mat[i][0] = WALL;
    for (j = 1; j < nc; j += 2) mat[0][j] = WALL;
    for (i = nl - 1, j = 0; j < nc; ++j) mat[i][j] = WALL;
    for (i = 0, j = nc - 1; i < nl; ++i) mat[i][j] = WALL;

    mat[ls][cs] = 0;                    // início
    mat[lg][cg] = GOAL;                 // fim
    qtde = 0;                           // qtde percorrida até o momento
    move (ls, cs);                      // move do início

    // formata saida
    printf("Maze %d\n\n", ++maze);
    for (i = 0; i < nl; ++i)
    {
      if (i & 1)                        // linha ímpar: caminho/muro dir/esq
        for (j = 0; j < nc; ++j)
          if (mat[i][j] == WALL)        // muro
            printf("|");
          else if (mat[i][j] == FAIL)   // tentou ir e nao conseguiu
            if (j & 1) printf("???");   // é caminho
            else       printf(" ");     // inter. linha/coluna
          else if (j & 1)               // é caminho
            if (mat[i][j] > 0) printf("%3d", mat[i][j] / 2 + 1);  // passou por i,j
            else               printf("   ");
          else                          // intersec linha/coluna
            printf(" ");
      else                              // linha par: caminho/muro cima/baixo
        for (j = 0; j < nc; ++j)
          if (j & 1) printf(mat[i][j] == WALL ? "---" : "   ");
          else       printf("+");       // intersec linha/coluna

      printf("\n");
    }

    printf("\n\n");
  }

  return 0;
}
