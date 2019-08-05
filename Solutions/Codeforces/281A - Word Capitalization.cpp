#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string s;
  while (cin >> s) { cout << char(toupper(s[0])) << s.data() + 1 << endl; }

  return 0;
}
