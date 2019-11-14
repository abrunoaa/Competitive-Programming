#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int m = 0;
  vector<int> v[2];
  for (int i = 0; i < n; ++i) {
    int w, c;
    cin >> w >> c;
    m += w;
    v[w - 1].push_back(c);
  }
  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());
  int ans = 0;
  vector<int> small;
  for (int c = 1, used = 0; c <= m; ++c) {
    while (!v[0].empty() && used + 1 <= c) {
      ans += v[0].back();
      small.push_back(v[0].back());
      v[0].pop_back();
      used += 1;
    }
    while (!v[1].empty() && used + 2 <= c) {
      ans += v[1].back();
      v[1].pop_back();
      used += 2;
    }
    if (!v[1].empty() && small.size() >= 2) {
      int a = small[small.size() - 1];
      int b = small[small.size() - 2];
      int diff = v[1].back() - a - b;
      if (diff > 0) {
        ans += diff;
        v[0].push_back(a);
        v[0].push_back(b);
        small.pop_back();
        small.pop_back();
        v[1].pop_back();
      }
    }
    if (c - used == 1 && !v[1].empty() && !small.empty()) {
      int diff = v[1].back() - small.back();
      if (diff > 0) {
        ans += diff;
        v[0].push_back(small.back());
        small.pop_back();
        v[1].pop_back();
        ++used;
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
  return 0;
}
