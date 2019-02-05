#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, m;

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &n, &m);
    n -= 2;
    m -= 2;

    printf("%d\n", (n / 3 + (n % 3 ? 1 : 0)) * (m / 3 + (m % 3 ? 1 : 0)));
  }

  return 0;
}





