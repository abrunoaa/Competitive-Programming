#include <cstdio>

int main() {
  register int n, s, d, s1;

  scanf("%d%d", &n, &s);

  while (n > 0) {
    scanf("%d", &d);

    s += d;

    if (s < s1) {
      s1 = s;
    }

    n--;
  }

  printf("%d", s1);
}
