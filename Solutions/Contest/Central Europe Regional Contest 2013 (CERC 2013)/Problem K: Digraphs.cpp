#include <bits/stdc++.h>
using namespace std;

bool forbidden[30][30];
int memo[40][30];
vector<int> g[30];
string s;

int f(int i, int p) {
  if (i == 39) return 0;
  int &dp = memo[i][p];
  if (dp != -1) return dp;
  dp = 1;
  for (int x : g[p]) {
    dp = max(dp, 1 + f(i + 1, x));
  }
  return dp;
}

void rec(int i, int p) {
  if (i == 39) return;
  s.push_back((char)(p + 'a'));
  int &dp = memo[i][p];
  for (int x : g[p]) {
    if (dp == 1 + f(i + 1, x)) {
      return rec(i + 1, x);
    }
  }
}

int main() {
  // assert(freopen("kin", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(forbidden, 0, sizeof(forbidden));
    for (int i = 0; i < n; ++i) {
      char c1, c2;
      cin >> c1 >> c2;
      forbidden[c1 - 'a'][c2 - 'a'] = 1;
    }
    for (int c = 0; c < 26; ++c) {
      g[c].clear();
      for (int d = 0; d < 26; ++d) {
        if (!forbidden[c][d]) {
          g[c].push_back(d);
        }
      }
    }
    int len = 0;
    memset(memo, -1, sizeof(memo));
    for (int x = 0; x < 26; ++x) {
      len = max(len, f(0, x));
    }
    s.clear();
    for (int x = 0; x < 26; ++x) {
      if (len == f(0, x)) {
        rec(0, x);
        break;
      }
    }
    assert((int)s.size() == len);
    int m = (len + 1) / 2;
    // cerr << " >> " << m << endl;
    for (int i = 0; i < m; ++i) {
      cout << s.substr(i, m) << '\n';
    }
  }
  return 0;
}
