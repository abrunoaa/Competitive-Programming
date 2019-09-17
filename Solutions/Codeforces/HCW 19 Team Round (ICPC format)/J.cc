#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  string x;
  cin >> x;
  string tmp = x;
  string y = "-1";
  for (int i = 0; i < (int)x.size(); ++i) {
    for (int j = 0; j < (int)x.size(); ++j) {
      if (i != j) {
        swap(tmp[i], tmp[j]);
        if (tmp[0] != '0' && tmp < x && tmp > y) {
          y = tmp;
        }
        swap(tmp[i], tmp[j]);
      }
    }
  }
  cout << y << '\n';
  return 0;
}
