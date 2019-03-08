#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);

  vector<bool> ans;
  int n;
  string s, p = "abcdefghijklmnopqrstuvwxyz";

  while (cin >> n >> s)
  {
    if (n < 26) goto no;

    ans.assign(26, 0);
    for (char c : s) ans[p.find(tolower(c))] = 1;
    for (bool x : ans) if (!x) goto no;

    cout << "YES\n";
    continue;
    no: cout << "NO\n";
  }

  return 0;
}
