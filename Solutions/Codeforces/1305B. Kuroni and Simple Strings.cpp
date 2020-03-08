#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  int op = 0;
  stringstream ss;
  while (1) {
    set<int> ans;
    bool ok = 0;
    while (1) {
      int l = 0, r = n - 1;
      for (; l < n && s[l] != '('; ++l);
      for (; r > l && s[r] != ')'; --r);
      if (l >= r) break;
      ok = 1;

      s[l] = s[r] = 'x';
      ans.insert(l);
      ans.insert(r);
    }
    if (!ok) break;
    ss << ans.size() << '\n';
    for (int x : ans) {
      ss << x + 1 << ' ';
    }
    ss << '\n';
    ++op;
  }
  cout << op << '\n' << ss.str() << '\n';
  return 0;
}
