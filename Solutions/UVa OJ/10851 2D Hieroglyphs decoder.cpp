#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  char s[10][100];
  string str;

  scanf("%d", &t);
  while (t--) {
    scanf(" %*[^\n]");
    for (int i = 0; i < 8; ++i) { scanf(" %[^\n]", s[i]); }
    scanf(" %*[^\n]");

    for (int j = 1; s[0][j + 1]; ++j) {
      char c = 0;
      for (int i = 8; i--;) {
        c = (c << 1) + (s[i][j] == '\\');
      }
      str.push_back(c);
    }

    cout << str << '\n';
    str.clear();
  }

  return 0;
}
