#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int h[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  sort(h, h + n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(i + 1 - h[i]);
  }
  cout << ans << '\n';
  return 0;
}
