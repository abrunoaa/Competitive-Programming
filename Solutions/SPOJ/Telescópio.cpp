#include <cstdio>

int main() {
  int e = 0;

  register int a, d, n;

  scanf("%d%d", &a, &n);
  while (n > 0) {
    scanf("%d", &d);

    if (a * d >= 40000000) {
      e++;
    }
    n--;
  }

  printf("%d", e);
}
