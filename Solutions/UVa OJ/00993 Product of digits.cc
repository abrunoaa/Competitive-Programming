#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, i;
  string q;

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);

    if (n <= 1) printf("%d\n", n);
    else
    {
      q.clear();
      for (i = 9; i >= 2; --i)
        while (n % i == 0)
          n /= i, q.push_back(i + 48);
      if (n > 1) q = "-1";

      sort(q.begin(), q.end());
      printf("%s\n", q.data());
    }
  }

  return 0;
}
