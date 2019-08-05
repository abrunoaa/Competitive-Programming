#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

bool hello (const string &s) {
  string t = "olleh";

  for (char c : s)
    if (c == t.back()) {
      t.pop_back();
    }

  return t.empty();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string s;
  while (cin >> s) { cout << (hello(s) ? "YES" : "NO") << endl; }

  return 0;
}
