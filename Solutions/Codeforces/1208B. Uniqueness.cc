#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e3 + 3;

int n;
int a[maxn];

int find(set<int> s) {
  int r;
  for (r = n - 1; !s.count(a[r]); --r) {
    s.insert(a[r]);
  }
  return r;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  if ((int)s.size() == n) {
    cout << "0\n";
    return 0;
  }
  int ans = n;
  s.clear();
  bool flag = 1;
  for (int l = 0; flag; ++l) {
    ans = min(ans, find(s) - l + 1);
    flag ^= s.count(a[l]);
    s.insert(a[l]);
  }
  cout << ans << '\n';
  return 0;
}
