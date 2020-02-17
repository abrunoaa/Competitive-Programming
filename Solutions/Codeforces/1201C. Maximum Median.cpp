#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

int a[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a[n] = (int)2e9;
  sort(a, a + n);
  int m = n / 2;
  int j = m;
  while (true) {
    for (; a[j] == a[j + 1]; ++j);
    if (k < j - m + 1) {
      break;
    }
    int r = min(k / (j - m + 1), a[j + 1] - a[j]);
    a[j] += r;
    k -= r * (j - m + 1);
  }
  cout << a[j] << '\n';
  return 0;
}
