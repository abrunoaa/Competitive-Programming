#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  string s;

  cin >> n;
  while (n--)
  {
    cin >> s;
    if (s.length() <= 10) cout << s << endl;
    else cout << s[0] << s.length() - 2 << s.back() << endl;
  }

  return 0;
}
