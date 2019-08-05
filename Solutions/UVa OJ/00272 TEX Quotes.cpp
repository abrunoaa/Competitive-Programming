#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in", "r", stdin);

  register int n, f = 1;
  char str[10000];
  string s;

  while (scanf(" %[^\n]", str) > 0) {
    s = str;
    while ((n = s.find('\"')) != -1) {
      if (f) {
        s.erase(n, 1);
        s.insert(n, 2, '`');
        f = 0;
      } else {
        s.erase(n, 1);
        s.insert(n, 2, '\'');
        f = 1;
      }
    }

    printf("%s\n", s.c_str());
  }

  return 0;
}
