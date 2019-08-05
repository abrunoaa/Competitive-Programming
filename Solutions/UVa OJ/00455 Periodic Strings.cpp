#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int tc, i, j, b[100];
  string s;

  cin >> tc;
  while (tc--) {
    cin >> s;

    // kmp pre-process
    b[0] = -1;
    for (i = 0, j = -1; i < (int)s.length(); b[++i] = ++j)
      while (j >= 0 && s[i] != s[j]) {
        j = b[j];
      }
    // \kmp

    if (s.length() % (s.length() - j)) { j = 0; }
    cout << s.length() - j << endl;
    if (tc) { cout << endl; }
  }

  return 0;
}
