#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, i, v[110];

  cin >> n;
  if (n % 2 == 0)
    puts("No");
  else
  {
    for (i = 0; i < n; ++i) cin >> v[i];
    if (v[0] % 2 && v[n - 1] % 2)
      puts("Yes");
    else
      puts("No");
  }

  return 0;
}
