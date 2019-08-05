#include <bits/stdc++.h>
using namespace std;

int f(string s) {
  int n = 0;
  for (char c : s) {
    n = 2 * n + (c - '0');
  }
  return n;
}

int main() {
  assert(freopen("ip.in", "r", stdin));

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < 4; ++i) {
      cout << f(s.substr(8 * i, 8));
      if (i < 3) { cout << '.'; }
      else { cout << '\n'; }
    }
  }

  return 0;
}
