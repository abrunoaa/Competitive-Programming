#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int k;
  string s;

again:
  while (cin >> k >> s) {
    bool used[26] = {};
    string ans;
    vector<int> rep(26, 0);

    for (char c : s) { ++rep[c - 97], used[c - 97] = 1; }
    for (int i = 0; i < 26; ++i)
      if (used[i]) {
        if (rep[i] % k) {
          cout << -1 << endl;
          goto again;
        }
        for (int j = rep[i] / k; j--; ans.push_back(i + 97));
      }

    while (k--) { cout << ans; }
    cout << endl;
  }

  return 0;
}
