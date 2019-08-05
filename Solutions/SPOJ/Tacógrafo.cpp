#include <cstdio>

int main() {
  register int d = 0, n, t, v;

  scanf("%d", &n);

  while (n > 0) {
    scanf("%d%d", &t, &v);
    d += t * v;
    n--;
  }

  printf("%d", d);
}
