#include <bits/stdc++.h>
using namespace std;

int freq[10][10];
int need[10][10];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  for (int i = 1; i < (int)s.size(); ++i) {
    ++freq[s[i - 1] - '0'][s[i] - '0'];
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      memset(need, 63, sizeof(need));
      for (int k = 0; k < 10; ++k) {
        for (int a = 0; a < 10; ++a) {
          for (int b = (a == 0); b < 10; ++b) {
            int d = (k + a * i + b * j) % 10;
            need[k][d] = min(need[k][d], a + b - 1);
          }
        }
      }
      int ans = 0;
      for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
          if (freq[a][b] > 0 && need[a][b] == 0x3f3f3f3f) {
            ans = -1;
            goto out;
          }
          ans += freq[a][b] * need[a][b];
        }
      }
     out:
      cout << ans << " \n"[j == 9];
    }
  }
  return 0;
}
