#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int a[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = (int)(1ll * ans * abs(a[i] - a[j]) % m);
    }
  }
  cout << ans << '\n';
  return 0;
}

