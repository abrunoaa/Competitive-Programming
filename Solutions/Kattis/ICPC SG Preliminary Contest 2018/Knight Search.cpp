#include <bits/stdc++.h>
using namespace std;

auto square(auto x) {
  return x * x;
}

const int maxn = 103;

int n;
char s[maxn][maxn];
const string t = "ICPCASIASG";

bool ok(int i, int j, int k) {
  return 0 <= i && i < n && 0 <= j && j < n && s[i][j] == t[k];
}

bool f(int i, int j, int k) {
  if (k == (int)t.size()) return 1;
  if (!ok(i, j, k)) return 0;
  for (int a = i - 2; a <= i + 2; ++a) {
    for (int b = j - 2; b <= j + 2; ++b) {
      if (square(i - a) + square(j - b) == 5 && f(a, b, k + 1)) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> s[i][j];
    }
    s[i][n] = 0;
    // cerr << " >> " << s[i] << endl;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (f(i, j, 0)) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
