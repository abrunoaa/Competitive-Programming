#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int a[maxn], freq[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  map<int,int> mp;
  for (int i = 0, k = 0; i < n; ++i) {
    cin >> a[i];
    int &x = mp[a[i]];
    if (!x) {
      x = ++k;
    }
    a[i] = x;
  }
  int l;
  for (l = 0; l < n && freq[a[l]] == 0; ++l) {
    ++freq[a[l]];
  }
  int ans = n - l;
  for (int r = n - 1; r >= 0; ) {
    while (l > 0 && freq[a[r]] > 0) {
      --l;
      --freq[a[l]];
    }
    if (freq[a[r]] > 0) {
      ans = min(ans, r + 1);
      break;
    }
    for (; r >= 0 && freq[a[r]] == 0; --r) {
      ++freq[a[r]];
    }
    ans = min(ans, r - l + 1);
  }
  cout << ans << '\n';
  return 0;
}
