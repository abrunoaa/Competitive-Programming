#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define endl '\n'

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  string s;
  while (cin >> s) {
    int l = 0, u = 0;

    for (char c : s)
      if (islower(c)) {
        ++l;
      } else {
        ++u;
      }

    if (l >= u)
      for (char &c : s) {
        c = tolower(c);
      } else
      for (char &c : s) {
        c = toupper(c);
      }

    cout << s << endl;
  }

  return 0;
}
