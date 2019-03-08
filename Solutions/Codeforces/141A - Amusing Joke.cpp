#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  string s, t, u;
  while (cin >> s >> t >> u)
  {
    s += t;
    sort(s.begin(), s.end()), sort(u.begin(), u.end());
    cout << (s == u ? "YES" : "NO") << endl;
  }

  return 0;
}
