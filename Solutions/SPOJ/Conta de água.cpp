#include <cstdio>

int main() {
  register int n, v;
  scanf("%d", &n);

  v = 7;
  n -= 10;
  if (n > 0) {
    if (n > 20) {
      v += 20;
    } else {
      v += n;
    }
    n -= 20;
  }
  if (n > 0) {
    if (n > 70) {
      v += 140;
    } else {
      v += 2 * n;
    }
    n -= 70;
  }
  if (n > 0) {
    v += 5 * n;
  }

  printf("%d", v);
}
