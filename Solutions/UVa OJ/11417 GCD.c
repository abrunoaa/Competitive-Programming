#include <stdio.h>

int mdc (int a, int b) { return b ? mdc(b, a % b) : a; }

int main()
{
  int n, g, i, j;

  while (scanf("%d", &n) == 1 && n)
  {
    g = 0;
    for (i = 1; i < n; ++i)
      for (j = i + 1; j <= n; ++j)
        g += mdc(i, j);

    printf("%d\n", g);
  }

  return 0;
}
