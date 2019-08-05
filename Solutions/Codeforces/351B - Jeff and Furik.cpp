#include <bits/stdc++.h>
using namespace std;

#define maxn 3010

int n, p[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  int k = 0;
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < n - i - 1; ++j)
      if (p[j] > p[j + 1]) {
        ++k;
        swap(p[j], p[j + 1]);
      }
  cout << fixed << setprecision(20) << double(4 * (k / 2) + k % 2) << '\n';

  return 0;
}
