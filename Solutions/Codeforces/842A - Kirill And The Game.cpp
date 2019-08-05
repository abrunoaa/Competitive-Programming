#include <cstdio>

int main() {
  int l, r, x, y, b;
  double k;

  scanf("%d%d%d%d%lf", &l, &r, &x, &y, &k);

  for (b = x; b <= y; ++b)
    if (l <= (k * b) && (k * b) <= r) {
      puts("YES");
      return 0;
    }

  puts("NO");

  return 0;
}
