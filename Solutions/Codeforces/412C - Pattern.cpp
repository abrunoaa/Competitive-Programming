#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  char ans[100010];
  string s[100010];

  cin >> n;
  for (int i = 0; i < n; ++i) { cin >> s[i]; }

  memset(ans, -1, sizeof ans);
  for (int j = 0; j < (int)s[0].length(); ++j)
    for (int i = 0; i < n; ++i)
      if (isalpha(s[i][j])) {
        if (ans[j] == -1) {
          ans[j] = s[i][j];
        } else if (ans[j] != s[i][j]) {
          ans[j] = '?';
        }
      }

  for (int i = 0; i < (int)s[0].length(); ++i)
    if (ans[i] < 0) { cout << 'x'; }
    else { cout << ans[i]; }
  cout << endl;

  return 0;
}
