#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  string s;

  while (cin >> s)
  {
    int zero = 0, one = 0;

    for (char c : s)
      if (c == '1')
      {
        zero = 0;
        if (++one == 7) goto dangerous;
      }
      else
      {
        one = 0;
        if (++zero == 7) goto dangerous;
      }

    puts("NO");
    continue;
    dangerous: puts("YES");
  }

  return 0;
}
