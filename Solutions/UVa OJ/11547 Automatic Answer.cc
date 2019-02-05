#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  long long n;

  scanf("%d", &t);
  while (t--)
  {
    scanf("%lld", &n);
    n = (315 * n + 36962) / 10 % 10;
    printf("%lld\n", n < 0 ? -n : n);
  }

  return 0;
}





