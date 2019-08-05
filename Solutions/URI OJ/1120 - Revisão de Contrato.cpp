#include <bits/stdc++.h>
using namespace std;

int main() {
  int d;
  string n;
  while (cin >> d >> n && d) {
    string ans;
    for (char c : n) {
      if (c - '0' != d && (c != '0' || !ans.empty())) {
        ans.push_back(c);
      }
    }
    if (ans.empty()) {
      ans = "0";
    }
    cout << ans << '\n';
  }
  return 0;
}
