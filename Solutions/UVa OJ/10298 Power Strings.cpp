#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int i, j, n, b[1000100];
  string s;

  while (getline(cin, s) && s != ".") {
    n = s.length();

    // kmp pre-process
    b[0] = -1;
    for (i = 0, j = -1; i < n; b[++i] = ++j)
      while (j >= 0 && s[i] != s[j]) {
        j = b[j];
      }
    // \kmp

    if (!j || n % (n - j)) { cout << 1 << endl; }
    else { cout << n / (n - j) << endl; }
  }

  return 0;
}
