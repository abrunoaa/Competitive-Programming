#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  int tc, b[1000100];
  string s, t;

  cin >> tc;
  while (tc--)
  {
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());

    int n = s.length();

    // kmp
    b[0] = -1;
    for (int i = 0, j = -1; i < n; b[++i] = ++j)
      while (j >= 0 && s[i] != s[j])
        j = b[j];

    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
      while (j >= 0 && s[j] != t[i]) j = b[j];
      ans = max(ans, ++j);
    }
    // \kmp

    s = s.substr(0, ans);
    reverse(s.begin(), s.end());
    cout << s << endl;
  }

  return 0;
}
