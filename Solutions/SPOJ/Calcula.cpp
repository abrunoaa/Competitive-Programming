#include <cstdio>

int main() {
  register int i;
  int m, aux, s;
  scanf("%d", &m);
  for (i = 1; m != 0; i++) {
    s = 0;
    while (m > 0) {
      scanf("%d", &aux);
      s += aux;
      printf("%d", aux);
      m--;
    }

    printf("Teste %d\n%d\n\n", i, s);
    scanf("%d", &m);
  }
}
