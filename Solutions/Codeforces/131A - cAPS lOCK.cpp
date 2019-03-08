#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  int i;
  string s;

  while (cin >> s)
  {
    for (i = 1; i < (int)s.length() && isupper(s[i]); ++i);
    if (i == (int)s.length())
      for (char &c : s)
        c ^= 32;

    cout << s << endl;
  }

  return 0;
}
