#include <cstdio>
#include <cstring>

//#define T

bool mat[105][105];
int w;

void mov(register int x, register int y) {
#ifdef T
  printf(" >> call %d %d \n", x, y);
#endif
  if (!mat[x][y]) {
    w++;
    mat[x][y] = 1;
    mov(x + 1, y);
    mov(x - 1, y);
    mov(x, y + 1);
    mov(x, y - 1);
  }
}

int main() {
  char aux[105];
  int x, y, m;
  register int i, j;
  scanf("%d", &m);
  while (m--) {
    for (i = -1; ++i < 105; )
      for (j = -1; ++j < 105; mat[i][j] = 1);

    scanf("%2d%2d", &x, &y);
    i = 1;
    while (scanf("%*1c%[01]s", aux) > 0) {
      for (j = -1; aux[++j]; mat[i][j + 1] = aux[j] == '1');
      i++;
    }
#ifdef T
    printf("%d %d\n", x, y);
    for (i = 0; i < 15; i++) {
      for (j = 0; j < 15; j++) {
        printf("%d ", mat[i][j] ? 1 : 0);
      }
      printf("\n");
    }
#endif
    w = 0;
    mov(x, y);
    printf("%d%s", w, (m ? "\n\n" : "\n"));
  }

  return 0;
}
