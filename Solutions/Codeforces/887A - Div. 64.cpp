#include <bits/stdc++.h>
using namespace std;

int main() {
  int i;
  string s;

  while (cin >> s) {
    for (i = s.length(); i--; )
      if (s[i] == '1' && s.size() - i <= 6) {
        s.erase(i, 1);
      }
// cerr << s << endl;
    for (i = 0; i < (int)s.size() && s[i] == '0'; ++i);
    if ((int)s.size() - i < 6) { puts("no"); }
    else { puts("yes"); }
  }

  return 0;
}

