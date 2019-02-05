#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);

  int ans;
  string s;

  while (cin >> s && s != "0")
  {
    ans = 0;
    for (auto c : s) ans = (ans * 10 + c - 48) % 11;
    if (ans) cout << s << " is not a multiple of 11.\n";
    else cout << s << " is a multiple of 11.\n";
  }

  return 0;
}
