#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int n;
int x[maxn], y[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  if (n % 2) {
    cout << "no\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int k = n / 2;
  int x0 = x[0] + x[k];
  int y0 = y[0] + y[k];
  for (int i = 1; i < k; ++i) {
    if (x[i] + x[i + k] != x0 || y[i] + y[i + k] != y0) {
      cout << "no\n";
      return 0;
    }
  }
  cout << "yes\n";
  return 0;
}
