#include <cstdio>

#define MAX 30
//#define T

bool mat[MAX][MAX];
char x[] = { -1, -1,  0,  1,  1,  1,  0, -1 };
char y[] = {  0,  1,  1,  1,  0, -1, -1, -1 };
int n;

void col(register int i, register int j) {
  if (i >= 0 && i < n && j >= 0 && j < n && mat[i][j]) {
    mat[i][j] = 0;
    for (register int k = -1; ++k < 8; col(i + x[k], j + y[k]));
  }
}

int main() {
  register int i, j, count = 0;
  int war;
  char obj;

  while (scanf("%d%*c", &n) != EOF) {
    for (i = -1; ++i < n; scanf("%*c"))
      for (j = -1; ++j < n; ) {
        scanf("%1c", &obj);
        mat[i][j] = obj == '1';
      }
#ifdef T
    for (i = -1; ++i < n; ) {
      for (j = -1; ++j < n; printf("%d ", mat[i][j] ? 1 : 0));
      printf("\n");
    }
#endif
    war = 0;
    for (i = n; i--; )
      for (j = n; j--; )
        if (mat[i][j]) {
          war++;
          col(i, j);
        }
    printf("Image number %d contains %d war eagles.\n", ++count, war);
  }

  return 0;
}
