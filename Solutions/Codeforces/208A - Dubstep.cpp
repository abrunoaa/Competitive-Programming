#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string s;
  while (cin >> s) {
    for (int p = 0; (p = s.find("WUB", p)) != -1; )
      if (!p || s[p - 1] == ' ') { s.erase(p, 3); }
      else { s.erase(p, 2), s[p] = ' '; }
    while (s.back() == ' ') { s.pop_back(); }
    cout << s << endl;
  }

  return 0;
}
