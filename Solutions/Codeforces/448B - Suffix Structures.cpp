#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int lcs (string& s, string& t)
{
  int m = s.length(), n = t.length();
  int memo[m + 1][n + 1] = {};

  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      if (s[i - 1] == t[j - 1])
        memo[i][j] = memo[i - 1][j - 1] + 1;
      else
        memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);

  return memo[m][n];
}

int main()
{
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  bool flag;
  string s, t, u;

next_tc:
  while (cin >> s >> t)
  {
    // if (s.length() < t.length())
    // {
      // cout << "need tree\n";
      // goto next_tc;
    // }

    flag = 0;
    if (s.length() > t.length())
    {
      // cerr << lcs(s, t) << endl;
      if (lcs(s, t) == (int)t.length())
      {
        cout << "automaton\n";
        goto next_tc;
      }

      u = t;
      for (int i = s.length(); i--; )
      {
        int p = u.find(s[i]);
        p == -1 ? s.erase(i, 1) : u.erase(p, 1);
      }

      flag = 1;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) cout << (flag ? "both" : "array") << endl;
    else cout << "need tree\n";
  }

  return 0;
}
