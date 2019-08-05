#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, i, a, b, bb = -1;

  cin >> n >> m;
  cin >> a >> b;
  if (a) { goto no; }
  for (i = 1; i < n; ++i) {
    bb = max(b, bb);
    cin >> a >> b;
    if (a > bb) { goto no; }
  }

  if (max(bb, b) < m) {
    goto no;
  }

  cout << "yes\n";
  return 0;

no:
  cout << "no\n";
  return 0;
}
