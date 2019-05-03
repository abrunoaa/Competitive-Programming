#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;

  while (scanf("%d%d", &a, &b) == 2)
  {
    if (!a && !b)
      puts("Not a moose");
    else if (a == b)
      printf("Even %d\n", a + b);
    else
      printf("Odd %d\n", 2 * (max(a, b)));
  }

  return 0;
}
