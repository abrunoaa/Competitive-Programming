#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int x, y;
  cin >> x >> y;

  if (y == 0 || (y == 1 && x > 0) || x < y - 1 || (y - 1) % 2 != x % 2) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }

  return 0;
}
