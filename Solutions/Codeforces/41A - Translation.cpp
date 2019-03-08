#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  string s, t;
  while (cin >> s >> t)
  {
    reverse(t.begin(), t.end());
    cout << (s == t ? "YES" : "NO") << endl;
  }

  return 0;
}
