#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

pair<int, int> a[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].second;
  }
  sort(a, a + n, [](const auto& x, const auto& y) {
    if (x.first != y.first) {
      return x.first < y.first;
    }
    return x.second > y.second;
  });

  // for (auto [x, y] : vector(a, a + n)) {
    // cerr << " -- " << x << ' ' << y << endl;
  // }

  priority_queue<int> q;
  int x = 0;
  long long ans = 0;
  long long sum = 0;
  for (int l = 0, r = 0; l < n; ++l) {
    if (l >= r) {
      r = l + 1;
      x = a[l].first;
      q.push(a[l].second);
      sum = a[l].second;
    }
    for (; r < n && a[r].first == x; ++r) {
      q.push(a[r].second);
      sum += a[r].second;
    }
    // cerr << " >> " << l << ' ' << r << ' ' << sum << ' ' << q.top() << endl;
    sum -= q.top();
    q.pop();
    ans += sum;
    ++x;
  }
  cout << ans << '\n';
  return 0;
}
