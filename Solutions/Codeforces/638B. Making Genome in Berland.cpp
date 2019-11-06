#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;

bool used[maxn];
string s[maxn];

string merge(string a, string b) {
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < (int)a.size(); ++i) {
      if (a[i] == b[0]) {
        if (b.size() <= a.size() - i) {
          return a;
        }
        return a + b.substr(a.size() - i);
      }
    }
    swap(a, b);
  }
  assert(0);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  string ans = "";
  for (int i = 0; i < n; ++i) {
    if (ans.empty()) {
      for (int j = 0; j < n; ++j) {
        if (!used[j]) {
          used[j] = 1;
          ans = s[j];
          break;
        }
      }
      continue;
    }
    set<char> f;
    for (char c : ans) {
      f.insert(c);
    }
    bool ok = 0;
    for (int j = 0; j < n; ++j) {
      if (!used[j]) {
        int k;
        for (k = 0; k < (int)s[j].size() && !f.count(s[j][k]); ++k);
        if (k < (int)s[j].size()) {
          ok = 1;
          used[j] = 1;
          ans = merge(ans, s[j]);
          break;
        }
      }
    }
    if (!ok) {
      --i;
      cout << ans;
      ans = "";
    }
  }
  cout << ans << '\n';
  return 0;
}
