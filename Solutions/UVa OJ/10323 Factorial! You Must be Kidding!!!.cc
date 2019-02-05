#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long fat, i, lo, hi, n, ans[100];

  for (i = fat = 1; fat < 10000; fat *= ++i);
  lo = i;
  for (; fat <= 6227020800LL; fat *= ++i) ans[i] = fat;
  hi = i - 1;

  while (scanf("%lld", &n) == 1)
    if (n < 0)
      if (n % 2)      puts("Overflow!");
      else            puts("Underflow!");
    else if (n < lo)  puts("Underflow!");
    else if (n > hi)  puts("Overflow!");
    else              printf("%lld\n", ans[n]);

  return 0;
}
